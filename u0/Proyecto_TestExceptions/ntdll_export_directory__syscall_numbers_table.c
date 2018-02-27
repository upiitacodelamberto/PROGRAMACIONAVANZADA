#include <stdio.h>
#include <Windows.h>

#define IS_ADDRESS_BETWEEN( left, right, address ) ( (address) >= (left) && (address) < (right) )

PIMAGE_SECTION_HEADER SectionByRVA( PIMAGE_SECTION_HEADER pSections, DWORD dwSections, DWORD rva )
{
   PIMAGE_SECTION_HEADER pSectionHeader = pSections;
   DWORD i;
   
   for( i = 0; i < dwSections; i++, pSectionHeader++ )
   {
      // Is the RVA within this section?
      if( IS_ADDRESS_BETWEEN( pSectionHeader->VirtualAddress, ( pSectionHeader->VirtualAddress + pSectionHeader->SizeOfRawData ), rva ) )
         return pSectionHeader;
   }
   return 0;
}

DWORD RawOffsetByRVA( PIMAGE_SECTION_HEADER pSections, DWORD dwSections, DWORD dwFileSize, DWORD rva )
{
	PIMAGE_SECTION_HEADER pSectionHeader;
	DWORD dwOffset, dwDelta;
	pSectionHeader = SectionByRVA( pSections, dwSections, rva );
	if ( !pSectionHeader )
	{
		return 0;
	}
	dwDelta  = rva - pSectionHeader->VirtualAddress;
	dwOffset = pSectionHeader->PointerToRawData + dwDelta;
	if( dwOffset >= dwFileSize )
		return 0;
	else
	{
		return dwOffset;
	}
}

#define GET_POINTER(RVA) ( pBuffer + RawOffsetByRVA( Sections, dwSections, dwFileSize, (RVA) ) )

int main(int argc, char* argv[])
{
	HANDLE hFile = INVALID_HANDLE_VALUE,
		   hMap  = NULL;
	PBYTE pBuffer = NULL, pOps = NULL;
	DWORD dwFileSize = 0,
		  dwSizeOfHeaders = 0,
		  dwSections = 0,
		  dwBaseAddress = 0,
		  dwImageSize = 0,
  	      dwExportRVA  = 0,
		  dwExportSize = 0,
		  dwExportRaw  = 0,
		  dwExports = 0;
	PDWORD pdwFunctions, pszFunctionNames;
	PWORD  pwOrdinals;
	PIMAGE_NT_HEADERS     NTHeader;
	PIMAGE_DOS_HEADER     DOSHeader;
	PIMAGE_SECTION_HEADER Sections;
	PIMAGE_EXPORT_DIRECTORY pExportDirectory;
	hFile = CreateFile
	(
		"c:\\windows\\system32\\ntdll.dll",
		GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_DELETE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);

	if( hFile == INVALID_HANDLE_VALUE )
	{
		fprintf( stderr, "Could not open file: %08X\n", GetLastError() );
		goto done;
	}
	dwFileSize = GetFileSize( hFile, NULL );
	hMap = CreateFileMapping( hFile, NULL, PAGE_READONLY, 0, 0, NULL );
	if( hMap == NULL )
	{
		fprintf( stderr, "Could not create memory map: %08X\n", GetLastError() );
		goto done;
	}

	pBuffer = (PBYTE)MapViewOfFile( hMap, FILE_MAP_READ, 0, 0, 0 );
	if( hMap == NULL )
	{
		fprintf( stderr, "Could not obtain memory map view: %08X\n", GetLastError() );
		goto done;
	}
	if( pBuffer[0] != 'M' || pBuffer[1] != 'Z' )
	{
		fprintf( stderr, "Unexpected file header.\n" );
		goto done;
	}
	// start reading PE headers
	DOSHeader = (PIMAGE_DOS_HEADER)pBuffer;
	NTHeader  = (PIMAGE_NT_HEADERS)( pBuffer + DOSHeader->e_lfanew );

	dwSizeOfHeaders = NTHeader->OptionalHeader.SizeOfHeaders;
	dwBaseAddress   = NTHeader->OptionalHeader.ImageBase;
	dwImageSize     = NTHeader->OptionalHeader.SizeOfImage;
	dwSections      = NTHeader->FileHeader.NumberOfSections;
	// get first section header
	Sections = (PIMAGE_SECTION_HEADER)
	(
		pBuffer +
		DOSHeader->e_lfanew +
		sizeof(IMAGE_NT_HEADERS)
	);
	// now parse the export directory
	dwExportRVA  = NTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	dwExportSize = NTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;
	dwExportRaw  = RawOffsetByRVA( Sections, dwSections, dwFileSize, dwExportRVA );

	if( !dwExportRVA || !dwExportSize || !dwExportRaw )
	{
		fprintf( stderr, "Unexpected export directory structure.\n" );
		goto done;
	}
	pExportDirectory = (PIMAGE_EXPORT_DIRECTORY)( pBuffer + dwExportRaw );
	pdwFunctions     = (PDWORD)GET_POINTER( pExportDirectory->AddressOfFunctions );
	pwOrdinals       = (PWORD)GET_POINTER( pExportDirectory->AddressOfNameOrdinals );
	pszFunctionNames = (PDWORD)GET_POINTER( pExportDirectory->AddressOfNames );
	dwExports		 = pExportDirectory->NumberOfNames;
	printf( "SYSCALL   RVA       NAME\n" );
	printf( "-----------------------------------------------\n" );

	// loop each exported symbol by name
	for( DWORD i = 0; i < pExportDirectory->NumberOfNames; ++i )
	{
		DWORD dwNameRVA = pszFunctionNames[ i ],
			  dwApiRVA  = pdwFunctions[ pwOrdinals[ i ] ],
			  dwSyscall = 0,
			  dwApiRaw  = RawOffsetByRVA( Sections, dwSections, dwFileSize, dwApiRVA ),
			  dwNameRaw = RawOffsetByRVA( Sections, dwSections, dwFileSize, dwNameRVA );
		pOps = pBuffer + dwApiRaw;

		/*
		 * Check if the API entry begins with:
		 *
		 *	MOV  EAX, IMM32
		 *  XOR  ECX, ECX
		 *  LEA  EDX, [ESP+04h]
		 *  CALL FS:[C0h]
		 *
		 * Or
		 *
		 *	MOV  EAX, IMM32
		 *  MOV  ECX, IMM32
		 *  LEA  EDX, [ESP+04h]
		 *  CALL FS:[C0h]
		 */

		if( pOps[0] == 0xB8 &&									            // mov eax, imm32
			(
				(
					pOps[5] == 0x33 && pOps[6] == 0xC9 &&		            // xor ecx, ecx
					!memcmp( &pOps[7],  "\x8D\x54\x24\x04", 4 ) &&          // lea edx, [esp+04h]
					!memcmp( &pOps[11], "\x64\xFF\x15\xC0\x00\x00\x00", 7 ) // call fs:[C0h]
				)
			||
				(
					pOps[5] == 0xB9 &&								        // mov ecx, imm32
					!memcmp( &pOps[10], "\x8D\x54\x24\x04", 4 ) &&          // lea edx, [esp+04h]
					!memcmp( &pOps[13], "\x64\xFF\x15\xC0\x00\x00\x00", 7 ) // call fs:[C0h]
				)
			)
		)
		{
			/*
			 * Extract the IMM32 part, this is our syscall number.
			 */
			dwSyscall  = *(DWORD *)( pOps + 1 );
			printf( "%08X  %08X  %s\n", dwSyscall, dwBaseAddress + dwApiRVA, pBuffer + dwNameRaw );
		}
	}

done:
	if( hFile != INVALID_HANDLE_VALUE )
	{
		CloseHandle( hFile );
	}
	if( pBuffer != NULL )
	{
		UnmapViewOfFile( pBuffer );
	}
	if( hMap != NULL )
	{
		CloseHandle( hMap );
	}
	return 0;
}//end main()

On my Windows 7 computer the output is:

SYSCALL   RVA       NAME
-----------------------------------------------
00000060  7DE90210  NtAcceptConnectPort
00000061  7DE90228  NtAccessCheck
00000026  7DE8FC68  NtAccessCheckAndAuditAlarm
00000062  7DE90240  NtAccessCheckByType
00000056  7DE90114  NtAccessCheckByTypeAndAuditAlarm
00000063  7DE90258  NtAccessCheckByTypeResultList
00000064  7DE90270  NtAccessCheckByTypeResultListAndAuditAlarm
00000065  7DE90288  NtAccessCheckByTypeResultListAndAuditAlarmByHandle
00000066  7DE902A0  NtAddBootEntry
00000067  7DE902B8  NtAddDriverEntry
00000068  7DE902D0  NtAdjustGroupsToken
0000003E  7DE8FEC0  NtAdjustPrivilegesToken
0000006C  7DE9033C  NtAllocateReserveObject
0000006D  7DE90354  NtAllocateUserPhysicalPages
00000015  7DE8FAC0  NtAllocateVirtualMemory
0000006F  7DE90388  NtAlpcAcceptConnectPort
00000070  7DE903A0  NtAlpcCancelMessage
00000071  7DE903B8  NtAlpcConnectPort
00000072  7DE903D0  NtAlpcCreatePort
00000073  7DE903E8  NtAlpcCreatePortSection
00000074  7DE90400  NtAlpcCreateResourceReserve
00000075  7DE90418  NtAlpcCreateSectionView
00000076  7DE90430  NtAlpcCreateSecurityContext
00000077  7DE90448  NtAlpcDeletePortSection
00000078  7DE90460  NtAlpcDeleteResourceReserve
00000079  7DE90478  NtAlpcDeleteSectionView
0000007A  7DE90490  NtAlpcDeleteSecurityContext
0000007B  7DE904A8  NtAlpcDisconnectPort
0000007C  7DE904C0  NtAlpcImpersonateClientOfPort
0000007D  7DE904D8  NtAlpcOpenSenderProcess
0000007E  7DE904F0  NtAlpcOpenSenderThread
0000007F  7DE90508  NtAlpcQueryInformation
00000080  7DE90520  NtAlpcQueryInformationMessage
00000081  7DE90538  NtAlpcRevokeSecurityContext
00000082  7DE90550  NtAlpcSendWaitReceivePort
00000083  7DE90568  NtAlpcSetInformation
00000049  7DE8FFD4  NtApphelpCacheControl
00000002  7DE8F8D8  NtCallbackReturn
0000005A  7DE9017C  NtCancelIoFile
00000086  7DE905B8  NtCancelIoFileEx
00000087  7DE905D0  NtCancelSynchronousIoFile
0000000C  7DE8F9E0  NtClose
00000038  7DE8FE2C  NtCloseObjectAuditAlarm
00000088  7DE905E8  NtCommitComplete
00000089  7DE90600  NtCommitEnlistment
0000008A  7DE90618  NtCommitTransaction
0000008B  7DE90630  NtCompactKeys
0000008C  7DE90648  NtCompareTokens
0000008D  7DE90660  NtCompleteConnectPort
0000008F  7DE90694  NtConnectPort
00000040  7DE8FEF0  NtContinue
00000090  7DE906AC  NtCreateDebugObject
00000091  7DE906C4  NtCreateDirectoryObject
00000092  7DE906DC  NtCreateEnlistment
00000045  7DE8FF74  NtCreateEvent
00000093  7DE906F4  NtCreateEventPair
00000052  7DE900B4  NtCreateFile
00000094  7DE9070C  NtCreateIoCompletion
00000095  7DE90724  NtCreateJobObject
00000096  7DE9073C  NtCreateJobSet
0000001A  7DE8FB40  NtCreateKey
00000097  7DE90754  NtCreateKeyTransacted
00000098  7DE9076C  NtCreateKeyedEvent
00000099  7DE90784  NtCreateMailslotFile
0000009A  7DE9079C  NtCreateMutant
0000009B  7DE907B4  NtCreateNamedPipeFile
0000009C  7DE907CC  NtCreatePagingFile
0000009D  7DE907E4  NtCreatePort
0000009E  7DE907FC  NtCreatePrivateNamespace
0000009F  7DE90814  NtCreateProcess
0000004A  7DE8FFEC  NtCreateProcessEx
000000A0  7DE9082C  NtCreateProfile
000000A1  7DE90844  NtCreateProfileEx
000000A2  7DE9085C  NtCreateResourceManager
00000047  7DE8FFA4  NtCreateSection
000000A3  7DE90874  NtCreateSemaphore
000000A4  7DE9088C  NtCreateSymbolicLinkObject
0000004B  7DE90004  NtCreateThread
000000A5  7DE908A4  NtCreateThreadEx
000000A6  7DE908BC  NtCreateTimer
000000A7  7DE908D4  NtCreateToken
000000A8  7DE908EC  NtCreateTransaction
000000A9  7DE90904  NtCreateTransactionManager
000000AA  7DE9091C  NtCreateUserProcess
000000AB  7DE90934  NtCreateWaitablePort
000000AC  7DE9094C  NtCreateWorkerFactory
000000AE  7DE90980  NtDebugContinue
000000B0  7DE909B4  NtDeleteBootEntry
000000B1  7DE909CC  NtDeleteDriverEntry
000000B2  7DE909E4  NtDeleteFile
000000B3  7DE909FC  NtDeleteKey
000000B4  7DE90A14  NtDeleteObjectAuditAlarm
000000B5  7DE90A2C  NtDeletePrivateNamespace
000000B6  7DE90A44  NtDeleteValueKey
000000B7  7DE90A5C  NtDisableLastKnownGood
000000B8  7DE90A74  NtDisplayString
000000B9  7DE90A8C  NtDrawText
00000039  7DE8FE44  NtDuplicateObject
0000003F  7DE8FED8  NtDuplicateToken
000000BA  7DE90AA4  NtEnableLastKnownGood
000000BB  7DE90ABC  NtEnumerateBootEntries
000000BC  7DE90AD4  NtEnumerateDriverEntries
0000002F  7DE8FD4C  NtEnumerateKey
000000BD  7DE90AEC  NtEnumerateSystemEnvironmentValuesEx
000000BE  7DE90B04  NtEnumerateTransactionObject
00000010  7DE8FA40  NtEnumerateValueKey
000000BF  7DE90B1C  NtExtendSection
000000C0  7DE90B34  NtFilterToken
00000048  7DE8FFBC  NtFlushBuffersFile
000000C1  7DE90B4C  NtFlushInstallUILanguage
000000C4  7DE90B9C  NtFlushProcessWriteBuffers
000000C5  7DE90BB4  NtFlushVirtualMemory
000000C7  7DE90BE8  NtFreeUserPhysicalPages
0000001B  7DE8FB58  NtFreeVirtualMemory
000000C8  7DE90C00  NtFreezeRegistry
000000C9  7DE90C18  NtFreezeTransactions
000000CA  7DE90C30  NtGetContextThread
000000CD  7DE90C80  NtGetMUIRegistryInfo
000000CE  7DE90C98  NtGetNextProcess
000000CF  7DE90CB0  NtGetNextThread
000000D0  7DE90CC8  NtGetNlsSectionPtr
000000D1  7DE90CE0  NtGetNotificationResourceManager
000000D2  7DE90CF8  NtGetPlugPlayEvent
000000D3  7DE90D10  NtGetWriteWatch
000000D5  7DE90D44  NtImpersonateThread
000000D6  7DE90D5C  NtInitializeNlsFiles
000000D7  7DE90D74  NtInitializeRegistry
000000DA  7DE90DC4  NtIsUILanguageComitted
000000DB  7DE90DDC  NtListenPort
000000DC  7DE90DF4  NtLoadDriver
000000DD  7DE90E0C  NtLoadKey
000000DE  7DE90E24  NtLoadKey2
000000DF  7DE90E3C  NtLoadKeyEx
000000E0  7DE90E54  NtLockFile
000000E3  7DE90EA4  NtLockVirtualMemory
000000E6  7DE90EF4  NtMapCMFModule
00000025  7DE8FC50  NtMapViewOfSection
000000E8  7DE90F28  NtModifyBootEntry
000000E9  7DE90F40  NtModifyDriverEntry
000000EA  7DE90F58  NtNotifyChangeDirectoryFile
000000EB  7DE90F70  NtNotifyChangeKey
000000EC  7DE90F88  NtNotifyChangeMultipleKeys
000000ED  7DE90FA0  NtNotifyChangeSession
00000055  7DE900FC  NtOpenDirectoryObject
000000EE  7DE90FB8  NtOpenEnlistment
0000003D  7DE8FEA8  NtOpenEvent
000000EF  7DE90FD0  NtOpenEventPair
00000030  7DE8FD64  NtOpenFile
000000F0  7DE90FE8  NtOpenIoCompletion
000000F1  7DE91000  NtOpenJobObject
0000000F  7DE8FA28  NtOpenKey
000000F2  7DE91018  NtOpenKeyEx
000000F3  7DE91030  NtOpenKeyTransacted
000000F4  7DE91048  NtOpenKeyTransactedEx
000000F5  7DE91060  NtOpenKeyedEvent
000000F6  7DE91078  NtOpenMutant
000000F7  7DE91090  NtOpenObjectAuditAlarm
000000F8  7DE910A8  NtOpenPrivateNamespace
00000023  7DE8FC20  NtOpenProcess
000000F9  7DE910C0  NtOpenProcessToken
0000002D  7DE8FD18  NtOpenProcessTokenEx
000000FA  7DE910D8  NtOpenResourceManager
00000034  7DE8FDC8  NtOpenSection
000000FB  7DE910F0  NtOpenSemaphore
000000FC  7DE91108  NtOpenSession
000000FD  7DE91120  NtOpenSymbolicLinkObject
000000FE  7DE91138  NtOpenThread
00000021  7DE8FBF0  NtOpenThreadToken
0000002C  7DE8FD00  NtOpenThreadTokenEx
000000FF  7DE91150  NtOpenTimer
00000100  7DE91168  NtOpenTransaction
00000101  7DE91180  NtOpenTransactionManager
00000102  7DE91198  NtPlugPlayControl
0000005C  7DE901AC  NtPowerInformation
00000103  7DE911B0  NtPrePrepareComplete
00000104  7DE911C8  NtPrePrepareEnlistment
00000105  7DE911E0  NtPrepareComplete
00000106  7DE911F8  NtPrepareEnlistment
00000108  7DE9122C  NtPrivilegeObjectAuditAlarm
00000109  7DE91244  NtPrivilegedServiceAuditAlarm
0000010A  7DE9125C  NtPropagationComplete
0000010B  7DE91274  NtPropagationFailed
0000004D  7DE90038  NtProtectVirtualMemory
0000003A  7DE8FE5C  NtQueryAttributesFile
0000010D  7DE912A8  NtQueryBootEntryOrder
0000010E  7DE912C0  NtQueryBootOptions
00000032  7DE8FD98  NtQueryDirectoryFile
00000110  7DE912F4  NtQueryDirectoryObject
00000111  7DE9130C  NtQueryDriverEntryOrder
00000112  7DE91324  NtQueryEaFile
00000053  7DE900CC  NtQueryEvent
00000113  7DE9133C  NtQueryFullAttributesFile
00000114  7DE91354  NtQueryInformationAtom
00000115  7DE9136C  NtQueryInformationEnlistment
0000000E  7DE8FA10  NtQueryInformationFile
00000116  7DE91384  NtQueryInformationJobObject
00000117  7DE9139C  NtQueryInformationPort
00000016  7DE8FAD8  NtQueryInformationProcess
00000118  7DE913B4  NtQueryInformationResourceManager
00000022  7DE8FC08  NtQueryInformationThread
0000001E  7DE8FBA8  NtQueryInformationToken
00000119  7DE913CC  NtQueryInformationTransaction
0000011A  7DE913E4  NtQueryInformationTransactionManager
0000011B  7DE913FC  NtQueryInformationWorkerFactory
0000011E  7DE9144C  NtQueryIoCompletion
00000013  7DE8FA90  NtQueryKey
0000011F  7DE91464  NtQueryLicenseValue
00000120  7DE9147C  NtQueryMultipleValueKey
00000121  7DE91494  NtQueryMutant
0000000D  7DE8F9F8  NtQueryObject
00000122  7DE914AC  NtQueryOpenSubKeys
00000123  7DE914C4  NtQueryOpenSubKeysEx
00000125  7DE914F8  NtQueryQuotaInformationFile
0000004E  7DE90050  NtQuerySection
00000126  7DE91510  NtQuerySecurityAttributesToken
00000127  7DE91528  NtQuerySecurityObject
00000128  7DE91540  NtQuerySemaphore
00000129  7DE91558  NtQuerySymbolicLinkObject
0000012A  7DE91570  NtQuerySystemEnvironmentValue
0000012B  7DE91588  NtQuerySystemEnvironmentValueEx
00000033  7DE8FDB0  NtQuerySystemInformation
0000012C  7DE915A0  NtQuerySystemInformationEx
00000035  7DE8FDE0  NtQueryTimer
00000014  7DE8FAA8  NtQueryValueKey
00000020  7DE8FBD8  NtQueryVirtualMemory
00000046  7DE8FF8C  NtQueryVolumeInformationFile
00000042  7DE8FF24  NtQueueApcThread
0000012E  7DE915D4  NtQueueApcThreadEx
0000012F  7DE915EC  NtRaiseException
00000130  7DE91604  NtRaiseHardError
00000131  7DE9161C  NtReadOnlyEnlistment
00000051  7DE9009C  NtReadRequestData
0000003C  7DE8FE90  NtReadVirtualMemory
00000132  7DE91634  NtRecoverEnlistment
00000133  7DE9164C  NtRecoverResourceManager
00000134  7DE91664  NtRecoverTransactionManager
00000135  7DE9167C  NtRegisterProtocolAddressInformation
00000138  7DE916CC  NtReleaseWorkerFactoryWorker
00000139  7DE916E4  NtRemoveIoCompletionEx
0000013B  7DE91718  NtRenameKey
0000013C  7DE91730  NtRenameTransactionManager
0000013D  7DE91748  NtReplaceKey
0000013E  7DE91760  NtReplacePartitionUnit
00000009  7DE8F994  NtReplyPort
00000008  7DE8F97C  NtReplyWaitReceivePort
00000028  7DE8FC98  NtReplyWaitReceivePortEx
0000013F  7DE91778  NtReplyWaitReplyPort
00000140  7DE91790  NtRequestPort
0000001F  7DE8FBC0  NtRequestWaitReplyPort
00000143  7DE917E0  NtRestoreKey
00000145  7DE91814  NtRollbackComplete
00000146  7DE9182C  NtRollbackEnlistment
00000147  7DE91844  NtRollbackTransaction
00000148  7DE9185C  NtRollforwardTransactionManager
00000149  7DE91874  NtSaveKey
0000014A  7DE9188C  NtSaveKeyEx
0000014C  7DE918C0  NtSecureConnectPort
0000014D  7DE918D8  NtSerializeBoot
0000014E  7DE918F0  NtSetBootEntryOrder
0000014F  7DE91908  NtSetBootOptions
00000150  7DE91920  NtSetContextThread
00000155  7DE919A8  NtSetDriverEntryOrder
00000156  7DE919C0  NtSetEaFile
00000159  7DE91A10  NtSetInformationDebugObject
0000015A  7DE91A28  NtSetInformationEnlistment
00000024  7DE8FC38  NtSetInformationFile
0000015B  7DE91A40  NtSetInformationJobObject
0000015C  7DE91A58  NtSetInformationKey
00000059  7DE90164  NtSetInformationObject
00000019  7DE8FB28  NtSetInformationProcess
0000015D  7DE91A70  NtSetInformationResourceManager
0000000A  7DE8F9AC  NtSetInformationThread
0000015E  7DE91A88  NtSetInformationToken
0000015F  7DE91AA0  NtSetInformationTransaction
00000160  7DE91AB8  NtSetInformationTransactionManager
00000161  7DE91AD0  NtSetInformationWorkerFactory
00000163  7DE91B04  NtSetIoCompletion
00000164  7DE91B1C  NtSetIoCompletionEx
00000165  7DE91B34  NtSetLdtEntries
00000168  7DE91B84  NtSetQuotaInformationFile
00000169  7DE91B9C  NtSetSecurityObject
0000016A  7DE91BB4  NtSetSystemEnvironmentValue
0000016B  7DE91BCC  NtSetSystemEnvironmentValueEx
0000016C  7DE91BE4  NtSetSystemInformation
0000016D  7DE91BFC  NtSetSystemPowerState
0000005F  7DE901F8  NtSetTimer
00000170  7DE91C4C  NtSetTimerEx
0000005D  7DE901C4  NtSetValueKey
00000173  7DE91C9C  NtSetVolumeInformationFile
00000175  7DE91CD0  NtShutdownWorkerFactory
00000177  7DE91D04  NtSinglePhaseReject
0000017C  7DE91D8C  NtSystemDebugControl
00000029  7DE8FCB0  NtTerminateProcess
00000050  7DE90084  NtTerminateThread
0000017F  7DE91DDC  NtThawRegistry
00000180  7DE91DF4  NtThawTransactions
00000181  7DE91E0C  NtTraceControl
0000005B  7DE90194  NtTraceEvent
00000183  7DE91E40  NtUmsThreadYield
00000184  7DE91E58  NtUnloadDriver
00000185  7DE91E70  NtUnloadKey
00000186  7DE91E88  NtUnloadKey2
00000187  7DE91EA0  NtUnloadKeyEx
00000188  7DE91EB8  NtUnlockFile
00000189  7DE91ED0  NtUnlockVirtualMemory
00000027  7DE8FC80  NtUnmapViewOfSection
0000018A  7DE91EE8  NtVdmControl
0000018B  7DE91F00  NtWaitForDebugEvent
0000018D  7DE91F34  NtWaitForWorkViaWorkerFactory
00000190  7DE91F84  NtWorkerFactoryWorkerReady
000001A3  7DE9214C  NtWow64CallFunction64
00000194  7DE91FE4  NtWow64CsrAllocateCaptureBuffer
00000196  7DE92014  NtWow64CsrAllocateMessagePointer
00000197  7DE9202C  NtWow64CsrCaptureMessageBuffer
00000198  7DE92044  NtWow64CsrCaptureMessageString
00000193  7DE91FCC  NtWow64CsrClientCallServer
00000191  7DE91F9C  NtWow64CsrClientConnectToServer
00000195  7DE91FFC  NtWow64CsrFreeCaptureBuffer
00000199  7DE9205C  NtWow64CsrGetProcessId
00000192  7DE91FB4  NtWow64CsrIdentifyAlertableThread
0000019A  7DE92074  NtWow64CsrVerifyRegion
0000019B  7DE9208C  NtWow64DebuggerCall
0000019C  7DE920A4  NtWow64GetCurrentProcessorNumberEx
0000019D  7DE920BC  NtWow64GetNativeSystemInformation
0000019E  7DE920D4  NtWow64InterlockedPopEntrySList
0000019F  7DE920EC  NtWow64QueryInformationProcess64
000001A2  7DE92134  NtWow64QueryVirtualMemory64
000001A0  7DE92104  NtWow64ReadVirtualMemory64
000001A1  7DE9211C  NtWow64WriteVirtualMemory64
00000054  7DE900E4  NtWriteRequestData
00000037  7DE8FE14  NtWriteVirtualMemory
0000019D  7DE920BC  RtlGetNativeSystemInformation
00000060  7DE90210  ZwAcceptConnectPort
00000061  7DE90228  ZwAccessCheck
00000026  7DE8FC68  ZwAccessCheckAndAuditAlarm
00000062  7DE90240  ZwAccessCheckByType
00000056  7DE90114  ZwAccessCheckByTypeAndAuditAlarm
00000063  7DE90258  ZwAccessCheckByTypeResultList
00000064  7DE90270  ZwAccessCheckByTypeResultListAndAuditAlarm
00000065  7DE90288  ZwAccessCheckByTypeResultListAndAuditAlarmByHandle
00000066  7DE902A0  ZwAddBootEntry
00000067  7DE902B8  ZwAddDriverEntry
00000068  7DE902D0  ZwAdjustGroupsToken
0000003E  7DE8FEC0  ZwAdjustPrivilegesToken
0000006C  7DE9033C  ZwAllocateReserveObject
0000006D  7DE90354  ZwAllocateUserPhysicalPages
00000015  7DE8FAC0  ZwAllocateVirtualMemory
0000006F  7DE90388  ZwAlpcAcceptConnectPort
00000070  7DE903A0  ZwAlpcCancelMessage
00000071  7DE903B8  ZwAlpcConnectPort
00000072  7DE903D0  ZwAlpcCreatePort
00000073  7DE903E8  ZwAlpcCreatePortSection
00000074  7DE90400  ZwAlpcCreateResourceReserve
00000075  7DE90418  ZwAlpcCreateSectionView
00000076  7DE90430  ZwAlpcCreateSecurityContext
00000077  7DE90448  ZwAlpcDeletePortSection
00000078  7DE90460  ZwAlpcDeleteResourceReserve
00000079  7DE90478  ZwAlpcDeleteSectionView
0000007A  7DE90490  ZwAlpcDeleteSecurityContext
0000007B  7DE904A8  ZwAlpcDisconnectPort
0000007C  7DE904C0  ZwAlpcImpersonateClientOfPort
0000007D  7DE904D8  ZwAlpcOpenSenderProcess
0000007E  7DE904F0  ZwAlpcOpenSenderThread
0000007F  7DE90508  ZwAlpcQueryInformation
00000080  7DE90520  ZwAlpcQueryInformationMessage
00000081  7DE90538  ZwAlpcRevokeSecurityContext
00000081  7DE90538  ZwAlpcRevokeSecurityContext
00000082  7DE90550  ZwAlpcSendWaitReceivePort
00000083  7DE90568  ZwAlpcSetInformation
00000049  7DE8FFD4  ZwApphelpCacheControl
00000002  7DE8F8D8  ZwCallbackReturn
0000005A  7DE9017C  ZwCancelIoFile
00000086  7DE905B8  ZwCancelIoFileEx
00000087  7DE905D0  ZwCancelSynchronousIoFile
0000000C  7DE8F9E0  ZwClose
00000038  7DE8FE2C  ZwCloseObjectAuditAlarm
00000088  7DE905E8  ZwCommitComplete
00000089  7DE90600  ZwCommitEnlistment
0000008A  7DE90618  ZwCommitTransaction
0000008B  7DE90630  ZwCompactKeys
0000008C  7DE90648  ZwCompareTokens
0000008D  7DE90660  ZwCompleteConnectPort
0000008F  7DE90694  ZwConnectPort
00000040  7DE8FEF0  ZwContinue
00000090  7DE906AC  ZwCreateDebugObject
00000091  7DE906C4  ZwCreateDirectoryObject
00000092  7DE906DC  ZwCreateEnlistment
00000045  7DE8FF74  ZwCreateEvent
00000093  7DE906F4  ZwCreateEventPair
00000052  7DE900B4  ZwCreateFile
00000094  7DE9070C  ZwCreateIoCompletion
00000095  7DE90724  ZwCreateJobObject
00000096  7DE9073C  ZwCreateJobSet
0000001A  7DE8FB40  ZwCreateKey
00000097  7DE90754  ZwCreateKeyTransacted
00000098  7DE9076C  ZwCreateKeyedEvent
00000099  7DE90784  ZwCreateMailslotFile
0000009A  7DE9079C  ZwCreateMutant
0000009B  7DE907B4  ZwCreateNamedPipeFile
0000009C  7DE907CC  ZwCreatePagingFile
0000009D  7DE907E4  ZwCreatePort
0000009E  7DE907FC  ZwCreatePrivateNamespace
0000009F  7DE90814  ZwCreateProcess
0000004A  7DE8FFEC  ZwCreateProcessEx
000000A0  7DE9082C  ZwCreateProfile
000000A1  7DE90844  ZwCreateProfileEx
000000A2  7DE9085C  ZwCreateResourceManager
00000047  7DE8FFA4  ZwCreateSection
000000A3  7DE90874  ZwCreateSemaphore
000000A4  7DE9088C  ZwCreateSymbolicLinkObject
0000004B  7DE90004  ZwCreateThread
000000A5  7DE908A4  ZwCreateThreadEx
000000A6  7DE908BC  ZwCreateTimer
000000A7  7DE908D4  ZwCreateToken
000000A8  7DE908EC  ZwCreateTransaction
000000A9  7DE90904  ZwCreateTransactionManager
000000AA  7DE9091C  ZwCreateUserProcess
000000AB  7DE90934  ZwCreateWaitablePort
000000AC  7DE9094C  ZwCreateWorkerFactory
000000AE  7DE90980  ZwDebugContinue
000000B0  7DE909B4  ZwDeleteBootEntry
000000B1  7DE909CC  ZwDeleteDriverEntry
000000B2  7DE909E4  ZwDeleteFile
000000B3  7DE909FC  ZwDeleteKey
000000B4  7DE90A14  ZwDeleteObjectAuditAlarm
000000B5  7DE90A2C  ZwDeletePrivateNamespace
000000B6  7DE90A44  ZwDeleteValueKey
000000B7  7DE90A5C  ZwDisableLastKnownGood
000000B8  7DE90A74  ZwDisplayString
000000B9  7DE90A8C  ZwDrawText
00000039  7DE8FE44  ZwDuplicateObject
0000003F  7DE8FED8  ZwDuplicateToken
000000BA  7DE90AA4  ZwEnableLastKnownGood
000000BB  7DE90ABC  ZwEnumerateBootEntries
000000BC  7DE90AD4  ZwEnumerateDriverEntries
0000002F  7DE8FD4C  ZwEnumerateKey
000000BD  7DE90AEC  ZwEnumerateSystemEnvironmentValuesEx
000000BE  7DE90B04  ZwEnumerateTransactionObject
00000010  7DE8FA40  ZwEnumerateValueKey
000000BF  7DE90B1C  ZwExtendSection
000000C0  7DE90B34  ZwFilterToken
00000048  7DE8FFBC  ZwFlushBuffersFile
000000C1  7DE90B4C  ZwFlushInstallUILanguage
000000C4  7DE90B9C  ZwFlushProcessWriteBuffers
000000C5  7DE90BB4  ZwFlushVirtualMemory
000000C7  7DE90BE8  ZwFreeUserPhysicalPages
0000001B  7DE8FB58  ZwFreeVirtualMemory
000000C8  7DE90C00  ZwFreezeRegistry
000000C9  7DE90C18  ZwFreezeTransactions
000000CA  7DE90C30  ZwGetContextThread
000000CD  7DE90C80  ZwGetMUIRegistryInfo
000000CE  7DE90C98  ZwGetNextProcess
000000CF  7DE90CB0  ZwGetNextThread
000000D0  7DE90CC8  ZwGetNlsSectionPtr
000000D1  7DE90CE0  ZwGetNotificationResourceManager
000000D2  7DE90CF8  ZwGetPlugPlayEvent
000000D3  7DE90D10  ZwGetWriteWatch
000000D5  7DE90D44  ZwImpersonateThread
000000D6  7DE90D5C  ZwInitializeNlsFiles
000000D7  7DE90D74  ZwInitializeRegistry
000000DA  7DE90DC4  ZwIsUILanguageComitted
000000DB  7DE90DDC  ZwListenPort
000000DC  7DE90DF4  ZwLoadDriver
000000DD  7DE90E0C  ZwLoadKey
000000DE  7DE90E24  ZwLoadKey2
000000DF  7DE90E3C  ZwLoadKeyEx
000000E0  7DE90E54  ZwLockFile
000000E3  7DE90EA4  ZwLockVirtualMemory
000000E6  7DE90EF4  ZwMapCMFModule
00000025  7DE8FC50  ZwMapViewOfSection
000000E8  7DE90F28  ZwModifyBootEntry
000000E9  7DE90F40  ZwModifyDriverEntry
000000EA  7DE90F58  ZwNotifyChangeDirectoryFile
000000EB  7DE90F70  ZwNotifyChangeKey
000000EC  7DE90F88  ZwNotifyChangeMultipleKeys
000000ED  7DE90FA0  ZwNotifyChangeSession
00000055  7DE900FC  ZwOpenDirectoryObject
000000EE  7DE90FB8  ZwOpenEnlistment
0000003D  7DE8FEA8  ZwOpenEvent
000000EF  7DE90FD0  ZwOpenEventPair
00000030  7DE8FD64  ZwOpenFile
000000F0  7DE90FE8  ZwOpenIoCompletion
000000F1  7DE91000  ZwOpenJobObject
0000000F  7DE8FA28  ZwOpenKey
000000F2  7DE91018  ZwOpenKeyEx
000000F3  7DE91030  ZwOpenKeyTransacted
000000F4  7DE91048  ZwOpenKeyTransactedEx
000000F5  7DE91060  ZwOpenKeyedEvent
000000F6  7DE91078  ZwOpenMutant
000000F7  7DE91090  ZwOpenObjectAuditAlarm
000000F8  7DE910A8  ZwOpenPrivateNamespace
00000023  7DE8FC20  ZwOpenProcess
000000F9  7DE910C0  ZwOpenProcessToken
0000002D  7DE8FD18  ZwOpenProcessTokenEx
000000FA  7DE910D8  ZwOpenResourceManager
00000034  7DE8FDC8  ZwOpenSection
000000FB  7DE910F0  ZwOpenSemaphore
000000FC  7DE91108  ZwOpenSession
000000FD  7DE91120  ZwOpenSymbolicLinkObject
000000FE  7DE91138  ZwOpenThread
00000021  7DE8FBF0  ZwOpenThreadToken
0000002C  7DE8FD00  ZwOpenThreadTokenEx
000000FF  7DE91150  ZwOpenTimer
00000100  7DE91168  ZwOpenTransaction
00000101  7DE91180  ZwOpenTransactionManager
00000102  7DE91198  ZwPlugPlayControl
0000005C  7DE901AC  ZwPowerInformation
00000103  7DE911B0  ZwPrePrepareComplete
00000104  7DE911C8  ZwPrePrepareEnlistment
00000105  7DE911E0  ZwPrepareComplete
00000106  7DE911F8  ZwPrepareEnlistment
00000108  7DE9122C  ZwPrivilegeObjectAuditAlarm
00000109  7DE91244  ZwPrivilegedServiceAuditAlarm
0000010A  7DE9125C  ZwPropagationComplete
0000010B  7DE91274  ZwPropagationFailed
0000004D  7DE90038  ZwProtectVirtualMemory
0000003A  7DE8FE5C  ZwQueryAttributesFile
Enjoy :)
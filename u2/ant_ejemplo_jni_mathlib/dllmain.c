/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include "ejemusodmathlib_UsoDMathlib.h"
#include <windows.h>

DLLIMPORT void HelloWorld()
{
	MessageBox(0,"Hello World from DLL!\n","Hi",MB_ICONINFORMATION);
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}

JNIEXPORT jint JNICALL Java_ejemusodmathlib_UsoDMathlib_addTwoNumbers
  (JNIEnv *env, jobject obj, jint arg1, jint arg2){
  	return arg1+arg2;
  }

JNIEXPORT jint JNICALL Java_ejemusodmathlib_UsoDMathlib_multiplyTwoNumbers
  (JNIEnv *env, jobject obj, jint arg1, jint arg2){
  	return arg1*arg2;
  }




















  
  
  
  
  
  
  
  
  
  

/**
 * bibliotecastring.c Archivo de implementacion de la biblioteca
 * BibliotecaString
 */
#include <string.h>
#include "u4_jni00_EjemploString.h"

JNIEXPORT jstring JNICALL Java_u4_jni00_EjemploString_replaceString
  (JNIEnv *env, jobject obj, 
  jstring _srcString, jstring _strToReplace, jstring _replString){
  const char *searchStr, *findStr, *replStr, *found;
  jstring newString=NULL;
  int index;

  searchStr=env->GetStringUTFChars(_srcString, NULL);
  findStr=env->GetStringUTFChars(_strToReplace, NULL);
  replStr=env->GetStringUTFChars(_replString, NULL);

  found=strstr(searchStr, findStr);

  if(found!=NULL){
    char *newStringTemp;
    index=found-searchStr;
    newStringTemp=new char[strlen(searchStr)+strlen(replStr)+1];
    strcpy(newStringTemp, searchStr);
    newStringTemp[index]=0;
    strcat(newStringTemp, replStr);
    strcat(newStringTemp, &searchStr[index+strlen(findStr)]);
    newString=env->NewStringUTF((const char*)newStringTemp);
  }
  env->ReleaseStringUTFChars(_srcString, searchStr);
  env->ReleaseStringUTFChars(_strToReplace, findStr);
  env->ReleaseStringUTFChars(_replString, replStr);

  return (newString);
}

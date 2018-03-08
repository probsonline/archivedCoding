#include <stdio.h>
#include "testDLLCall.h"

JNIEXPORT void JNICALL Java_testDLLCall_cPrintf
  (JNIEnv *a, jobject b)
{
    printf("I am in C now\n");
}


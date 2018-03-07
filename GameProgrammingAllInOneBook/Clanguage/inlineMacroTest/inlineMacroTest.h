
#include <windows.h>
#include <stdio.h>

#define   USE_MACRO	0

#if		 (!USE_MACRO)

int myRoutine(int x, int y);

#else


#define myRoutine(x, y);		\

0


#endif





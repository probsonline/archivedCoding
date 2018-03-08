#include <stdio.h>

#define    USE_MACRO    0

#if        (!USE_MACRO)

int myRoutine(int x, int y);

#else

#define  myRoutine(x, y); \

         (x>y)? x+y : -1;

#endif


int main(int argc, char *argv[])
{
	int result;
	printf("Starting the test\n");

	result = myRoutine(5, 7);

	printf("Result: %d\n", result);
    getch();
    return 0;
}



int myRoutine(int x, int y)
{
	int status;
	if(x>y)
	status = (x+y);
	else
		status = -1;

	return status;
}


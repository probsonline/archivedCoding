#include <stdio.h>

#define    USE_MACRO    1

#if        (!USE_MACRO)

int myRoutine(int x, int y);

#else

#define  myRoutine(x, y)          \
(x>y) ? if(x<y)(x+y) : -1

#endif


int main(int argc, char *argv[])
{
	int result, x, y;
	printf("Starting the programme\n");

	printf("Performing test 1\n");	
	x=5; 
    y=7;
	printf("x: %d \t y: %d\n", x, y);
	//myRoutine(x, y);
	result = myRoutine(x, y);
	printf("Result: %d\n", result);


	printf("Performing test 2\n");	
	x=7; 
    y=5;
	printf("x: %d \t y: %d\n", x, y);
	//myRoutine(x, y);
	result = myRoutine(x, y);	
	printf("Result: %d\n", result);



    getch();
    return 0;
}


#if        (!USE_MACRO)
int myRoutine(int x, int y)
{
	int status;
	if(x>y)
	status = (x+y);
	else
		status = -1;

	return status;
}
#endif

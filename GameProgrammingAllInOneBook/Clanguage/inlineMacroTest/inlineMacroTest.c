#include "inlineMacroTest.h"


int myRoutine(int x, int y)
{
	int status;
	if(x>y)
	status = (x+y);
	else
		status = -1;

	return status;
}



//int main(int argc, char *argv[])
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	int result;
	printf("Starting the test\n");

	result = myRoutine(5, 7);

	printf("Result: %d\n", result);

	return 0;
}
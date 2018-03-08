#include <stdio.h>

void my_test_func1(int a);
#define abc my_test_func1
void my_test_func1(int a);

int main( int argc, char *argv[] )
{
    printf( "Hello World!\n" );
    my_test_func1(10);
	abc(100);
    return 0;
}

void my_test_func1(int a)
{
   printf("%u\n", a);
}
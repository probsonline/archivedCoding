#include <stdio.h>

unsigned long ggg;

int main( int argc, char *argv[] )
{
    unsigned long *abc;
    
    abc = &ggg;
    printf( "Hello World!\n" );
    printf("%u\n", abc);
    abc = abc+1;
    printf("%u\n", abc);
    abc = abc+2;
    printf("%u\n", abc);
    
    return 0;
}

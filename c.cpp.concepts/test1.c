#include <stdio.h>

/* Error interrupt request for Tx/Rx error. */
#define     CT_ERRINT           0x0002

/* Busoff interrupt request. */
#define     CT_BOFFINT          0x0004

#define     NU_FALSE    0

int main( int argc, char *argv[] )
{
    int i;
    unsigned short intreg, value;

    value = 0x0;

    for(i=0; i<16; i++)
    {
        intreg = value & (CT_BOFFINT | CT_ERRINT);
        if(intreg != NU_FALSE)
        {
            printf("value=%x\t intreg=%x\t", value, intreg);
            printf( "inside if statement!\n" );
        }
        else
        {
            printf("value=%x\t intreg=%x\t", value, intreg);
            printf( "not in if statement!\n" );
        }

        value++;
    }



    return 0;
}

#include <stdio.h>

//#define MAT_11
//#define MAT_22


#if (defined(MAT_22)) || (defined(MAT_11))

void main()
{
    printf("Mat 1 Test \n");
}

#else

void main()
{

    printf("XXXXXXXXXXXXXXXx");
}

#endif


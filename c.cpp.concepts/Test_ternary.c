#include <stdio.h>

#define     CT_IPSBAR_DEFAULT_VALUE     0x40000001 

/* Mask for checking if offset of 1GB IPS-memory is valid. */
#define     CT_IPSBAR_VALID_MASK            0x00000001

/* Mask for getting the offest of 1GB memory associated with IPS 
   (On-chip/Internal Peripheral System). */
#define     CT_IPSBAR_IPS_MEM_OFFSET_MASK   0xC0000000

#define     CT_GET_IPS_OFFSET                   \
            ((CT_IPSBAR_DEFAULT_VALUE & CT_IPSBAR_VALID_MASK)  \
                                ? (CT_IPSBAR_DEFAULT_VALUE &  \
                                   CT_IPSBAR_IPS_MEM_OFFSET_MASK)        \
                                : 0 )


void main()
{
    unsigned long  a, b;

    a= 3;

/*
    if (b = ((a>2) ? 3:5))
    {
        printf("%d = \n", b);
    }
*/
    printf("%x = \n", CT_GET_IPS_OFFSET);

    if (CT_GET_IPS_OFFSET) 
    {
        printf("%x = \n", CT_GET_IPS_OFFSET);

        printf("%x = \n", a);
        
        a = a + CT_GET_IPS_OFFSET;

        printf("%x = \n", a);

    }



}



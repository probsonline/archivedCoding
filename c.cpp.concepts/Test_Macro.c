#include <stdio.h>

#define     NU_System_Clock_Frequency   66000000/2
#define     CT_PDR_VALUE_1MBAUD         0x01
//#if         CT_PRESCALER_VALUE_VALID(1000000, CT_PDR_VALUE_1MBAUD)
//#error      
//#else
//#error
//#endif
/*
#define     CT_PRESCALER_VALUE_VALID(baud, pval)                                \
            if((((NU_System_Clock_Frequency/(2*(pval+1)))/baud) < 10)          \
            1\
            else\
                0\
            #error  "Prescaler's valus is not valid. Decrease Prescaler value. "\
            #else                                                               \
            #if(((NU_System_Clock_Frequency/(2*(pval+1)))/baud) > 24))          \
            #error  "Prescaler's valus is not valid. Increase Prescaler value. "\
            #endif
*/

#define     CT_PRESCALER_VALUE_VALID(baud, pval)                                \
            (((((NU_System_Clock_Frequency/(2*(pval+1)))/baud) < 10) ?   \
             ("Prescaler's valus is not valid. Decrease Prescaler value. ";) : \
            ((((NU_System_Clock_Frequency/(2*(pval+1)))/baud) > 24) ?   \
             ("Prescaler's valus is not valid. Decrease Prescaler value. ";) : 0))
/*
#define     CT_PRESCALER_VALUE_VALID(baud, pval)                                \
            if( ((NU_System_Clock_Frequency/(2*(pval+1)))/baud) <10 )            \
                "Prescaler's valus is not valid. Decrease Prescaler value. ";  \
            else if( ((NU_System_Clock_Frequency/(2*(pval+1)))/baud) <10)            \
             "Prescaler's valus is not valid. Increase Prescaler value. ";   \
            else    \
                0;

*/

/*
#define     CT_PRESCALER_VALUE_VALID(baud, pval)                                \
            #if((((NU_System_Clock_Frequency/(2*(pval+1)))/baud) < 10)          \
            #error  "Prescaler's valus is not valid. Decrease Prescaler value. "\
            #else                                                               \
            #if(((NU_System_Clock_Frequency/(2*(pval+1)))/baud) > 24))          \
            #error  "Prescaler's valus is not valid. Increase Prescaler value. "\
            #endif
*/
void main()
{
    char *a;
    CT_PRESCALER_VALUE_VALID(1000000, CT_PDR_VALUE_1MBAUD)
    printf("Mat 1 Test \n");
    printf("Mat 1 Test \n");
}





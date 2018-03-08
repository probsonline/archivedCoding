#include <stdio.h>

int main(int *argc, int argv)
{
    char c_in='\n';
    int lo_limt, hi_limt, sum;
    printf("Starting the program\n");
    
    while(c_in != 'q')
    {
        printf("\n Enter the lower limit of the range.\n");
        scanf("%d", &lo_limt);
        printf("\n Enter the upper limit of the range.\n");
        scanf("%d", &hi_limt);
    
        printf("Calculating the sum ....\n\n");
    
        sum = (hi_limt - lo_limt)*(hi_limt + lo_limt-1)/2+hi_limt;
        printf("Sum calculated. It is:\t%d\n", sum);
        
        printf("\n Press q to quit program or anything else to continue.\n");
        scanf("%c", &c_in);        
    }

    getch();
    return 0;
}

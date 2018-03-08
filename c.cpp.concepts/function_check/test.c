#include <stdio.h>
#include "func.h"

void main()
{
    UINT16 ans;
    printf("starting...................\n");
    printf("calling mul...................\n");
    ans = mul(3,4);
    printf("%u\n", ans);
    printf("calling mul2...................\n");
    ans = mul(3);
    printf("%u\n", ans);
    printf("Finishing...................\n");
}
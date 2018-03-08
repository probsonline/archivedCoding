#include <stdio.h>

typedef struct First_str
{
    struct Second  *sec;
}First;

typedef struct Second_str
{
    First  *first;

}Second;

int main()
{
    printf("hi");
}
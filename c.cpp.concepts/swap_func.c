#include <stdio.h>

//#defined FUNC_PTR   (void (*CALLBACKFN1)(void))
typedef void  (*CALLBACKFN)(void);

void func1();
void func2();
void SwapFunctions(void (*CALLBACKFN1)(void), void (*CALLBACKFN2)(void));
void SwapFunctions3(void *(void (*CALLBACKFN1)(void)), void *(void (*CALLBACKFN2)(void)));
void SwapFunctions2(CALLBACKFN *f1, CALLBACKFN *f2);
//void SwapFunctions(void*, void*);

int main( int argc, char *argv[] )
{
    printf( "Hello World!\n" );
    func1();
    func2();
    SwapFunctions(func1, func2);
    func1();
    func2();
    SwapFunctions2(&func1, &func2);
    func1();
    func2();

    return 0;
}
//void SwapFunctions3(void *(void (*CALLBACKFN1)(void)), void *(void (*CALLBACKFN2)(void)))
//{
//}

void SwapFunctions2(CALLBACKFN *f1, CALLBACKFN *f2)
{
    CALLBACKFN *temp;
    temp = f2;
    //(*f1);
    f2 = f1;
    f1 = temp;
}
void SwapFunctions(void (*CALLBACKFN1)(void), void (*CALLBACKFN2)(void))
{
    void *temp;
    temp = CALLBACKFN1;
    CALLBACKFN1=CALLBACKFN2;
    CALLBACKFN2=temp;
//    (*CALLBACKFN1)();
//    (*CALLBACKFN2)();
}

void func1()
{
    printf("in function 1\n");
}
void func2()
{
    printf("In function 2\n");
}
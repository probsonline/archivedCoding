// This is the main project file for VC++ application project 
// generated using an Application Wizard.

#include "stdafx.h"

#using <mscorlib.dll>
#include <tchar.h>
#include <conio.h>
#include<iostream.h>
using namespace System;

// This is the entry point for this application
class Book{
   public : int x,y,z;
		 //virtual void m();
};
class JavaBook : public Book{
   public : int a,b,c;
};
int fido(int m);
int _tmain(void)
{
	Book *bp = new JavaBook();
	JavaBook *jbp = new JavaBook();// = dynamic_cast<JavaBook*>(bp);
    jbp = dynamic_cast<JavaBook*>(bp);
	Console::WriteLine(jbp->b);
	//cout<<p->x;
    // TODO: Please replace the sample code below with your own.
	int x = 5;
	x = x << 1;
	
	Console::WriteLine(x);
	int *p = & x;
	int s1 = sizeof(p);

    Console::WriteLine(s1);
	Book *p2 = new Book();
    int s2 = sizeof(p2);
    Console::WriteLine(s2);

    Console::WriteLine(S"Hello World");
	
	int f = fido(3);
	Console::WriteLine(f);
	getche();
    return 0;
}
int fido(int m){
	if( m == 0 )return 1;
	return m * fido(m-1);
}

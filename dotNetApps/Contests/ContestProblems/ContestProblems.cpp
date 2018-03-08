// ContestProblems.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FewestFactors.h"

int _tmain(int argc, _TCHAR* argv[])
{

	printf("IN the name of Allah, I start");

	//Example 1 {1,2}
	int digit[] = {1,2,3};

	FewestFactors factors;
	factors.number(digit);

	//Hack to stop
	getchar();

	return 0;
}


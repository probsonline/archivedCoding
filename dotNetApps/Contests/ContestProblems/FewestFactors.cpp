#include "stdafx.h"
#include "FewestFactors.h"

using namespace std;

FewestFactors::FewestFactors(){}

FewestFactors::~FewestFactors(){}

//max 5 elements in array. Each element is a single digit
//use each element once (not less not more i.e. digit duplication may occur)
//Temp: assume two digits
int FewestFactors::number(int digits[])
{
	int num;

	//calculate number possible results. It is array_length!
	//num = calcArraySize(digits);
	num = MAX_DIGITS;

	//Synthesize number
	int *possibleIntegers = synthesizeNumbers(digits, num);

	//Search for prime numbers from synthesized numbers. 
	//Check if more than one prime found. Return the smallest

	//else, no prime found.
	//calculate factors

	return num;

}


int FewestFactors::calcFactorial(int n)
{
	int fact=1;
	for (int i=2; i<=n; i++)
	{
		fact = fact * i;
	}

	debugPrint("Possible Solutions", fact);

	return fact;
}


int* FewestFactors::synthesizeNumbers(int *digits, int elementCount)
{
	int possibleSolCount  = calcFactorial(elementCount);
	int *possibleIntegers = new int[possibleSolCount];	//Allocate array memory.

	return possibleIntegers;
}

void FewestFactors::debugPrint(string s, int n)
{
	cout << "\n" << s << ":\t";
	cout << n << endl;
}

//Copied from: http://www.daniweb.com/forums/thread17212.html
//template <typename T, int sz>
//char (&calcArraySize(T(&)[sz]))[sz];

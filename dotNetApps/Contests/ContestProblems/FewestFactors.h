#include "stdafx.h"
#include <string>

class FewestFactors
{
public:
	FewestFactors();
	~FewestFactors();

	int number(int digits[]);

protected:

private:
	static const int MAX_DIGITS = 2;

	int calcFactorial(int n);
	int* synthesizeNumbers(int *digits, int elementCount);
	void debugPrint(string s, int n);

};


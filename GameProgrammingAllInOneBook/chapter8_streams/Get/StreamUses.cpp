#include <iostream>

int main(int argc, char* srgv)
{
	char typedLetter;

	std::cout << "Press q to quit ...";

	/* Wait untill user pressed q or Q. */
	do
	{
		typedLetter = std::cin.get();
	}while((typedLetter != 'q') || (typedLetter != 'Q'));

	return 0;
}
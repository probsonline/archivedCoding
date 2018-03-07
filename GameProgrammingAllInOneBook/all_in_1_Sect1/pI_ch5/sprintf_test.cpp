#include <iostream>

int main()
{
	char info[255];

	sprintf(info, "My wife's name is %s, her height is %d inches and her current weight is %d kg", "Msrt", 64, 57);

	std::cout << info << std::endl;
	
	return 0;
}

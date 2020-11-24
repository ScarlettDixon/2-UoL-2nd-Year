//Array1.cpp
#include <iostream>

int main()
{
	int myArray[9];
	myArray[0] = 3;


	char charArray[] = { 'a', 'b', 'c' };
	char* ptr = charArray;

	//determine its size
	std::cout << (sizeof(myArray) / sizeof(myArray[0])) << std::endl;
	//or
	std::cout << (sizeof(myArray) / sizeof(*myArray)) << std::endl;

	std::cout << (sizeof(charArray) / sizeof(*charArray)) << std::endl;

	std::cout << charArray[0] << std::endl;

	//output charArray contents
	for (int x = 0; x < (sizeof(charArray) / sizeof(*charArray)); x++)
	{
		std::cout << charArray[x] << " ";
		

	}
	std::cout << std::endl;

}

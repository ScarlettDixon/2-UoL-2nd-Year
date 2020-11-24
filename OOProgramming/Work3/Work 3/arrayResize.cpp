//arrayResize.cpp
#include <iostream>

int main()
{
	char arrOld[] = { 'a', 'b', 'c' };
	char* ptr = arrOld;

	std::cout << "Size of old array: " << (sizeof(arrOld) / sizeof(arrOld[0])) << std::endl;

	//resize the old array to a new array size
	char newArr[6];
	//copy the old array contents to the new one
	for (int x = 0; x < (sizeof(arrOld) / sizeof(arrOld[0])); x++)
	{
			newArr[x] = arrOld[x];
	}

	//using pointers
	/*for (int x = 0; x < (sizeof(ptr) / sizeof(*ptr)); x++)
	{
		newArr[x] = *ptr;
		ptr++;
	}*/


	newArr[3] = 'q';
	newArr[4] = 'w';

	//output contents of newArr
	for (int y = 0; y < (sizeof(newArr) / sizeof(newArr[0])); y++)
	{
		std::cout << newArr[y] << " ";
	}
	std::cout << std::endl;
	std::cout << "Size of new array: " << (sizeof(newArr) / sizeof(newArr[0])) << std::endl;
	
	
	return 0;
}
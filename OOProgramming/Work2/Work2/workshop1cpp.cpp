#include <iostream>

void outputArray(char[], int size);

int main()
{
	char c;
	char arr[10];
	char* arrPtr;
	arrPtr = arr;

	std::cout << "Enter some text" << std::endl;

	for(int x = 0; x < 10; x++)
	{
		std::cin.get(c);
		*arrPtr = c;
		arrPtr++;
	}

	outputArray(arr, 10);

	return 0;
}

void outputArray(char a[], int size)
{
	char* ptr;
	ptr = &a[size - 1];
	for (int x = 0; x < 10; x++)
	{
		std::cout << *ptr << " ";
		ptr--;
	}
	std::cout << std::endl;
}
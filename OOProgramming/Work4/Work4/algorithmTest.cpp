//algorithmTest.cpp
#include <algorithm>
#include <vector>
#include <iostream>

void mult(int x);

int main()
{
	std::vector<int> vec = { 3, 4, 6, 3, 2, 6, 8, 6, 4, 6, 8, 9 };
	std::vector<int>::iterator it;

	/*int result = std::count(vec.begin(), vec.end(), 6);

	std::cout << result << std::endl;*/
	//********************************************************

	/*std::sort(vec.begin(), vec.end());
	std::cout << "Sorted vector: ";
	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;*/
	//********************************************************

	std::cout << "for_each: ";
	std::for_each(vec.begin(), vec.end(), mult);
	std::cout << std::endl;

	return 0;
}

void mult(int x)
{
	std::cout << x * 2 << " ";
}
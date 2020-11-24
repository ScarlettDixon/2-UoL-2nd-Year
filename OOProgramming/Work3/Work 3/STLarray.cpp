//STLarray.cpp
#include <iostream>
#include <array>

int main()
{
	std::array<int, 5> mySTLarray = { 1, 2, 3, 4, 5 };

	/*for (int x = 0; x < mySTLarray.size(); x++)
	{
		mySTLarray[x] = x;
	}*/

	std::cout << mySTLarray.size() << std::endl;

	//using at() instead of the [] operator
	std::cout << mySTLarray[2] << std::endl;
	std::cout << mySTLarray.at(2) << std::endl;


	//output the contents of STL array
	for (int y = 0; y < mySTLarray.size(); y++)
	{
		std::cout << mySTLarray[y] << " ";
	}
	std::cout << std::endl;



	return 0;
}
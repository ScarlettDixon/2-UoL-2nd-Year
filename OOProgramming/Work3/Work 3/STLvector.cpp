//STLvector.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> mySTLvector;
	std::vector<int>::iterator it;

	for (int x = 0; x < 5; x++)
	{
		mySTLvector.push_back(x);
	}

	for (int y = 0; y < mySTLvector.size(); y++)
	{
		std::cout << mySTLvector.at(y) << " ";
	}
	std::cout<<std::endl;

	//insert automatically adds element to vector and resizes it
	mySTLvector.insert(mySTLvector.end(), 9);

	it = mySTLvector.begin();
	//insert value 8 into vector at element 3 - using iterator 
	mySTLvector.insert(it + 3, 8);

	//reset iterator to begining of vector
	it = mySTLvector.begin();


	for (std::vector<int>::iterator it = mySTLvector.begin(); it != mySTLvector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}
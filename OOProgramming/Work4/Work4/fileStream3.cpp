//fileStream3.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
	std::ifstream file;
	std::string temp;
	std::string myString[10];

	int x = 0;

	//open the file for reading and writing
	file.open("file.txt");

		while (std::getline(file, temp))
		{
			myString[x] = temp;
			x++;
		}

		for (int y = 0; y < 10; y++)
		{
			std::cout << "mystring[" << y << "] " << myString[y] << std::endl;

		}
	

	//close the file
	file.close();           

	return 0;
}
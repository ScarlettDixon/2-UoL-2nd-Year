//fileStream2.cpp
#include <iostream>
#include <fstream>


int main()
{
	std::ofstream file;

	file.open("file.txt", std::ios::app);      //open a file
	std::cout << "File opened .." << std::endl;

	//write a string and an int to the file
	file << "Hello file\n" << 2017 << "\n"; 
	std::cout << "Data written to File .." << std::endl;

	//close the file
	file.close(); 
	std::cout << "File closed .." << std::endl;

	return 0;
}
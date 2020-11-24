//SourceWriter.cpp
#include <iostream>
#include <fstream>
#include <vector>

void outputVector(std::vector<char>);

int main()
{
	//create the input file stream
	char character;
	std::ifstream input_stream;
	std::vector<char> input_vector;


	//open the file stream
	input_stream.open("SourceWriter.cpp"); 

	//get the first character from the stream
	input_stream.get(character);

	//loop through the file outputting each character
	while (!input_stream.eof())
	{
		input_vector.push_back(character);
		input_stream.get(character);
	}

	//close the file stream 
	input_stream.close();

	outputVector(input_vector);

	std::cout << std::endl;

	return 0;
}

void outputVector(std::vector<char> vec)
{
	std::vector<char>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it;
	}
}
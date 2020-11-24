//SourceWriter.cpp
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<char>UseVect(vector<char> V1);
vector<char>::iterator it1;

int main()
{
	vector<char> VectorChar;
	//create the input file stream
	char character;
	std::ifstream input_stream;

	//open the file stream
	input_stream.open("SourceWriter.cpp");

	//get the first character from the stream
	input_stream.get(character);

	//loop through the file outputting each chararcter
	while (!input_stream.eof())
	{
		VectorChar.push_back(character);
		//std::cout << character;
		input_stream.get(character);

	}
	VectorChar = UseVect(VectorChar);

	//close the file stream
	input_stream.close();
	for (int y = 0; y < VectorChar.size(); y++)
	{
		cout << VectorChar.at(y);
	}

	std::cout << std::endl;

	return 0;
}

vector<char>UseVect(vector<char> V1){
	for (it1 = V1.begin(); it1 != V1.end(); it1++)
	{
		
		if (*it1 == '/' && *(it1+1) == '/') 
		{
			while( *it1 != '\n' )
			{
				it1 = V1.erase(it1);
				
			}
		}
	}



	return V1;
 }
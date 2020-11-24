//fileStream.cpp
#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
	std::string testString;
	std::stringstream ss;
	int a, b;
	char op;

	while (std::getline(std::cin, testString)) 
	{							 // Reads line into testString
		ss.clear();				 // Reset from possible previous errors.
		ss.str(testString);      // Use testString as source of input.

		if (ss >> a >> op >> b) 
		{
			ss >> std::ws;        // Skip white space, if any. 'ws' is an input manipulator that skips whitespace

			if (ss.eof())		//eof() returns true if we reach the end of the string
			{  // true if we're at end of string.
				std::cout << "OK." << std::endl;
				std::cout << a << " " << op << " " << b << std::endl;
				break;
			}
			else 
			{
				std::cout << "Too many inputs." << std::endl;
				break;
			}
		}
		else
		{
			std::cout << "Input not correct" << std::endl;
			break;
		}
	
	}

	//float pi;
	//int q = 10;
	//std::string myStr;
	//std::string str = "3.142";

	////pass the int into stringstream
	//ss << q;
	//myStr = ss.str();
	//std::cout << myStr << std::endl;
	////Clear the stream of existing values
	////ss.str("");

	////pass the string into the stringstream - adding to what is already there
	//ss << str;
	////pass the string into the stringstream - replacing what is there
	// //ss.str(str);
	//
	////string variable is now in the format of float
	//ss >> pi;


	//std::cout << pi << std::endl;

	return 0;
}
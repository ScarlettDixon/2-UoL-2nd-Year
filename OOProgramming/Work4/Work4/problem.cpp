//problem.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

std::vector<std::string> split(std::string str, char c);

int main()
{
	std::string s = "to be or not to be";

	std::vector<std::string> splitStr = split(s, ' ');
	std::vector<std::string>::iterator it;

	for (it = splitStr.begin(); it != splitStr.end(); it++)
	{
		std::cout << *it << std::endl;
	}


	return 0;
}

std::vector<std::string> split(std::string str, char c)
{
	std::vector<std::string> vec;
	std::stringstream ss;
	std::string temp;

	ss << str;
	for (int x = 0; x < 6; x++)
	{
		std::getline(ss, temp, c);
		vec.push_back(temp);
	}


	return vec;
}
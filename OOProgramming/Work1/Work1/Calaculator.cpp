//Mark Doughty
//September 2017
#include <iostream>
//#include <stdlib.h>
#include <string>
#include <math.h>
#include <cmath>
#define PI 3.14159265

int main(int argc, char* argv[])
{
	//argv[0] is always the filename of the program

	//'atoi' converts strings to their numerical values
	if (argc == 4) {
		double number1 = atof(argv[1]);
		double number2 = atof(argv[3]);

		//char* needed as that is what argv[] is
		char* op = argv[2];

		std::cout << "Number of arguments:" << argc << std::endl;

		//do the calculation based on what the operator is

		if (*op == '-')
		{
			std::cout << number1 << " - " << number2 << " = " << (number1 - number2) << std::endl;
		}
		if (*op == '+')
		{
			std::cout << number1 << " + " << number2 << " = " << (number1 + number2) << std::endl;
		}
		if (*op == '*')
		{
			std::cout << number1 << " * " << number2 << " = " << (number1 * number2) << std::endl;
		}
		if (*op == '/')
		{
			std::cout << number1 << " / " << number2 << " = " << (number1 / number2) << std::endl;
		}
		
	}
	else if (argc == 3) {
		std::string op1 = argv[1];
		double number1 = atof(argv[2]);
		std::cout << "Number of arguments:" << argc << std::endl;
		if (op1 == "sin")
		{
			number1 = sin((number1* PI) / 180);
			std::cout << number1 << std::endl;
		}
		if (op1 == "cos")
		{
			number1 = cos((number1* PI) / 180);
			std::cout << number1 << std::endl;
		}
		if (op1 == "tan")
		{
			number1 = tan((number1* PI) / 180);
			std::cout << number1 << std::endl;
		}
		std::cin.get();
	}
	else
	{
		std::cout << "Error, incorrect number of arguments" << std::endl;
	}
	std::cin.get();
	return 0;
}
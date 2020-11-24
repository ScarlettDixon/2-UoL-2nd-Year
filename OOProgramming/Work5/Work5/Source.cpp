#include "Bus.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Program starts..." << endl << endl;
	Bus *ptr = new Bus[10];

	ptr[1].horn();

	delete [] ptr;

	cout << endl << "Program ends..." << endl;
	cin.get();
	return 0;
}
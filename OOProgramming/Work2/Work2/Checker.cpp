#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "chartest.h"

using namespace std;
//void ptrSwap(int*, int*);


void main()
{
	char input;
	cout << "Please enter a character for observation " << endl;
	cin.get(input);
	check(input);
	cin.get();
}


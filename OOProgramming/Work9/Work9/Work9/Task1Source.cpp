#include <iostream>
#include "Task1.h"
#include <ostream>

using namespace std;
int main()
{
	//don’t change any of the following
	B b;
	A *aP = &b;
	cout << aP->report() << endl; // want this to produce “I am child class”
	return 0;
}
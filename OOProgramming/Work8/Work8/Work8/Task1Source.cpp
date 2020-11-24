#include <iostream>
#include <string>
#include <sstream>

#include "Task1.h"

using namespace std;

int main() {

	Point *x1 = new Point(10,8);
	Point *x2 = new Point(10,8);

	Point *x3 = new Point(0,0);
	//*x3 = operator +(*x1, *x2);
	*x3 = *x1 + *x2;
	//You overload an operator to use that operator on things it wouldn't generally be used on
	//e.g. adding values from two objects together or two whole classes
	ostringstream test1;
    test1 << x3->getx() << " " << x3->gety() << endl;
	cout << test1.str();

	if (*x1 == *x2) { cout << "They are the same!!"; }
	else { cout << "They are not the same!!"; }
	cin.get();
}
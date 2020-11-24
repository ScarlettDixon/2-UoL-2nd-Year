#include <iostream>
//#include <string>

#include "Overloader.h"

using namespace std;

Variables::Variables()
{
}

Variables::~Variables()
{
}

void VariableType(int V1) {
	cout << "Output: " << V1 << endl;
	cout << "This is an integer" << endl;
}
void VariableType(double V2) {
	cout << "Output: " << V2 << endl;
	cout << "This is an double" << endl;

}
//void VariableType(string V3) {
//	cout << "Output: " << V3 << endl;
//	cout << "This is an string" << endl;
//
//}
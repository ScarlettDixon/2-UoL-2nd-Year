#include <iostream>
#include <string>

//#include "Overloader.h"

using namespace std;


void VariableType(int V1) {
	cout << "Output: " << V1 << endl;
	cout << "This is an integer" << endl;
}
void VariableType(double V2) {
	cout << "Output: " << V2 << endl;
	cout << "This is a double" << endl;

}
void VariableType(string V3) {
	cout << "Output: " << V3;//.c_str() << endl;
	cout << "This is a string" << endl;

}

int main() {
	int Var1 = 1;
	double Var2 = 2.01;
	string Var3 = "Hello World";
	VariableType(Var1);
	VariableType(Var2);
	VariableType(Var3);



}
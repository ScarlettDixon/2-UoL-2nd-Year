#include <iostream>
#include <string>
#include <sstream>

#include "Task2.h"

using namespace std;

int main() {

	CompNum *Com1 = new CompNum(2.4, 4.8);
	CompNum *Com2 = new CompNum(1.7, -2.6);
	CompNum *Com3 = new CompNum;
	Com1->display();
	Com2->display();
	*Com3 = *Com1 + *Com2;
	Com3->display();
	-*Com3;
	//Com3->display();
	//cout << "and negating the sum yields: " << -c3 << endl;
	cin.get();
}
#include <iostream>
#include <string>

#include "Task3.h"

using namespace std;

Messenger::Messenger()
{
}
Messenger::Messenger(string a)
{
	def = a;
}

Messenger::~Messenger()
{
}

void Messenger::print() {
	cout << def << endl;
	
}

void Messenger::print(string b) {
	cout << def << endl;
	cout << b << endl;
}
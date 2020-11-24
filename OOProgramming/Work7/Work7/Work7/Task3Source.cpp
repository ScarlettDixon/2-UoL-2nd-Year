#include <iostream>
#include <string>

#include "Task3.h"

using namespace std;

int main() {

	Messenger *Me1 = new Messenger("Hello World");
	//Messenger *Me2 = new Messenger("Understand");
	(*Me1).print("Please work");
	//(*Me2).print("Please work");
}
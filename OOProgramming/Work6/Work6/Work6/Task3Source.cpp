#include "Task3.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
	Zebra Zebra1;
	Dolphin Dolphin1;

	Zebra1.setValue("Jamez", 5);
	Dolphin1.setValue("Donnie", 22);

	Zebra1.display();
	Dolphin1.display();

	system("PAUSE");
}
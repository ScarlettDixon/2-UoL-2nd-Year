#include "Robot.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
	Robot *a = new Robot("a", 1);
	
	(*a).forward(1.0f);
	(*a).Turn(270);
	(*a).info();
	(*a).Turn(90);
	(*a).info();
	/*Robot *b = new Robot("b", 2);
	Robot *c = new Robot("c", 3);

	vector<Robot> robots;

	cout << "what happened here" << endl;

	robots.push_back(*a);
	robots.push_back(*b);
	robots.push_back(*c);

	cout << "what happended? " << endl;
	for (int i = 0; i < robots.size(); i++)
	{
		robots[i].forward((float)i + 1);
		robots[i].info();
	}

	delete a;
	delete b;
	delete c;
		*/
	cin.get();
	return 0;
}

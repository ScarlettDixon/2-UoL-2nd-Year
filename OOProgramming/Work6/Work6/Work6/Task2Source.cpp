#include "Task2.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
	Rectangle rect1;
	Triangle tri1;
	rect1.SetWidHei(2, 5);
	tri1.SetWidHei(3,2);
	cout << rect1.Area() << endl;
	cout << tri1.Area() << endl;
	cout << endl;
	cin.get();


}
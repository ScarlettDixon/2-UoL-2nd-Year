#include <iostream>
#include <string>

#include "Task4.h"

using namespace std;

int main() {
	Square *Sq1 = new  Square(5);
	Circle *Circ1 = new  Circle(3);
	Triangle *Tri1 = new  Triangle(4);

	(*Sq1).Area();
	(*Circ1).Area();
	(*Tri1).Area();
}
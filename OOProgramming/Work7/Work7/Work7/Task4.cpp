#include <iostream>
#include <string>

#include "Task4.h"

using namespace std;

Square::Square(int a)
{
	height = a;
}

Square::~Square()
{
}

Circle::Circle(int b)
{
	radius = b;
}

Circle::~Circle()
{
}

Triangle::Triangle(int c)
{
	height = c;
}

Triangle::~Triangle()
{
}

void Square::Area() {
	double area = height * height;
	cout << "The area of the Square is : " << area << endl;

}
void Circle::Area() {
	double area = 3.1415 * radius;
	cout << "The area of the Circle is : " << area << endl;
}
void Triangle::Area() {
	double area = (height * height)/ 2;
	cout << "The area of the Square is : " << area << endl;
}
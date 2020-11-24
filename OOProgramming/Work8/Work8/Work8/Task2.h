#pragma once
#include <iostream>
#include <string>

using namespace std;

class CompNum
{
public:
	CompNum();
	CompNum(double, double);
	~CompNum();
	void display();
	friend CompNum operator +(CompNum, CompNum);
	friend void operator -(CompNum);
	string op1 = " + ";
private:
	double a_real;
	double b_imaginary;
};

CompNum::CompNum()
{
}
CompNum::CompNum(double a, double b)
{
	a_real = a;
	b_imaginary = b;
}

CompNum::~CompNum()
{
}
void CompNum::display() {
	cout << "Complex Number is : "<< a_real << " + " << b_imaginary << "i" << endl;
}
CompNum operator +(CompNum c1, CompNum c2) {
	CompNum c3;
	c3.a_real = c1.a_real + c2.a_real;
	c3.b_imaginary = c1.b_imaginary + c2.b_imaginary;
	return c3;
}
void operator -(CompNum v1) {
	 v1.a_real *= -1;
	 v1.b_imaginary *= -1;
	 if (v1.b_imaginary < 0) {
		 cout << "Complex Number is : " << v1.a_real << "" << v1.b_imaginary << "i" << endl;
	 }
}
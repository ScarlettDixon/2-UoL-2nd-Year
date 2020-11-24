#pragma once
#include <iostream>

using namespace std;

class Shape
{
public:
	Shape();
	~Shape();
	void SetWidHei(int a, int b);
protected:
	int width, height;
private:

};

class Rectangle : public Shape {
	public:
		int Area() { return width*height; }
};
class Triangle : public Shape {
	public:
		int Area() { return (width*height)/2; }
};

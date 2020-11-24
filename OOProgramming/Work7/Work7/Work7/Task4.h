#pragma once
#include <iostream>
#include <string>

using namespace std;

class Square
{
public:
	Square(int a);
	~Square();
	int height;
	void Area();
private:
	
};

class Circle
{
public:
	Circle(int b);
	~Circle();
	int radius;
	void Area();
private:

};

class Triangle
{
public:
	Triangle(int c);
	~Triangle();
	//int base;
	int height;
	void Area();
private:

};


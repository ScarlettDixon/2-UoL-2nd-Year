#pragma once
#include <iostream>
#include <string>

using namespace std;

class Point {
	int x;
	int y;
public:
	int getx();
	int gety();
	Point();
	Point(int xval, int yval) { x = xval; y = yval; }
	//friend Point operator +(Point, Point); //non-member friend declaration
	Point operator +(Point); //Member declaration
	friend bool operator ==(Point, Point);
	

};


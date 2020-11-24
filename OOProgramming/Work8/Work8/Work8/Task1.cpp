#include <iostream>
#include <string>

#include "Task1.h"

using namespace std;

Point::Point() {}

//Point operator +(Point v1, Point v2) { //Used for the friend non-member declaration
//	Point v3;
//	v3.x = v1.x + v2.x;
//	v3.y = v1.y + v2.y;
//	return v3;
//};

Point  Point::operator +(Point v1) { //used for the member declaration
	Point v3;
	v3.x = v1.x + x;
	v3.y = v1.y + y;
	return v3;
};


bool operator ==(Point e1, Point e2)
{
	if (e1.x == e2.x && e1.y == e2.y) { return true; }
	else { return false; }
}
int Point::getx() { return x; }
int Point::gety() { return y; }
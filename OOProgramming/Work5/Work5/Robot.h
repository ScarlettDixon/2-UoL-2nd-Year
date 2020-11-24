#pragma once
#include <iostream>

using namespace std;
class Robot
{
private:
	string name;
	float length;
	float position[2];
	int Angle;

public:
	Robot();
	Robot(string n, float l);
	~Robot();
	
	bool forward(float m);
	bool Turn(int t);
	float getPosition();
	void info();

};


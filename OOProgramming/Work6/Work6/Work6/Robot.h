#pragma once
#include <iostream>

using namespace std;
class Robot
{
private:
protected:
	string name;
	float length;
	float position[2];
	int Angle;
public:
	Robot();
	Robot(string n, float l);
	~Robot();
	
	void Setname(string n);
	void SetLeng(float l);
	void SetPosi(float p1, float p2);
	void SetAngl(int a);
	bool forward(float m);
	bool Turn(int t);
	float getPosition();
	void info();

};

class AutonomousCar :
	public Robot
{
	
private:
	/*string name;
	float length;
	float position[2];
	int Angle;*/
protected:
public:
	AutonomousCar(string n, float l);
	
	~AutonomousCar();

	void drive(int d, int o );


};

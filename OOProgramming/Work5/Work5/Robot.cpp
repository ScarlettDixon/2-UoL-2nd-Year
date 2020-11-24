#include "Robot.h"
#include <string>

using namespace std;
float Robot::getPosition() {
	return position[0],position[1];
}

bool Robot::forward(float m) {
	if (length != 0.0f) {
		if (Angle == 0) {
			position[0] += length * m;
			cout << "moving robot " << name << "!" << endl;
			return true;
		}
		else if (Angle == 90) {
			position[1] += length * m;
			cout << "moving robot " << name << "!" << endl;
			return true;
		}
		if (Angle == 180) {
			position[0] -= length * m;
			cout << "moving robot " << name << "!" << endl;
			return true;
		}
		if (Angle == 270) {
			position[1] -= length * m;
			cout << "moving robot " << name << "!" << endl;
			return true;
		}
	}
	else
		return false;
}

bool Robot::Turn(int t) {
	int t2 = t % 90;
	if (t2 == 0) {
		Angle += t;
		if (Angle == 360) { Angle = 0;}
		return true;
	}
	else
		return false;
}

void Robot::info() {
	cout << "Robot " << name << " has length " << length << ", " << Angle << " degrees as an angle and position " << position[0] << "," << position[1] << endl;
}

Robot::Robot()
{
	name = "default";
	length = 0.0f;
	position[0] = 0.0f;
	position[1] = 0.0f;
	Angle = 0;
	
}

Robot::Robot(string n, float l)
{
	//cout << "Constructor invoked" << endl;
	name = n;
	length = l;
	position[0] = 0.0f;
	position[1] = 0.0f;
	Angle = 0;
	
}

Robot::~Robot()
{
	//cout << "destructor invoked. " << endl;
}

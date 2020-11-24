#pragma once
#include <iostream>

using namespace std;

class Robot
{
public:
	Robot();
	~Robot();

private:

};

class SocialRobot: public Robot
{
public:
	SocialRobot();
	~SocialRobot();

private:

};

class IndustRobot: public Robot
{
public:
	IndustRobot();
	~IndustRobot();

private:

};


IndustRobot::IndustRobot()
{
}

IndustRobot::~IndustRobot()
{
}

SocialRobot::SocialRobot()
{
}

SocialRobot::~SocialRobot()
{
}

Robot::Robot()
{
}

Robot::~Robot()
{
}
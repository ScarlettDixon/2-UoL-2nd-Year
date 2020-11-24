#pragma once

#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	virtual string report(void) {
		return "I am parent class";
	}
};
class B : public A
{
public:
	string report(void) {
		return "I am child class";
	}
};
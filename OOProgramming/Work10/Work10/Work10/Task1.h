#pragma once
#include <iostream>

using namespace std;

class A
{
};
class B : public A
{
};
class C : public B
{
public:
	~C() {
		cout << "C destructor" << endl;
	}
};
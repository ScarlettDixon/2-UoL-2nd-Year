#pragma once
#include <iostream>
#include <string>

using namespace std;

class Messenger
{
public:
	Messenger();
	Messenger(string a);
	~Messenger();
	void print();
	void print(string b);
protected:
private:
	string def;

};


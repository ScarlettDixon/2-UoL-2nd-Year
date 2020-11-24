#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal();
	~Animal();
	void setValue(string n, int a);
private:
protected:
	string name;
	int age;
};


class Dolphin: public Animal
{
public:
	void display();
private:
};

class Zebra : public Animal
{
public:
	void display();
private:
};


void Animal::setValue(string n, int a) 
{
	name = n;
	age = a;

}

void Dolphin::display() { 
	cout << "Dolphin's name is: " << name << endl;
	cout << "Dolphin's age is: " << age << endl;
	cout << "Dolphin's place of origin is: Gulf of Mexia" << endl;
}
void Zebra::display() {
	cout << "Zebra name is: " << name << endl;
	cout << "Zebra age is: " << age << endl;
	cout << "Zebra name is: Capetown " << endl;
}

Animal::Animal()
{
}

Animal::~Animal()
{
}
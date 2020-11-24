#include "Bus.h"
#include <iostream>

using namespace std;

//Define the function here
Bus::Bus(bool running, double price) {
	cout << "Parameterised constructor created" << endl;
	this->running = running;
	this->price = price;
}

Bus::Bus() {
	cout << "Bus created..." << endl;
	running = false;
}

Bus::~Bus() {
	cout << "Bus destroyed..." << endl;
}

void Bus::setPrice(double price) {
	this->price = price;
}

void Bus::getPrice() {
	cout << "The bus fare is " << char(156) << price << endl;
}

void Bus::enableRun() {
	running = true;
}

void Bus::stopRun() {
	running = false;
}

void Bus::horn() {
	if (running)
		cout << "Beep Beep!" << endl;
	else
		cout << "Bus not running" << endl;
}

void Bus::route() {
	cout << "Goes from Lincoln to Worksop." << endl;
}
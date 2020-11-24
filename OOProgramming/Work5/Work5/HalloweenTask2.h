#pragma once
#include <iostream>

using namespace std;
class Character
{
private: //Can only be used in the public functions below
	string name; // the name of the character
	bool trickOtreat; // ‘false’ set to play trick and ‘true’ set to play treat.
	string trick; // a description about the trick
	string treat; // a description about the treat

public: //Any variables here can be accessed from anywhere using the header file, any functions placed here can use the private variables
	Character();
	Character(string p);
	Character(string nam, bool tot, string tri, string tre);
	~Character();

	void getName();
	void setName();
	void setTrickOTreat();
	void getTrickOTreat();
	void setTrick();
	void getTrick();
	void setTreat();
	void getTreat();

};
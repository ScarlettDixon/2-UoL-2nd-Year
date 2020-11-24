#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
class Tool
{
public:
	//Tool();
	//~Tool();
	void setstrength(int s);
	int getstrength();
	char gettype();
protected:
	int strength;
	char type;
private:
	

};

class Rock: public Tool
{
public:
	Rock(int s);
	//~Rock();
	string fight(Tool op);
	//string fight(Paper op);
private:

};
class Paper : public Tool
{
public:
	Paper(int s);
	//~Paper();
	string fight(Tool op);

private:

};
class Scissors : public Tool
{
public:
	Scissors(int s);
	//~Scissors();
	string fight(Tool op);
private:

};


int Tool::getstrength() { return strength; }
char Tool::gettype() { return type; }
Rock::Rock(int s)
{
	strength = s;
	type = 'r';
}

Paper::Paper(int s) {
	strength = s;
	type = 'p';
}
Scissors::Scissors(int s) {
	strength = s;
	type = 's';
}

string Rock::fight(Tool op) {//int t = op.strength();	
	//cout << "Strength is:" << strength << endl;
	string output = "";
	int opstrength = op.getstrength();
	char optype = op.gettype();
	if (optype == 's') { opstrength *= 2; }
	if (strength > opstrength) {
		output = "Rock Wins!!";
	}
	return output;
}
string Paper::fight(Tool op) {
	string output = "";
	int opstrength = op.getstrength();
	char optype = op.gettype();
	if (optype == 'r') { opstrength *= 2; }
	if (strength > opstrength) {
		output = "Paper Wins!!";
	}
	return output;
}
string Scissors::fight(Tool op) {
	/*ostringstream oss;
	
	oss << "Hey Jude " << strength << " " << opstrength;
	string output = oss.str();;*/
	string output = "";
	int opstrength = op.getstrength();
	char optype = op.gettype();
	if (optype == 'p') { opstrength *= 2; }
	if (strength > opstrength) {
		output =  "Scissors Wins!!";
	}
	return output;
}

//string Rock::fight(Paper op) {
//	return "Hello";
//}
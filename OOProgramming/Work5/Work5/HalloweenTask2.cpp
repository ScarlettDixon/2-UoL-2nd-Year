#include "HalloweenTask2.h"
#include <string>

using namespace std;

//string Character::setName(string s) {//Not needed as I set all the names when constructing
//	name = s;
//
//	return name;
//}
//void Character::setTrickOTreat() {} 
//void Character::setTrick() {}
//void Character::setTreat() {}

void Character::getName() {
	cout << name ; //Need this so you can access the variables set in private
	//return "";
}
void Character::getTrickOTreat() {
	cout << "You get a :" << endl;
}
void Character::getTrick() {}
void Character::getTreat() {}






Character::Character(){ //Default Constructor
	name = "Default";
	trickOtreat = false;
	trick = "None";
	treat = "None";
}

//Character::Character(string p){
//	name = "Default";
//	trickOtreat = false;
//	trick = "None";
//	treat = "None";
//
//}
Character::Character(string nam, bool tot, string tri, string tre) { // Constructor 1.0
	name = nam;
	trickOtreat = tot;
	trick = tri;
	treat = tre;

}

Character::~Character() {} //Default Destructor
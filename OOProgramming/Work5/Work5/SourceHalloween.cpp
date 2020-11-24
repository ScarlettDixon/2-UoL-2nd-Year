#include <iostream>
#include <vector>
#include <string>

#include "HalloweenTask2.h" //used to link to header file which links both this cpp file and HalloweenTask2

using namespace std;
int main() {

	Character *c1 = new Character("witch", true, "Curse you to an eternity of pain", "Gives you a potion of invisibility"); //Sent to the Constructer 1.0
	Character *c2 = new Character("zombie", true, "Eat your flesh", "Hand you free brains"); //Sent to the Constructer 1.0
	Character *c3 = new Character("spiderman", true, "Cover you in webbing", "Give you a spiderman mask"); //Sent to the Constructer 1.0

	vector<Character> Characters; //Vector used to place all characters inside

	Characters.push_back(*c1);
	Characters.push_back(*c2);
	Characters.push_back(*c3);

	cout << "Please Choose a character:" << endl;
	/*for (int i = 0; i < Characters.size(); i++)
	{
		cout << i << " " << Characters.at(i) << endl;
	}*/
	cout << "" << (*c1).getName();
	cin.get();
	return 0;
}
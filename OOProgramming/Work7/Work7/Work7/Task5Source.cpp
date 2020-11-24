#include <iostream>
#include <string>

//#include "Task4.h"

using namespace std;

void main() {
	cout << "How many videotapes are there?" << endl;
	int numVideotapes = 1;
	cin >> numVideotapes;
	int* videotape = new int [numVideotapes];
	int* DVD = new int[numVideotapes];
	cout << "Enter the titles for each videotape." << endl;
	for (int i = 0; i < numVideotapes; i++) {
		cin >> videotape[i];
		DVD[i] << videotape[i];
	}
	for (int j = 0; j < numVideotapes; j++) {
		cout << videotape[j]<< endl;
	}
	cin.get();
	delete[] videotape;
	delete[] DVD;
}
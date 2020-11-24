#include <iostream>
//#include <stdio.h>
//#include <ctype.h>

using namespace std;




void outputArray(char[], int size);


int main()
{
	char c;
	char arr[10];
	char* arrPtr;
	arrPtr = arr;
	cout << "Enter some text" << endl;
	for (int x = 0; x < 10; x++)
	{
		cin.get(c);
		//cout << c << endl;
		*arrPtr = c;
		arrPtr++;
	}
	//cin.get();
	outputArray(arr, 10);
	return 0;
}void outputArray(char A[], int s) {	int p = s - 1;	for (p; p > -1; p--) {		cout << A[p];	}	cout << endl;	cin.get();}
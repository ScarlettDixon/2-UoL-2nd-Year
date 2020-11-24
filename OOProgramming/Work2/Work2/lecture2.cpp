#include <iostream>
#include "Raise.h"
#include "output.h"

using namespace std;
void ptrSwap(int*, int*);

int main()
{
	int x = 0;
	int y = 1;
	
	cout << x << " " << y << endl;
	ptrSwap(&x, &y);
	cout << x << " " << y << endl;
	cin.get();
	return 0;
}

void ptrSwap(int *pX, int *pY)
{
	int temp; 
	temp = *pX;
	*pX = *pY;
	*pY = temp;

}




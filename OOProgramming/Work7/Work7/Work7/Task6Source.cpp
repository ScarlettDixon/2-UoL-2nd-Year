#include <iostream>
#include <string>
#include <vector>

#include "Task6.h"

using namespace std;

void main() {
	Bank Bank1;
	Bank_Acc *Cust1 = new Bank_Acc (10001,"James", 50.99);
	Bank_Acc *Cust2 = new Bank_Acc(10002, "Miles", 2000.66);
	/*Bank_Acc *Cust3;*/
	//(*Cust1).Deposit(500.5, Bank1.v1);
	
	Bank1.Input(*Cust1);
	Bank1.Input(*Cust2);
	(*Cust1).Deposit((*Cust1).getidnum(), 500.5, Bank1.v1);
	/*Bank1.Input(*Cust3);*/
	Bank1.Input(*Cust1);
	Bank1.Input(*Cust2);
	//(*Cust1).getbalance();
	//Deposit won't work after items are added to Vector unless update to the vector occurs
	Bank1.Print(Bank1);
	
	cin.get();
}
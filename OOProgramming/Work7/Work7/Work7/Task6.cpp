#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Task6.h"

using namespace std;

//Bank_Acc::Bank_Acc()
//{
//	Bank_Acc::~Bank_Acc();
//}
Bank_Acc::Bank_Acc(int id, string nm, float ba)
{
	id_num = id;
	cust_nm = nm;
	balance = ba;
}

Bank_Acc::~Bank_Acc()
{
}
Bank::Bank()
{
}

Bank::~Bank()
{
}
string Bank_Acc::getname() { return cust_nm; }
int Bank_Acc::getidnum() { return id_num; }
float Bank_Acc::getbalance() { return balance; }
void Bank_Acc::Deposit(int id, float am, vector<Bank_Acc> v2) {
	//if (find(v2.begin(), v2.end(), id_num )!= v2.end() ) {
		vector<Bank_Acc>::iterator it1;
		//for (it1 = v2.begin(); it1 != v2.end(); it1++) {
		for (int a = 0; a < v2.size(); a++) {
			if (id == v2[a].id_num) {
				//it1->balance += am;
				v2[a].balance += am;
			}
		}
		balance += am;
	}
	/*else {
		balance += am;
	}*/

//}
void Bank_Acc::Withdraw(float am) { balance -= am; }
void Bank::Input(Bank_Acc inp) { v1.push_back(inp); }
void Bank::AddNewAcc() {


}

void Bank::Print(Bank b1) {

	vector<Bank_Acc>::iterator it1;
	//Bank_Acc *Test = new Bank_Acc(" ", 0000.00);
	for (it1 = b1.v1.begin(); it1 != b1.v1.end(); it1++) {
		/*cout << it1->cust_nm << " "; //Only works if custnm and balance are public
		cout << it1->balance << endl;*/
		//b1[it1->getbalance] =   ;
		cout << it1->getname() << " " << it1->getbalance() << endl;
	}
}
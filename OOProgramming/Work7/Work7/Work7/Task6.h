#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bank_Acc
{
public:
	/*Bank_Acc();*/
	Bank_Acc(int id, string nm, float ba);
	~Bank_Acc();
	void Deposit(int id ,float am, vector<Bank_Acc> v2);
	void Withdraw(float am);
	string getname();
	float getbalance();
	int getidnum();
	
private:
	int id_num;
	string cust_nm;
	float balance;
	
};

class Bank
{
public:
	Bank();
	~Bank();
	void Input(Bank_Acc inp);
	void AddNewAcc();
	void Print(Bank b1);
	vector<Bank_Acc> v1;
private:

};


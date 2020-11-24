#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Statistics
{
public:
	Statistics();
	~Statistics();
	float average(vector<int> a);
	void median(vector<int> a);
	void stndev(vector<int> a, float m);

private:

};

Statistics::Statistics()
{
}

Statistics::~Statistics()
{
}
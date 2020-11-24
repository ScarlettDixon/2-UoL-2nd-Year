#include "Task4.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	Statistics stat;
	vector<int> Arr = { 5,7,8,9,1 };
	float mean = stat.average(Arr);
	stat.median(Arr);
	stat.stndev(Arr, mean);
}

float Statistics::average(vector<int> a) {
	float av = 0.0f;
	int nums = 0;
	vector<int>::iterator iter1;

	for (iter1 = a.begin(); iter1 != a.end(); iter1++) {
		av += *iter1;
		nums++;
	}

	cout << "The average is: " << (av/nums) <<  endl;
	return (av / nums);
}
void Statistics::median(vector<int> a) {
	float med = 0.0f;
	sort(a.begin(), a.end());
	
	int si = a.size();
	si /= 2; 
	cout << "The median is: " << a[si] << endl;
}
void Statistics::stndev(vector<int> a, float m) {

	float stdev = 0.0f;
	float sum = 0.0f;
	int N = a.size();
	N --;
	vector<int>::iterator iter2;
	for (iter2 = a.begin(); iter2 != a.end(); iter2++) {
		sum += ((m - *iter2) * 2);
	}
	stdev = sum / N;
	stdev = fabsf(stdev);
	stdev = sqrt(stdev);
	cout << "The standard deviation is: " << stdev << endl;
}
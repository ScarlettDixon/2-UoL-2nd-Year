
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
	double total = 0;
	double mean;
	double numbs[10];
	double temp;
	double total2 = 0;
	double stddev;
	int loops = 1;

	while (loops < 11) {
		double num;
		cout << "Please enter number " << loops << " : " << endl;
		cin >> num;
		//cout << "this is " << num << endl;
		total += num;
		numbs[loops] = num;
		loops++;

	}
	mean = total / 10.0;
	loops = 1;
	while (loops < 11) {
		temp = 0;
		temp = numbs[loops];
		temp = (temp - mean);
		temp = pow(temp, 2);
		total2 += temp;
		loops++;
	}
	total2 = total2 / 10.0;
	stddev = sqrt(total2);
	cout << "The mean is: " << mean << endl;
	cout << "The standard deviation is: " << stddev << endl;
	cin.get();
}




/*if (argc >= 11) {
double number1 = atof(argv[1]);
double number2 = atof(argv[2]);
double number3 = atof(argv[3]);
double number4 = atof(argv[4]);
double number5 = atof(argv[5]);
double number6 = atof(argv[6]);
double number7 = atof(argv[7]);
double number8 = atof(argv[8]);
double number9 = atof(argv[9]);
double number10 = atof(argv[10]);
double mean;

mean =*/
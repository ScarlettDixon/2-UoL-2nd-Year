#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Reverse(vector<int> V1);
vector<int> RemOdd(vector<int> V2);
vector<int> MergeVec(/*vector<int> V4*/);

int main()
{
	vector<int> Vector1;
	
	int test = 0;

	for (int x = 1; x < 11; x++)
	{
		Vector1.push_back(x);
	}


	for (int y = 0; y < Vector1.size(); y++)
	{
		cout << Vector1.at(y);
	}
	cout << endl;


	Vector1 = Reverse(Vector1);
	for (int z = 0; z < Vector1.size(); z++)
	{
		cout << Vector1.at(z);
	}
	cout << endl;


	Vector1 = RemOdd(Vector1);
	for (int z = 0; z < Vector1.size(); z++)
	{
		cout << Vector1.at(z);
	}
	cout << endl;

	Vector1 = MergeVec(/*Vector1*/);
	for (int a = 0; a < Vector1.size(); a++)
	{
		cout << Vector1.at(a);
	}
	cout << endl;


	//cout << test << endl;
	return 0;
}


vector<int> Reverse(vector<int> V1) {
	
	vector<int> V2;
	int temp;
	//for (int y = 1; y <V1.size(); y++)
	//{
	//	
	//	//Iter1 = V1.begin();
	//	//temp = *Iter1;
	//	//V1.erase(V1.begin());
	//	////V2.push_back(temp);
	//	//V1.insert(V1.end(), temp);
	//}
	reverse(V1.begin(), V1.end());

	return V1;
}


vector<int> RemOdd(vector<int> V2) {
	vector<int>::iterator Iter1;
	vector<int> V3;
	Iter1 = V2.begin();
	for (vector<int>::iterator Iter1= V2.begin(); Iter1 != V2.end(); Iter1++)
	{
		if (*Iter1 % 2 == 0) {
			//V2.erase(Iter1);
			V3.push_back(*Iter1);
		}
	}
	
	


	return V3;
}


vector<int> MergeVec(/*vector<int> V4*/){
	vector<int> V4 = {1,2,3,4,5,6};
	vector<int> V5 = {2,4,6,8,10,12};




}
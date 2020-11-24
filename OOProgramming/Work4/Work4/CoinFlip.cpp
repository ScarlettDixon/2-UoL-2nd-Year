#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//vector<int> CoinStore;
	srand((int)time(0));
	int HeadCount = 0;
	int TailCount = 0;
	int temp = 0;
	int seqnum = 1;
	int highest = 0;
	
	for (int x = 0; x < 100; x++)
	{
		//generates random number in range 0 - 1
		
		int i = std::rand() % 2;
		std::cout << i << " ";
		if (x != 0 && i == temp) {
			seqnum++;
		}
		else {
			//CoinStore.push_back(seqnum);
			if (seqnum > highest) { highest = seqnum; }
			seqnum = 1;
		}
		if (i == 1) {HeadCount++;}
		else {TailCount++;}
		temp = i;

	}
	std::cout << std::endl;
	std::cout << "Heads: " << HeadCount << std::endl;
	std::cout << "Tails: " << TailCount << std::endl;
	std::cout << "Largest sequence: " << highest << std::endl;
	//std::cout << "Highest numbers of sequential numbers is: " << *std::max_element(CoinStore.begin(), CoinStore.end()) << std::endl;

	
	return 0;
}
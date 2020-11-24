#include "Raise.h"

int  Raise(int x)
{
	int answer = 1;

	for (int y = 0; y < x; y++)
	{
		answer = answer * x;
	}

	return answer;
}
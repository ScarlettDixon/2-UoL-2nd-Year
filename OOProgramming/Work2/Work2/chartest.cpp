#include "chartest.h"

using namespace std;
void check(char inp)
{
	if (islower(inp))
	{
		cout << "The character is lower case" << endl;
	}

	if (isupper(inp))
	{
		cout << "The character is upper case" << endl;
	}
	if (isdigit(inp))
	{
		cout << "The character is a number" << endl;
	}
	if (isblank(inp))
	{
		cout << "The character is a space" << endl;
	}

}
//twoDArray.cpp
#include <iostream>

int main()
{
	const int nRows = 3;
	const int nCols = 5;
	int arr2D[3][5];

	//fill the array
	for (int x = 0; x < nRows; x++)
	{
		for (int y = 0; y < nCols; y++)
		{
			arr2D[x][y] = y;
		}
	}

	//output the contents of the array
	for (int p = 0; p < nRows; p++)
	{
		for (int q = 0; q < nCols; q++)
		{
			std::cout << arr2D[p][q] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//using pointers
	/*for (int p = 0; p < nRows; p++)
	{
		for (int q = 0; q < nCols; q++)
		{
			std::cout << *(*(arr2D+p)+q) << " ";
		}
		std::cout << std::endl;
	}*/

	//2D to 1D conversion
	int arr1D[nRows*nCols];

	for (int p = 0; p < nRows; p++)
	{
		for (int q = 0; q < nCols; q++)
		{
			arr1D[p * nCols + q] = arr2D[p][q];
			std::cout << arr1D[p * nCols + q] << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
#include <iostream>
using namespace std;
typedef void(*Key)(int**, int**, int, int, int);
int** AllocateMemory(int);
void RandomArray(int**, int);
void DisplayArray(int**, int);
void CreateMatrixArea(int**, int**, int, int, int);
int FindMax(int**, int);
int** BuildMatrixFromKey(int**, int, Key);
int main()
{
	int n;
	cout << "Enter size of matrix: ";
	cin >> n;
	int** sourceMatrix = AllocateMemory(n);
	RandomArray(sourceMatrix, n);
	DisplayArray(sourceMatrix, n);
	cout << endl;
	int** resultMatrix = BuildMatrixFromKey(sourceMatrix, n, CreateMatrixArea);
	DisplayArray(resultMatrix, n);
	delete[] sourceMatrix;
	delete[] resultMatrix;
}


int** AllocateMemory(int n)
{
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
	}
	return matrix;
}

void RandomArray(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand() % 10;
	}
}

void DisplayArray(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{

		{
			for (int j = 0; j < n; j++)
				cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void CreateMatrixArea(int** source, int** result, int i, int j, int border)
{
	result[i][j] = source[i][j];
	int count = 1;
	for (int m = i + 1; m < border; m++, count++)
	{
		for (int n = j - count; n <= j + count; n++)
		{
			if (n >= 0 && n < border)
				result[m][n] = source[m][n];
		}
	}
	count = 1;
	for (int m = i - 1; m >= 0; m--, count++)
	{
		for (int n = j - count; n <= j + count; n++)
		{
			if (n >= 0 && n < border)
				result[m][n] = source[m][n];
		}
	}
}

int FindMax(int** array, int n)
{
	int max = array[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (array[i][j] > max)
				max = array[i][j];
	return max;
}

int** BuildMatrixFromKey(int** sourceMatrix, int n, Key criteria)
{
	int** resultMatrix = AllocateMemory(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int** matrixArea = AllocateMemory(n);
			criteria(sourceMatrix, matrixArea, i, j, n);
			resultMatrix[i][j] = FindMax(matrixArea, n);
			delete[] matrixArea;
		}
	}
	return resultMatrix;
}
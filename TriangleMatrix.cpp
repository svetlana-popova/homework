#include <iostream>
using namespace std;
int** AllocateMemory(int, int*);
int** AllocateQuadMemory(int);
int* AllocateMemory(int);
void RandomArray(int**, int, int*);
void DisplayArray(int**, int, int*);
void DisplayArray(int**, int);
void ArrayConsecutiveNumbers(int* a, int n);
void EnterTriangleArray(int**, int*, int);
void TransposeMatrix(int**, int*, int);



int main()
{
	int n = 0;
	cout << "Enter number of columns" << endl;
	cin >> n;
	int* lengths = AllocateMemory(n);
	ArrayConsecutiveNumbers(lengths, n);
	int** matrix = AllocateQuadMemory(n);
	DisplayArray(matrix, n);
	cout << endl;
	EnterTriangleArray(matrix, lengths, n);
	DisplayArray(matrix, n);
	cout << endl;
	TransposeMatrix(matrix, lengths, n);
	DisplayArray(matrix, n);
	cout << endl;

}


void ArrayConsecutiveNumbers(int* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
}

int** AllocateMemory(int n, int* arr)
{
	int** matrix = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[arr[i]];
		for (int j = 0; j < arr[i]; j++)
			matrix[i][j] = 0;
	}
	return matrix;
}

int** AllocateQuadMemory(int n)
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

int* AllocateMemory(int n)
{
	int* a = new int[n];
	for (int* p = a; p < a + n; p++)
		*p = 0;
	return a;
}

void RandomArray(int** matrix, int n, int* arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int g = 0; g < arr[i]; g++)
			matrix[i][g] = rand() % 10;
	}
}

void RandomArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 10;
}

void DisplayArray(int** matrix, int n, int* arr)
{
	for (int i = 0; i < n; i++)
	{

		{
			for (int g = 0; g < arr[i]; g++)
				cout << matrix[i][g] << " ";
		}
		cout << endl;
	}
}

void DisplayArray(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{

		{
			for (int g = 0; g < n; g++)
				cout << matrix[i][g] << " ";
		}
		cout << endl;
	}
}

void DisplayArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void EnterTriangleArray(int** matrix, int* lengths, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int g = 0; g < lengths[i] - 1; g++)
			matrix[i][g] = rand() % 10;
	}
}

void TransposeMatrix(int** matrix, int* lengths, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			matrix[j][i] = matrix[n - j][n - i];
		}
	}
}
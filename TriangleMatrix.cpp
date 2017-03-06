#include <iostream>
using namespace std;
int** AllocateMemory(int, int*);
int* AllocateMemory(int);
void DisplayArray(int**, int, int*);
void ArrayConsecutiveNumbers(int* a, int n);
void EnterTriangleArray(int**, int*, int);
void ReflectMatrix(int**, int*, int);



int main()
{
	int n = 0;
	cout << "Enter number of columns" << endl;
	cin >> n;
	int* lengths = AllocateMemory(n);
	ArrayConsecutiveNumbers(lengths, n);
	int** matrix = AllocateMemory(n, lengths);
	EnterTriangleArray(matrix, lengths, n);
	DisplayArray(matrix, n, lengths);
	cout << endl;
	ReflectMatrix(matrix, lengths, n);
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


int* AllocateMemory(int n)
{
	int* a = new int[n];
	for (int* p = a; p < a + n; p++)
		*p = 0;
	return a;
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


void EnterTriangleArray(int** matrix, int* lengths, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int g = 0; g < lengths[i] - 1; g++)
			matrix[i][g] = rand() % 10;
	}
}

void ReflectMatrix(int** matrix, int* lengths, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			cout << matrix[i][j] << " ";
		for (int k = i + 1; k < n; k++)
			cout << matrix[k][i] << " ";
		cout << endl;
	}
}

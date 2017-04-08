#include <iostream>
#include "math.h"
using namespace std;
double CountFactorial(int);
double MySinus(double x, double acc);
void EnterMatrixMySinus(double**, int, int);
void EnterMatrixSin(double**, int, int);
double* AllocateMemory(int);
double** AllocateMemory(int, int);
void DisplayArray(double**, int, int);
double NormOfMatrix(double**, int, int);
double FindMax(double*, int);

int main()
{
	double x, accurancy;
	int rows, columns;
	cout << "Number of rows = ";
	cin >> rows;
	cout << "Number of columns = ";
	cin >> columns;
	double ** realMatrix = AllocateMemory(rows, columns);
	double** expectedMatrix = AllocateMemory(rows, columns);
	EnterMatrixMySinus(realMatrix, rows, columns);
	EnterMatrixSin(expectedMatrix, rows, columns);
	DisplayArray(realMatrix, rows, columns);
	cout << endl;
	DisplayArray(expectedMatrix, rows, columns);
	double realNorm = NormOfMatrix(realMatrix, rows, columns);
	cout << "Norm of real matrix is " << realNorm << endl;
	double expectedNorm = NormOfMatrix(expectedMatrix, rows, columns);
	cout << "Norm of expected matrix is " << expectedNorm << endl;
}

double CountFactorial(int n)
{
	double answer = 1.0;
	for (int i = 1; i <= n; i++)
	{
		answer *= i;
	}
	return answer;
}

double MySinus(double x, double acc)
{
	double sum = 0, temp = 1;
	int i = 1, p = 1;
	do
	{
		double devider = CountFactorial(2 * i - 1);
		temp *= p * pow(x, (2 * i - 1)) / devider;
		sum += temp;
		i += 2;
		p *= -1;
	} while (fabs(temp) > acc);
	return sum;
}

void EnterMatrixMySinus(double** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			double temp = ((double)i / (j + 1) / 10);
			matrix[i][j] = MySinus(temp, 0.00001);
		}
	}
}

void EnterMatrixSin(double** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = sin((double)i / (j + 1) / 10);
		}
	}
}

double** AllocateMemory(int n, int m)
{
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[m];
		for (int j = 0; j < m; j++)
			matrix[i][j] = 0;
	}
	return matrix;
}

double* AllocateMemory(int n)
{
	double* matrix = new double[n];
	for (int i = 0; i < n; i++)
		matrix[i] = 0;
	return matrix;
}

void DisplayArray(double** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{

		{
			for (int j = 0; j < m; j++)
			{
				cout.setf(ios::fixed);
				cout.width(7);
				cout << matrix[i][j] << " ";
			}
		}
		cout << endl;
	}
}

double NormOfMatrix(double** matrix, int n, int m)
{
	double* SumsOfRows = AllocateMemory(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			SumsOfRows[i] += fabs(matrix[i][j]);
	}
	return FindMax(SumsOfRows, n);
}

double FindMax(double* array, int n)
{
	double max = array[0];
	for (int i = 0; i < n; i++)
		if (array[i + 1] > array[i])
			max = array[i + 1];
	return max;
}
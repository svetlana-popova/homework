#include <iostream>
using namespace std;
int** AllocateMemory(int, int*);
int* AllocateMemory(int);
void RandomArray(int**, int, int*);
void RandomArray(int*, int);
int SumElements(int*, int);
void DisplayArray(int**, int, int* );
void DisplayArray(int*, int);
int* CreateSumRows(int**, int, int*);
void SortRowsBySum(int**, int*, int, int*);
void Swap(int*&, int*&);
void Swap(int&, int&);
void SortRowsBySum1(int**, int, int*);



int main()
{
	int n = 0;
	cout << "Enter number of columns" << endl;
	cin >> n;
	int* arr = AllocateMemory(n);
	RandomArray(arr, n);
	int** matrix = AllocateMemory(n, arr);
	RandomArray(matrix, n, arr);
	DisplayArray(matrix, n, arr);
	cout << endl;
	int* sums = CreateSumRows(matrix, n, arr);
	cout << "Sums: ";
	DisplayArray(sums, n);
	cout << endl;
	SortRowsBySum(matrix, sums, n, arr);
	//SortRowsBySum1(matrix, n, arr);
	cout << "After Sort: ";
	DisplayArray(matrix, n, arr);
	cout << endl;
	cout << "The second ";
	DisplayArray(sums, n);
	cout << endl;
	delete[] sums;
	delete[] matrix;
	delete[] arr;

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

void DisplayArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	cout << arr[i] << " ";
}

int SumElements(int* a, int n)
	{
		int result = 0;
		for (int* p = a; p < a + n; p++)
			result += *p;
		return result;
	}


		//1 variant
int* CreateSumRows(int** matrix, int n, int* arr)
	{
		int* sums = AllocateMemory(n);
		for (int i = 0; i < n; i++)
		{
			sums[i] = SumElements(matrix[i], arr[i]);
		}
		return sums;
	}

void SortRowsBySum(int** matrix, int* sums, int n, int* arr)
{
	for (int i = 1; i < n; i++)
	{
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int g = n - 1; g >= i; g--)
			{
				if (sums[g] < sums[g - 1])
				{
					Swap(arr[g], arr[g - 1]);
					Swap(sums[g], sums[g - 1]);
					Swap(matrix[g], matrix[g - 1]);
				}
			}
		}
		
	}
}

void Swap(int*& a, int*& b)
		{
			int* t = a;
			a = b;
			b = t;
		}

void Swap(int& a, int& b)
		{
			int t = a;
			a = b;
			b = t;
		}


//2 variant
void SortRowsBySum1(int** matrix, int n, int* arr)
{
	for (int i = 1; i < n; i++)
	{
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int g = n - 1; g >= i; g--)
				if (SumElements(matrix[g], arr[g]) < SumElements(matrix[g - 1], arr[g - 1]))
				{
					Swap(arr[g], arr[g - 1]);
					Swap(matrix[g], matrix[g - 1]);
				}

		}
	}
}
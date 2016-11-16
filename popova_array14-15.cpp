#include <iostream>
using namespace std;

void EnterArray(int a[], int);
void DisplayArray(int a[], int);
int DeleteTheSame(int a[], int, int&);
void ShiftLeft(int a[], int, int);

int main()
{
	const int N = 100;
	int a[N] = { 0 };
	int n;
	while (true)
	{
		cout << "Enter n (n > 0 and n < 100)" << endl;
		cin >> n;
		if (n > 0 && n < 100) break;
		else
			cout << "Input error! Please try again" << endl;
	}
	system("cls");
	EnterArray(a, n);
	DisplayArray(a, n);
	cout << endl;
	int n1 = n;
	int x = DeleteTheSame(a, n, n1);
	DisplayArray(a, n1);
	cout << endl;
	cout << "Array consists of " << x << " unique elements" <<endl;
	return 0;
}


void EnterArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter a[" << i + 1 << "] = " << endl;
		cin >> a[i];
	}
}

void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}


int DeleteTheSame(int a[], int n, int& n1)
{
	int counter = n;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] == a[i])
			{
				ShiftLeft(a, n, i);
				counter--;
				n1--;
			}
		}
	}
	return counter;
}

void ShiftLeft(int a[], int n, int i)
{
	for (i; i < n; i++)
	{
		a[i] = a[i + 1];
		
	}
}



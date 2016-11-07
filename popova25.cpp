#include <iostream>
using namespace std;

void MinMax (int a[], int, int&, int&);
void RandomArray(int a[], int);
void DisplayArray(int a[], int);

int main()
{
	const int N = 100;
	int a[N] = {0};
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
	RandomArray (a, n);
	DisplayArray(a, n);
	cout << endl;
	int min = 0;
	int max = 0;
	MinMax(a, n, min, max);
	cout << "Minimum is " << a[min] << ", it's number is " << min + 1 << endl;
	cout << "Maximum is " << a[max] << ", it's number is " << max + 1 << endl;
}
void RandomArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 - 50;
	}
}

void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void MinMax(int a[], int n, int& min, int& max)
{
	for (int i = 0; i < n; i++)
	{
		if (a[min] >= a[i])
			min = i;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[max] < a[i])
			max = i;

	}
	
}


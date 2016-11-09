#include <iostream>
using namespace std;

void RandomArray(int a[], int);
void DisplayArray(int a[], int);
void InvertedArray (int a[], int);

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
	RandomArray(a, n);
	DisplayArray(a, n);
	cout << endl;
	InvertedArray(a, n);
	DisplayArray(a, n);
	return 0;
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
void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void InvertedArray(int a[], int n)
{
		for (int i = 0; i < n / 2; i++)
	{
		Swap(a[i], a[n - 1 - i]);
	}
}



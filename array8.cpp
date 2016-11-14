#include <iostream>
using namespace std;

void RandomArray(int a[], int);
void DisplayArray(int a[], int);
int SumNeighbElements(int a[], int);
void PrintLine(int a);

int main()
{
	const int N = 100;
	int a[N] = { 0 };
	int n;
	while (true)
	{
		cout << "Enter n (n > 0 and n < 100, should be even number)" << endl;
		cin >> n;
		if (n > 0 && n < 100 && n % 2 == 0) break;
		else
			cout << "Input error! Please try again" << endl;
	}
	system("cls");
	RandomArray(a, n);
	DisplayArray(a, n);
	cout << endl;
	int x = SumNeighbElements(a, n);
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
		PrintLine (a[i]);
	}
}

int SumNeighbElements(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		a[i] = a[i * 2] + a[i * 2 + 1];
		PrintLine(a[i]);
	}
	cout << endl;
	n = n / 2;
	if (n == 0)
		return a[0];
	else
		SumNeighbElements(a, n);
}

void PrintLine(int a)
{
	cout << a << " ";
}
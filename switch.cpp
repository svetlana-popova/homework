#include <iostream>
using namespace std;
void EnterArray(int[], int&);
void DisplayArray(char[], int);
void Switcher(int[], char[], int);

int main()
{
	const int N = 100;
	int a[N] = { 0 };
	int n = 0;
	char b[N] = { " " };
	EnterArray(a, n);
	Switcher(a, b, n);
	DisplayArray(b, n);
}

void EnterArray(int a[], int& n)
{
	int i = 0;
	cout << "When numbers are over enter '-1'" << endl;
	while (true)
	{
		cout << "Enter a[" << i + 1 << "] = " ;
		cin >> a[i];
		if (a[i] == -1) break;
		i++;
		n++;
	}
}

void Switcher(int a[], char b[], int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		if (a[i] >= 1 && a[i] <= 26)
		{
			b[i] = 123 - a[i];
		}
		if (a[i] == 27)
		{
			b[i] = '!';
		}
		if (a[i] == 28)
		{
			b[i] = 43;
		}
		if (a[i] == 29)
		{
			b[i] = 32;
		}

	}
}

void DisplayArray(char a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}
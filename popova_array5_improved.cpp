#include <iostream>
using namespace std;

void RandomArray(int a[], int);
void DisplayArray(int a[], int);
void FindMinMax(int a[], int, int b[], int&, int c[], int&);


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
	int b[N] = { 0 };
	int m = 0;
	int c[N] = { 0 };
	int l = 0;
	FindMinMax(a, n, b, m, c, l);
	cout << "Local Min are ";
	DisplayArray(b, m);
	cout << endl;
	cout << "Local Max are ";
	DisplayArray(c, l);
	cout << endl;

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


void FindMinMax(int a[], int n, int b[], int& m, int c[], int& l)
{
	int i = 0;
	if (a[i] < a[i + 1])
	{
		b[m] = a[i];
		m++;
	}
	if (a[i] > a[i + 1])
	{
		c[l] = a[i];
		l++;
	}
	i++;

	for (; i < n - 1; i++)
	{
		if (a[i] < a[i + 1] && a[i] < a[i - 1])
		{
			b[m] = a[i];
			m++;
		}
		if (a[i] > a[i + 1] && a[i] > a[i - 1])
		{
			c[l] = a[i];
			l++;
		}
	}
	if (a[i - 1] > a[i])
	{
		b[m] = a[i];
		m++;
	}
	if (a[i - 1] < a[i])
	{
		c[l] = a[i];
		l++;
	}
}



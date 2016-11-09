#include <iostream>
using namespace std;

void RandomArray(int a[], int);
void DisplayArray(int a[], int);
void DeposeArray(int a[], int, int);
void ChangeElement(int&, int&);



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
	int step;
	cout << "Enter step" << endl;
	cin >> step;
	DeposeArray(a, n, step);


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
void DeposeArray(int a[], int n, int step)
{
	const int N = 100;
	int b[N] = { 0 };
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}

	for (int i = 0; i < n - step; i++)
	{
		ChangeElement(a[i], b[i + step]);
	}
	int i = n - step;
	int j = 0;
	for (; i < n; i++, j++)
	{
		ChangeElement(a[i], b[j]);
	}
	DisplayArray(b, n);
}


void ChangeElement(int& a, int& b)
{
	b = a;
}





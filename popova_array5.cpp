#include <iostream>
using namespace std;

void RandomArray(int a[], int);
void DisplayArray(int a[], int);
void FindLocalMinMax(int a[], int);


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
	FindLocalMinMax(a, n);

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

void FindLocalMinMax(int a[], int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] < a[i + 1] && a[i] < a[i - 1])
			cout << a[i] << " is a local minimum" << endl;
		if (a[i] > a[i + 1] && a[i] > a[i - 1])
			cout << a[i] << " is a local maximum" << endl;
	}
}



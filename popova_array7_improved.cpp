#include <iostream>
using namespace std;

void RandomArray(int a[], int);
void DisplayArray(int a[], int);
void ShiftRight(int a[], int);
void ShiftLeft(int a[], int);
void KShiftRight(int a[], int, int);
void KShiftLeft(int a[], int, int);




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
	char direction;
	cout << "Left or right? Enter 'l' for left and 'r' for right" << endl;
	cin >> direction;
	system("cls");
	RandomArray(a, n);
	DisplayArray(a, n);
	cout << endl;
	int step;
	cout << "Enter step" << endl;
	cin >> step;
	if (direction == 'r')
		KShiftRight(a, n, step);
	else
		KShiftLeft(a, n, step);
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

void ShiftRight(int a[], int n)
{
	int temp = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		a[i + 1] = a[i];
	}
	a[0] = temp;
}

void ShiftLeft(int a[], int n)
{
	int temp = a[0];
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	a[n - 1] = temp;
}


void KShiftRight(int a[], int n, int step)
{
	for (int i = 1; i <= step; i++)
	{
		ShiftRight(a, n);
	}
}

void KShiftLeft(int a[], int n, int step)
{
	for (int i = 1; i <= step; i++)
	{
		ShiftLeft(a, n);
	}
}




#include <iostream>
using namespace std;

void RandomArray(int a[], int);
void DisplayArray(int a[], int);
void FindLessThen(int a[], int, int, bool&);



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
	int number;
	cout << "Enter number to compare with elements of the array" << endl;
	cin >> number;
	bool ok = false;
	FindLessThen(a, n, number, ok);
	if (ok == false)
		cout << "There is no elements less then your number" << endl;
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
void FindLessThen(int a[], int n, int number, bool& ok)
{
	for (int i = 0; i < n; i++)
		if (a[i] < number)
		{
			cout << a[i] << " is less then " << number << endl;
			ok = true;
		}
}



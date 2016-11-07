#include <iostream>
using namespace std;

void RandomArray(int a[], int);
void DisplayArray(int a[], int);
int CountPositive(int a[], int, int&);
int CountNegative(int a[], int, int&);

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
	int positive = 0;
	int negative = 0;
	int i = CountPositive(a, n, positive);
	int j = CountNegative(a, n, negative);
	cout << "Sum of positive numbers is " << i << ", there number is " << positive << endl;;
	cout << "Sum of negative numbers is " << j << ", there number is " << negative << endl;;

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

int CountPositive(int a[], int n, int& positive)
{
	int positivesum = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			positivesum += a[i];
			positive++;
		}
	}
	return positivesum;

}
int CountNegative(int a[], int n, int& negative)
{
	int negativesum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			negativesum += a[i];
			negative++;
		}
	}
	return negativesum;
}

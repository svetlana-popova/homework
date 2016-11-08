#include <iostream>
using namespace std;

void RandomArray(int a[], int);
void DisplayArray(int a[], int);
void AnalyzeArray(int a[], int, bool&, bool&, bool&);
void PrintAnswer(bool, bool, bool);

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
	bool incr = false;
	bool eq = false;
	bool decr = false;
	AnalyzeArray(a, n, incr, eq, decr);
	PrintAnswer(incr, eq, decr);
	system("pause");
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

void AnalyzeArray(int a[], int n, bool&incr, bool&eq, bool&decr)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i + 1]) incr = true;
		if (a[i] == a[i + 1]) eq = true;
		if (a[i] > a[i + 1]) decr = true;
	}
}

void PrintAnswer(bool incr, bool eq, bool decr)
{
	if (incr && !eq && !decr)
		cout << "Strictly increasing sequence" << endl;
	if (!incr && eq && !decr)
		cout << "Monotonous sequence" << endl;
	if (!incr && !eq && decr)
		cout << "Strictly decreasing sequence" << endl;
	if (incr && eq && !decr)
		cout << "Not strictly increasing sequence" << endl;
	if (!incr && eq && decr)
		cout << "Not strictly decreasing sequence" << endl;
	if (incr && !eq && decr)
		cout << "Chaotic sequence" << endl;
	if (incr && eq && decr)
		cout << "Chaotic sequence" << endl;
}
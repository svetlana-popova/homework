#include <iostream>
using namespace std;
void GetlineForInt(int a[], int&);
void DisplayArray(int a[], int);
void BubbleSort(int[], int);
void Swap(int&, int&);
void CopyArray (int[], int[], int);
bool CompareArrays(int[], int[], int);
void FindNextSmaller(int[], int);

int main() 
{
	const int N = 10;
	int a[N] = { 0 };
	int n = 0;
	GetlineForInt(a, n);
	int b[N] = { 0 };
	CopyArray(a, b, n);
	BubbleSort(b, n);
	bool ok = CompareArrays(a, b, n);
	if (!ok)
	{
		FindNextSmaller(a, n);
		DisplayArray(a, n);
	}
		else cout << "-1" << endl;
	
}

void GetlineForInt (int a[], int& n)
{
	cout << "Enter number (press 'enter' after each digit). When number is over enter '-1' " << endl;
	int i = 0;
	while (true)
	{
		cin >> a[i];
		if (a[i] == -1) break;
		i++;
		n++;
	}
}

void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << " ";
}

void BubbleSort(int a[], int n)
{
	int i = 1;
	bool flag = true;
	for (int i = 1; i <= n; i++)
		while(flag)
	{
		flag = false;
		for (int j = n - 1; j >= i; j--)
		{
			if (a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
				flag = true;
			}
		}
		i++;
	}
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

bool CompareArrays(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

void FindNextSmaller(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] < a[i - 1])
		{
			Swap(a[i], a[i - 1]);
			break;
		}
	}
}

//Tested on "32 -67 43 -78 44 89 -91 12 -98" result "-91 -67 -78 -98"
//Tested on "1 -32 2 -32 4 -56 7 -112 90 -111" result "-111 -56 -32 -112"


#include <iostream>
using namespace std;

int* AllocateMemory(int);
void EnterArray(int*, int);
void DisplayArray(int*, int);
bool IfNegativeAfterPositive(int, int);
void CopyToAnotherArray(int* , int*, int& int&);
void DeleteandShift(int* , int& );
int ConvertTo8(int);
void DeleteRepeatedElements(int*, int&);
int CountOddDigits(int);
void Swap(int&, int&);
void BubbleSort(int*, int);


int main()
{
	int n = 0;
	cout << "How many elements of array are you going to analyse?" << endl;
	cin >> n;
	int* a = AllocateMemory(n);
	int* b = AllocateMemory(n);
	EnterArray(a, n);
	cout << "Source array: ";
	DisplayArray(a, n);
	cout << endl;
	int m = 0;
	CopyToAnotherArray(a, b, n, m);
	cout << "Array of negative numbers: ";
	DisplayArray(b, m);
	cout << endl;
	DeleteRepeatedElements(b, m);
	cout << "Without repetead elements: ";
	DisplayArray(b, m);
	cout << endl;
	BubbleSort(b, m);
	cout << "Sort array: ";
	DisplayArray(b, m);
	delete [] a;
	delete [] b;
	return 0;
}

int* AllocateMemory(int n)
{
	int* a = new int[n];
	for (int* p = a; p < a + n; p++)
	{
		*p = 0;
	}
	return a;
}

void EnterArray(int* a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		cout << "Enter next element" << endl;
		cin >> *p;
	}
}

void DisplayArray(int* a, int n)
{
	for (int* p = a; p < a + n; p++)
	{
		cout << *p << " ";
	}
}

bool IfNegativeAfterPositive(int a, int b)
{
	if (a <= 0 && b >= 0)
		return true;
	else
		return false;
}

void CopyToAnotherArray(int* a, int* b, int& n, int& m)
{
	int* v = b;
	for (int* p = a + 1; p < a + n; p++)
	{

		bool ok = IfNegativeAfterPositive(*p, *(p - 1));
		if (ok == true)
		{
			*v = *p;
			m++;
			DeleteandShift(p, n);
			v++;
		}
	}
}

void DeleteandShift(int* a, int& n)
{
	for (int *p = a; p < a + n - 1; p++)
	{
		*p = *(p + 1);
	}
	n--;

}

int ConvertTo8(int n)
{
	int multiplier = 1;
	int result = 0;
	int remainder;
	while (n >= 8)
	{
		remainder = n % 8;
		result += multiplier * remainder;
		n = n / 8;
		multiplier *= 10;
	}
	remainder = n % 8;
	result += multiplier * remainder;
	return result;
}

void DeleteRepeatedElements(int* a, int& n)
{
	for (int* p = a; p < a + n; p++)
	{
		if (*p == *(p + 1))
			DeleteandShift(p + 1, n);
	}

}

int CountOddDigits(int n)
{
	int counter = 0;
	while (n)
	{
		int digit = n % 10;
		if (digit % 2 == 0)
			counter++;
		n /= 10;
	}
	return counter;
}


void Swap(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int* a, int n)
{
	bool flag = true;
	for (int* p = a; p < a + n - 1; p++)
		while (flag)
		{
			flag = false;

			for (int* g = a + n - 1; g > a; g--)
			{
				int i1 = CountOddDigits(ConvertTo8(*g));
				int i2 = CountOddDigits(ConvertTo8(*(g - 1)));
				if (i2 > i1)
				{
					Swap(*g, *(g - 1));
					flag = true;
				}
			}

		}
}

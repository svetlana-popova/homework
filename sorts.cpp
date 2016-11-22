#include <iostream>
using namespace std;

//void BubbleSort(double[], int);
//void ChoiceSort(double[], int);
void InsertionSort(double[], int);
void RandomArray(double[], int);
void DisplayArray(double[], int);
void Swap(double&, double&);

int main()
{
	const int N = 100;
	double a[N] = { 0 };
	int n;
	while (true)
	{
		cout << "Enter n (n > 0 and n < 100)" << endl;
		cin >> n;
		if (n > 0 && n < 100) break;
		else
			cout << "Input error! Please try again" << endl;
	}
	RandomArray(a, n);
	DisplayArray(a, n);
	//BubbleSort(a, n);
	//ChoiceSort(a, n);
	InsertionSort(a, n);
	cout << endl;
	DisplayArray(a, n);
	return 0;
}

//void BubbleSort(double a[], int n)
//{
//	int i = 1;
//	bool flag = true;
//	for (int i = 1; i <= n; i++)
//		while(flag)
//	{
//		flag = false;
//		for (int j = n - 1; j >= i; j--)
//		{
//			if (a[j] > a[j - 1])
//			{
//				Swap(a[j], a[j - 1]);
//				flag = true;
//			}
//		}
//		i++;
//	}
//}


//void ChoiceSort(double a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < n; j++)
//		{
//			if (a[j] > a[max]) max = j;
//
//		}
//		Swap(a[i], a[max]);
//	}
//}

void InsertionSort(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				double temp = a[i];
				for (int k = i - 1; k >= 0; k--)
				{
					a[k + 1] = a[k];
				}
				a[j] = temp;
			}
		}
	}
}


void RandomArray(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		//a[i] = rand();
		a[i] = rand() / 100.;
	}

}

void DisplayArray(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void Swap(double& a, double& b)
{
	double t = a;
	a = b;
	b = t;
}


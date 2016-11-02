#include <iostream>
using namespace std;
void CountNumber(long long, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&);
void PrintMin(int, int, int, int, int, int, int, int, int, int);
void PrintMax(int, int, int, int, int, int, int, int, int, int);

int main()
{
	long long number;
	cout << "Enter number" << endl;
	cin >> number;
	int s0 = 0;
	int s1 = 0;
	int s2 = 0;
	int s3 = 0;
	int s4 = 0;
	int s5 = 0;
	int s6 = 0;
	int s7 = 0;
	int s8 = 0;
	int s9 = 0;

	CountNumber (number, s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
	PrintMin(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
	PrintMax(s0, s1, s2, s3, s4, s5, s6, s7, s8, s9);
	return 0;
}

void CountNumber(long long n, int& s0, int& s1, int& s2, int& s3, int& s4, int& s5, int& s6, int& s7, int& s8, int& s9)
{
	int d;
	while (n)
	{
		d = n % 10;
		switch (d)
		{
		case 0:
			s0++;
			break;
		case 1:
			s1++;
			break;
		case 2:
			s2++;
			break;
		case 3:
			s3++;
			break;
		case 4:
			s4++;
			break;
		case 5:
			s5++;
			break;
		case 6:
			s6++;
			break;
		case 7:
			s7++;
			break;
		case 8:
			s8++;
			break;
		case 9:
			s9++;
			break;
		}
		n /= 10;
	}
}

void PrintMin(int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8, int s9)
{
	if (s0 > 0)
		cout << "0 is the smallest number" << endl;
	else if (s1 > 0)
		cout << "1 is the smallest number" << endl;
	else if (s2 > 0)
		cout << "2 is the smallest number" << endl;
	else if (s3 > 0)
		cout << "3 is the smallest number" << endl;
	else if (s4 > 0)
		cout << "4 is the smallest number" << endl;
	else if (s5 > 0)
		cout << "5 is the smallest number" << endl;
	else if (s6 > 0)
		cout << "6 is the smallest number" << endl;
	else if (s7 > 0)
		cout << "7 is the smallest number" << endl;
	else if (s8 > 0)
		cout << "8 is the smallest number" << endl;
	else
		cout << "9 is the smallest number" << endl;
}

void PrintMax(int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8, int s9)
{
	if (s9 > 9)
		cout << "9 is the biggest number" << endl;
	else if (s8 > 0)
		cout << "8 is the biggest number" << endl;
	else if (s7 > 0)
		cout << "7 is the biggest number" << endl;
	else if (s6 > 0)
		cout << "6 is the biggest number" << endl;
	else if (s5 > 0)
		cout << "5 is the biggest number" << endl;
	else if (s4 > 0)
		cout << "4 is the biggest number" << endl;
	else if (s3> 0)
		cout << "3 is the biggest number" << endl;
	else if (s2 > 0)
		cout << "2 is the biggest number" << endl;
	else if (s1 > 0)
		cout << "1 is the biggest number" << endl;
	else
		cout << "0 is the biggest number" << endl;
}
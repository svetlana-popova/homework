#include <iostream>
using namespace std;
long long MakingReverse(long long);
bool IsPolindrom(long long);
void PrintAnswer(bool, long long);

int main()
{
	long long number;
	cout << "Enter number" << endl;
	cin >> number;
	bool answer = IsPolindrom(number);
	PrintAnswer(answer, number);
	return 0;
}


bool IsPolindrom(long long a)
{
	long long b = MakingReverse(a);
	return (a == b);
}

long long MakingReverse(long long x)
{
	int last;
	long long  sum = 0;
	while (x)
	{
		last = x % 10;
		sum = sum * 10 + last;
		x /= 10;
	}
	return sum;
}


void PrintAnswer(bool answer, long long n)
{
	if (answer)

		cout << n << " is polindrom" << endl;
	else
		cout << n << " is not polindrom" << endl;
}

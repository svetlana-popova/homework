#include <iostream>
#include <cmath>
using namespace std;
bool IsNumberSimple(long long);
void PrintAnswer(bool, long long);

int main()
{
	long long number;
	cout << "Enter number" << endl;
	cin >> number;
	bool SimpleNumber = IsNumberSimple(number);
	PrintAnswer(SimpleNumber, number);
	return 0;
}

bool IsNumberSimple(long long n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (!(n / i))
			return false;
		else
			return true;
	}
}

void PrintAnswer(bool answer, long long number)
{
	if (answer)
		cout << number << " is simple" << endl;
	else
		cout << number << " is not simple" << endl;
}

#include <iostream>
using namespace std;
void CheckNeighbNumber(long long, bool&, bool&, bool&);
void PrintTypeOfNumber(long long, bool, bool, bool);

int main()
{
	long long number;
	cout << "Enter number" << endl;
	cin >> number;
	bool incr = false;
	bool decr = false;
	bool eq = false;
	CheckNeighbNumber(number, incr, decr, eq);
	PrintTypeOfNumber(number, incr, decr, eq);
	return 0;
}

void CheckNeighbNumber(long long n, bool& incr, bool& decr, bool& eq)
{
	int next, prev;
	next = n % 10;
	while (n)
	{
		prev = n % 10;
		if (prev < next)
			incr = true;
		if (prev = next)
			eq = true;
		if (prev > next)
			decr = true;
		next = prev;
		n /= 10;
	}
}

void PrintTypeOfNumber(long long number, bool a, bool b, bool c)
{
	if (a && !b && !c)
		cout << number << "is strict increasing" << endl;

	if (!a && b && !c)
		cout << number << "is strict decreasing" << endl;

	if (!a && !b && c)
		cout << number << " is monotonous" << endl;

	if (a && !b && c)
		cout << number << " is unstrict increasing" << endl;

	if (!a && b && c)
		cout << number << " is unstrict decreasing" << endl;

	if (a && b && !c)
		cout << number << " is chaotic" << endl;

	if (a && b && c)
		cout << number << " is chaotic" << endl;
}

#include <iostream>
using namespace std;

double CountFactorial(int);

int main()
{
	int n;
	cout << "Enter number of factors" << endl;
	cin >> n;
	double x = CountFactorial(n);
	return 0;

}

double CountFactorial(int n)
{
	int x = 1;
	if (n == 1) return 1;
	else return x *= CountFactorial(n - 1);
}
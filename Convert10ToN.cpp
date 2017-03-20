#include <iostream>
#include < math.h > 
#include <string.h>
using namespace std;
char* Convert10ToN(double, int, int);
char* AllocateMemory(int);
void MakePolindrom(char*, char*);


int main()
{
	double n = 0.;
	cout << "Enter number to convert" << endl;
	cin >> n;
	int base = 0;
	cout << "Enter basis of the new number system (from 2 to 31)" << endl;
	while (true)
	{
		cin >> base;
		if (base >= 2 && base <= 31) break;
		cout << "Error! Enter basis of the new number system (from 2 to 31)" << endl;
	}

	int eps = 0;
	cout << "Enter accuracy" << endl;
	cin >> eps;
	char* t = Convert10ToN(n, base, eps);
	cout << t << endl;
	return 0;
}

char* Convert10ToN(double n, int base, int eps)
{
	short sign = 1;
	if (n < 0)
		sign = -1;
	n = fabs(n);
	int integer = (int)n;
	double fractional = n - integer;
	char *part1 = AllocateMemory(256);
	char* s = "0123456789ABCDEF";
	int remainder;
	int i = 0;
	for (; integer >= base; i++)
	{
		remainder = integer % base;
		part1[i] = s[remainder];
		integer /= base;

	}
	remainder = integer % base;
	part1[i] = s[remainder];
	part1[i + 1] = '\0';

	char* part2 = AllocateMemory(eps + 1);
	for (int i = 0; i < eps; i++)
	{
		fractional *= base;
		double countint;
		double countfract = modf(fractional, &countint);
		part2[i] = s[(int)countint];
		fractional = countfract;
	}
	part2[eps] = '\0';

	char* result = AllocateMemory(256);
	MakePolindrom(part1, result);
	strcat(result, ".");
	strcat(result, part2);
	if (sign == -1)
	{
		for (int i = strlen(result); i >= 0; i--)
			result[i + 1] = result[i];
		result[0] = '-';

	}
	delete[] part1;
	delete[] part2;
	return result;
}

char * AllocateMemory(int n)
{
	char* a = new char[n];
	for (int i = 0; i <= 0; i++)
		a[i] = ' ';
	return a;
}

void MakePolindrom(char a[], char temp[])
{
	int length = strlen(a);
	for (int j = 0; j < length; j++)
		temp[j] = a[length - 1 - j];
	temp[length] = '\0';

}
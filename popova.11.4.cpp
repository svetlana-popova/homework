#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "Enter your number (a < 100)" << endl;
	cin >> a;
	if (a < 1 || a > 99)
	{
		cout << "Input error" << endl;
		system("pause");
		return 0;
	}
	int dozen, unit;
	dozen = a / 10;
	unit = a % 10;

	if (a > 9 && a < 20)
	{
		switch (unit)
		{
		case 0: 
			cout << "ten" << endl;
			break;
		case 1:
			cout << "eleven" << endl;
			break;
		case 2:
			cout << "twelve" << endl;
			break;
		case 3:
			cout << "thirteen" << endl;
			break;
		case 4:
			cout << "fourteen" << endl;
			break;
		case 5:
			cout << "fifteen" << endl;
			break;
		case 6:
			cout << "sixteen" << endl;
			break;
		case 7:
			cout << "seventeen" << endl;
			break;
		case 8:
			cout << "eighteen" << endl;
			break;
		case 9:
			cout << "nineteen" << endl;
			break;
		}
	}
	if (a < 9 || a > 20)
	{
		switch (dozen)
		{
		case 0:
			cout << ' ';
			break;
		case 2:
			cout << "twenty ";
			break;
		case 3:
			cout << "thirty ";
			break;
		case 4:
			cout << "fourty ";
			break;
		case 5:
			cout << "fifty ";
			break;
		case 6:
			cout << "sixty ";
			break;
		case 7:
			cout << "seventy ";
			break;
		case 8:
			cout << "eighty ";
			break;
		case 9:
			cout << "ninety ";
			break;
		}

		switch (unit)
		{
		case 0:
			cout << " " << endl;
			break;
		case 1:
			cout << "one" << endl;
			break;
		case 2:
			cout << "two" << endl;
			break;
		case 3:
			cout << "three" << endl;
			break;
		case 4:
			cout << "four" << endl;
			break;
		case 5:
			cout << "five" << endl;
			break;
		case 6:
			cout << "six" << endl;
			break;
		case 7:
			cout << "seven" << endl;
			break;
		case 8:
			cout << "eight" << endl;
			break;
		case 9:
			cout << "nine" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
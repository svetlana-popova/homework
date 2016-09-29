#include <iostream>
using namespace std;

int main()
{
	cout << "Welcome to calculator!" << endl << "If you want to add numbers, enter + " << endl;
	cout << "If you want to subtract numbers, enter - " << endl;
	cout << "If you want to multiply, enter * or . " << endl;
	cout << "If you want to devide, enter / or : " << endl;

	cout << "Enter numbers" << endl;
	double a, b;

	cout << "a: " << endl;
	cin >> a;
	cout << "b: " << endl;
	cin >> b;

	char op;
	cout << "Enter operation" << endl;
	cin >> op;
	double c;
	bool ok = true;
	switch (op)
	{
	case '*':
	case '.':
		c = a * b;
		break;
	case '-':
		c = a - b;
		break;
	case '+':
		c = a + b;
		break;
	case '/':
	case ':':
		if (b == 0)
			ok = false;
		else
			c = a / b;
		break;
	default:
		ok = false;
		break;
	}
	if (ok == true)
		cout << a << ' ' << op << ' ' << b << " = " << c << endl;
	else
		cout << "Input error" << endl;
	system("pause");
	return 0;
}
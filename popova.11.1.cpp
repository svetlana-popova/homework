#include <iostream>
using namespace std;

int main()
{
	double a, b, c;
	cout << "Enter coeff." << endl;
	cout << "a: ";
	cin >> a;
	if (a == 0)
	{
		cout << "Input error" << endl;
		system("pause");
		return 0;
	}
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;

	if (a == 1 && b == 0 && c == 0)
		cout << "x ^ 2 = 0" << endl;
	else
		if (a == -1 && b == 0 && c == 0)
			cout << "-x ^ 2 = 0" << endl;
		else if (a == 1 && b == 1 && c == 0)
			cout << "x ^ 2 + x = 0" << endl;
			else if (a == -1 && b == 1 && c == 0)
			cout << "-x ^ 2 + x = 0" << endl;
			else if (a == 1 && b == 1)
				cout << "x ^ 2 + x + " << c << " = 0" << endl;
				else if (a == -1 && b == 1)
				cout << "-x ^ 2 + x + " << c << " = 0" << endl;
					else if (a == 1 && b == 0)
					cout << "x ^ 2 + " << c << " = 0" << endl;
						else if (a == -1 && b == 0)
							cout << "-x ^ 2 + " << c << " = 0" << endl;
							else if (a == 1 && c == 0)
								cout << "x ^ 2 + " << b << " * x = 0" << endl;
								else if (a == -1 && c == 0)
								cout << "-x ^ 2 + " << b << " * x = 0" << endl;
									else if (b == 1 && c == 0)
									cout << a << "x ^ 2 + x = 0" << endl;
										else if (b == 0 && c == 0)
										cout << a << "x ^ 2 = 0" << endl;
											else if (a == 1)
											cout << "x ^ 2 + " << b << " * x + " << c << " = 0" << endl;
												else if (a == -1)
												cout << "-x ^ 2 + " << b << " * x + " << c << " = 0" << endl;
													else if (b == 1)
													cout << a << "x ^ 2 + x + " << c << " = 0" << endl; 
														else if (b == 0)
														cout << a << "x ^ 2 + " << c << " = 0" << endl;
															else if (c == 0)
															cout << a << "x ^ 2 + x = 0" << endl;
																else 
																cout << a << "x ^ 2 + " << b << " * x + " << c << " = 0" << endl;	
			double d = b * b - 4 * a * c;

			if (d < 0)
			{
				cout << "No roots" << endl;
			}
			else if (d == 0)
			{
				cout << "x1 = x2 = " << -b / 2 / a << endl;
			}
			else
			{
				cout << "x1 = " << (-b + sqrt(d)) / 2 / a << endl;
				cout << "x2 = " << (-b - sqrt(d)) / 2 / a << endl;
			}
		system("pause");
		return 0;
}
	
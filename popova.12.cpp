#include <iostream>
using namespace std;
int main()
{
	int n;
	while (true)
	{
		cout << "Enter n (n > 0)" << endl;
		cin >> n;
		if (n > 0) break;
		cout << "Input error!" << endl;
		system("pause");
		system("cls");
	}
	

	int selector;
	
	while (true)
	{
		cout << "To count the first expression enter 1" << endl;
		cout << "To count the second expression enter 2" << endl;
		cout << "To count the third expression enter 3" << endl;
		cin >> selector;
		if (selector >= 1 && selector <= 3) break;
		cout << "Input error!" << endl;
		system("pause");
		system("cls");
	}

	int i = 1;
	double sum = 0;
	int mp = 1;
	switch (selector)
	{
	case 1:
		
		for (; i <= n; i++)
		{
			mp *= i;
			}
		cout << "Product is " << mp << endl;
		break;
	case 2:
		
		for (; i <= n; i++)
		{
			sum += (float)1 / i;
			}
		cout << "Sum is " << sum << endl;
		break;
	case 3:
		sum = pow(2, n);
		cout << "Sum is " << sum << endl;
		break;
	}
	
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;
int main()
{
	cout << "To choose the first area, enter 1" << endl;
	cout << "To choose the second area, enter 2" << endl;
	cout << "To choose the third area, enter 3" << endl;


	int op;
	cin >> op;

	double x, y;
	cout << "Coordinates of point" << endl;
	cin >> x;
	cin >> y;
	bool condition;


	switch (op)
	{
	case 1: 
		condition = (pow(x - 1, 2) + y * y) <= 1 && y >= -0.5 && y <= x;
		break;

	case 2: 
		condition = ((x * x + y * y) <= 1 && x >= 0 && x <= 1 && y >= 0 && y <= 1) || (x >= -1 && x <= 0 && y >= -1 && y <= 0);
		break;
	case 3: 
		condition = (x * x + y * y) <= 1 && y <= x + 1 && x + 1 >= -y;
		break;
	default: 
		cout << "Input error";
		return 0;

	}
	if (condition)
		cout << "The point is in the area" << endl;
	else
		cout << "The point is not in the area" << endl;
	system("pause");
	return 0;
}

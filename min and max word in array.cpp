#include <iostream>
#include "matrix.h"
using namespace std;


int main()
{
	const int M = 265;
	const int N = 265;
	char text[N] = "";
	cout << "Enter text" << endl;
	cin.getline(text, N, '\n');
	int tmp[N] = { 0 };
	char array[][M] = { "" };
	int k = 0;
	ObtainArrayOfWords(text, array, k, tmp);
	DisplayArray(tmp, k);
	int min = Min(tmp, k);
	int max = Max(tmp, k);
	//how convert into words? 
}


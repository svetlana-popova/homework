#pragma once
using namespace std;
const int m = 265;
const int n = 265;

bool IsAlphabet(char ch)//проверяет, входит ли символ в алфавит
{
	if (ch >= 'a' && ch <= 'z' || ch >= 'a' && ch <= 'z')
		return true;
	else
		return false;
}

int StrLength(char str[]) //вычисляет длину строки до enter
{
	int length = 0;
	while (str[length])
		length++;

	return length;
}

int ToCompare(char a[], char b[]) //сравнить, какая из строк больше
{
	int i = 0;
	while (a[i] && b[i])
	{
		if (a[i] == b[i]) i++;
		else return (a[i] - b[i]);
	}
	if (!a[i]) return -1;
	else if (!b[i]) return 1;
	else return 0;
}

void CopyString(char a[], char b[]) //скопировать вторую строку в первую
{
	a = "";
	int l2 = StrLength(b);
	for (int i = 0; i < l2; i++)
		a[i] = b[i];
}

void EnterMatrix(int matrix[][m], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "[" << (i + 1) << "][" << (j + 1) << "] = ";
			cin >> matrix[i][j];
		}
	}
}

void DisplayMatrix(int matrix[][m], int n, int m)
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void DisplayWordArray(char array[][m], int m)
{

		for (int j = 0; j < m; j++)
		{
			cout.width(10);
			cout << array[j];
		}
		cout << endl;
	
}



int Max(int a[], int n)
{
	k = 0;
	for (int i = 0; i < n; i++)
	{
			if (a[k] < a[i])
			{
				k = i;
			}
		}
	return k;
	}

int Min(int a[], int n)
{
	k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[k] > a[i])
		{
			k = i;
		}
	} return k;
}


void MaxiInMatrix(int matrix[][m], int n, int m, int& k, int& l)
{
	k = 0, l = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[k][l] < matrix[i][j])
			{
				k = i;
				l = j;
			}
		}
	}
}

void MinInMatrix(int matrix[][m], int n, int m, int& k, int& l)
{
	k = 0, l = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[k][l] > matrix[i][j])
			{
				k = i;
				l = j;
			}
		}
	}
}
void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void TransposeMatrix(int matrix[][m], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}



void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
				{
			cout << a[i] << " " << endl;
		}
	}
}

void ColumnReverse(int matrix[][m], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			swap(matrix[i][j], matrix[i][m - j - 1]);
		}
	}
}

void RandomMatrix(int matrix[][m], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
}

void ObtainArrayOfWords(char s[], char a[][m], int& k, int tmp[])
{
	bool flag = false;
	int i = -1, j = 0;
	k = 0;
	while (s[++i])
	{
		if (IsAlphabet(s[i]))
			flag = true;
		a[k][j] = s[i];
		j++;
		continue;
	}
	if (flag)
	{
		flag = false;
		tmp[k] = j;
		k++;
		j = 0;
	}
}

void BubbleSortWords(char a[][m], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j > i; j--)
		{
			if (ToCompare(a[j], a[j - 1]) < 0)
			{
				char tmp[m] = "";
				CopyString(tmp, a[j]);
				CopyString(a[j], a[j - 1]);
				CopyString(a[j - 1], tmp);
			}
		}
	}
}

bool IsPolindrom(char a[]) //является ли строка полиндромом
{
	int length = StrLength(a);
	int i = 0, j = 0;
	for (; i < length / 2; i++)
	{
		if (a[i] == a[length - i - 1])
			j++;
	}
	if (j == i)
		return true;
	else
		return false;
}

bool IsVowel(char l) //является ли буква гласной
{
	char vowels[13] = { "aaeeiioouuyy" };
	for (int i = 0; i <= 12; i++)
	{
		if (l == vowels[i])
		{
			return true;
		}

	}
	return false;
}

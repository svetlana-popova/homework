#pragma once


int StrLength(char str[]) //вычисляет длину строки до Enter
{
	int length = 0;
	while (str[length])
		length++;

	return length;
}




bool IsAlphabet(char ch)//проверяет, входит ли символ в алфавит
{
	if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
		return true;
	else
		return false;
}





bool IsAllAlphabet(char str[]) //проверяет, все ли символы в строке из адфавита
{
	int length = StrLength(str);
	bool ok = true;
	int i = 0;
	for (; i < length; i++)
	{
		ok = IsAlphabet(str[i]);
		if (!ok)
		{
			ok = false;
			return ok;
		}
	}
	return ok;
}






void ToUpper(char& ch) //перевод в верхний регистр
{
	if (ch >= 'a' && ch <= 'z')
		ch -= 32;
}






void ToUpper(char str[])      //перевод в верхний регистр всех маленьких символов в строке
{
	int i = 0;
	while (str[i])
	{
		ToUpper(str[i]);
		i++;
	}
}




int ToCompare(char a[], char b[]) //Сравнить, какая из строк больше
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



bool IsEquals(char a[], char b[]) //Узнать, равны ли строки
{
	int L1 = StrLength(a);
	int L2 = StrLength(b);
	if (L1 != L2) return false;
	for (int i = 0; i < L1; i++)
		if (a[i] != b[i]) return false;
	return true;
}



void CopyString(char a[], char b[]) //Скопировать вторую строку в первую
{
	a = "";
	int L2 = StrLength(b);
	for (int i = 0; i < L2; i++)
		a[i] = b[i];
}


void MakePolindrom(char a[], char temp[]) //Сделать из строки перевертыш
{
	int length = StrLength(a);
	for (int j = 0; j < length; j++)
		temp[j] = a[length - 1 - j];

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


int ToFindLetter(char str[], char l, int a[]) //найти индекс буквы в строке
{
	int length = StrLength(str);
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == l)
		{
			a[j] = i + 1;
			j++;
		}
	}
	return j;

}




bool IsVowel(char l) //является ли буква гласной
{
	char vowels[13] = { "aAeEiIoOuUyY" };
	for (int i = 0; i <= 12; i++)
	{
		if (l == vowels[i])
		{
			return true;
		}

	}
	return false;
}



#include <iostream>
#include <string.h>
using namespace std;
void DeleteSubString(char*, const char*);
char* AllocateMemory(int);

int main()
{
	const int N = 256;
	char* source = AllocateMemory(N);
	cout << "Enter full string " << endl;
	cin.getline(source, N, '\0');
	char* toDelete = AllocateMemory(N);
	cout << "Enter word to delete" << endl;
	cin.getline(toDelete, N, '\0');
	DeleteSubString(source, toDelete);
	cout << source << endl;
	delete[] source;
	delete[] toDelete;
}

char* AllocateMemory(int n)
{
	char* a = new char[n];
	for (int i = 0; i <= 0; i++)
		a[i] = ' ';
	return a;
}

void DeleteSubString(char* source, const char* sub)
{
	int l = strlen(sub);
	char* p = strstr(source, sub);
	while (p)
	{
		strcpy(p, p + l);
		p = strstr(p, sub);
	}

}
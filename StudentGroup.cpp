#include "StudentGroup.h"
#include "Student.h"


Student InitStudent()
{
	char firstName[N] = "", lastName[N] = "", faculty[N] = "";
	cout << "Enter first name: ";
	cin.ignore();
	cin.get(firstName, N, '\n');
	cout << "Enter second name: ";
	cin.ignore();
	cin.get(lastName, N, '\n');
	cout << "Enter Faculty: ";
	cin.ignore();
	cin.get(faculty, N, '\n');
	cout << "Enter array of marks: ";
	int marks[M];
	EnterArray(marks, M);
	Student student;
	student.SetStudent(firstName, lastName, faculty, marks);
	return student;
}

Student* InitGroup(int n)
{
	Student* students = new Student[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the information about " << (i + 1) << " Student";
		students[i] = InitStudent();
	}
	return students;
}

void EnterArray(int* marks, int n)
{
	for (int i = 0; i < M; i++)
	{
		cout << "enter A[" << (i + 1) << "] = ";
		cin >> marks[i];
	}
}

void DisplayGroup(Student* students, int n)
{
	for (int i = 0; i < n; i++)
		students[i].DisplayStudent();
	cout << endl;
}

void DisplayChoise(Student* students, int n, char* faculty, double lowMark, double upperMark)
{
	for (int i = 0; i < n; i++)
		if (!strcmp(students[i].GetFaculty(), faculty) && students[i].GetMiddleMark()
			<= upperMark  &&  students[i].GetMiddleMark() >= lowMark)
			students[i].DisplayStudent();
}

void SortFirstName(Student* students, int n)
{
	for (int i = 0; i <= n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(students[j].GetFirstName(), students[j - 1].GetFirstName()) < 0)
				Swap(students[j], students[j - 1]);
}

void Swap(Student &a, Student &b)
{
	Student help = a;
	a = b;
	b = help;
}
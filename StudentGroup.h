#pragma once
#include <iostream>
#include "Student.h"
using namespace std;
#include <string.h>
const int N = 25;
const int M = 5;


class StudentGroup
{
private:
	Student Group[N];
	void Swap(Student&, Student&);
public:
	StudentGroup() {};
	Student InitStudent();
	Student* InitGroup(int);
	void DisplayGroup(Student*, int);
	void DisplayChoise(Student*, int, char*, double, double);
	void SortFirstName(Student*, int);
	void EnterArray(int*, int);

}; 
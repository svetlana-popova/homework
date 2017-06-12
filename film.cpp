#include <iostream>
#include <fstream>
#include "string.h"
#include "film.h"
using namespace std;

Film::Film()
{
	
}

Film::Film(char* n, char* dn, char* dln, int y, char* c, float cos, float in)
{
	SetFilm(n, dn, dln, y, c, cos, in);
}

Film::~Film()
{
	
}

void Film::SetName(char* n)
{
	strcpy(Name, n);
}

void Film::SetDirectorName(char* dn)
{
	strcpy(DirectorName, dn);
}

void Film::SetDirectorLastName(char* dln)
{
	strcpy(DirectorLastName, dln);
}

void Film::SetYear(int y)
{
	if (y > 1900 && y <= 2017)
		Year = y;
	else
		cout << "Input error" << endl;
}

void Film::SetCountry(char* c)
{
	strcpy(Country, c);
}

void Film::SetCost(float cos)
{
	if (cos > 0)
		Cost = cos;
	else
		cout << "Input error" << endl;
}

void Film::SetIncome(float in)
{
	if (in > 0)
		Income = in;
	else
		cout << "Input error" << endl;
}

void Film::CountBenefit()
{
	Benefit = Income - Cost;
}

void Film::SetFilm(char* n, char* dn, char* dln, int y, char* c, float cos, float in)
{
	SetName(n);
	SetDirectorName(dn);
	SetDirectorLastName(dln);
	SetYear(y);
	SetCountry(c);
	SetCost(cos);
	SetIncome(in);
	CountBenefit();
}

char* Film::GetName()
{
	return Name;
}

char* Film::GetDirectorName()
{
	return DirectorName;
}

char* Film::GetDirectorLastName()
{
	return DirectorLastName;
}

int Film::GetYear()
{
	return Year;
}

char* Film::GetCountry()
{
	return Country;
}

float Film::GetCost()
{
	return Cost;
}

float Film::GetIncome()
{
	return Income;
}

float Film::GetBenefit()
{
	return Benefit;
}

void Film::DisplayFilm()
{
	cout << "Name: " << Name << endl;
	cout << "Director: " << DirectorName << " " << DirectorLastName << endl;
	cout << "Year of production: " << Year << endl;
	cout << "Country: " << Country << endl;
	cout << "Cost: " << Cost << " $" << endl;
	cout << "Income: " << Income << " $" << endl;
	cout << "Benefit: " << Benefit << " $" << endl;
}

void Film::FillFilmFromConsol()
{
	char Name[N] = " ";
	cout << "\nEnter title of the film: ";
	cin.get(Name, N, '\n');
	char DirectorName[N] = " ";
	cout << "\nEnter director's name: ";
	cin.ignore();
	cin.get(DirectorName, N, '\n');
	char DirectorLastName[N] = " ";
	cout << "\nEnter director's last name: ";
	cin.ignore();
	cin.get(DirectorLastName, N, '\n');
	int Year = 0;
	cout << "\nEnter year of production: ";
	cin.ignore();
	cin >> Year;
	char Country[N] = " ";
	cout << "\nEnter country: ";
	cin.ignore();
	cin.get(Country, N, '\n');
	float Cost = 0.0;
	cout << "\nEnter cost of the film($): ";
	cin.ignore();
	cin >> Cost;
	float Income = 0.0;
	cout << "\nEnter income of the film($): ";
	cin.ignore();
	cin >> Income;
	cin.ignore();
	this -> SetFilm(Name, DirectorName, DirectorLastName, Year, Country, Cost, Income);
}

void Film::WriteFilmToFile(char* FileName)
{
	ofstream out;
	out.open(FileName, ios::app);
	if (!out.is_open())
	{
		cout << " Cannot open file " << FileName << endl;
	}
	out << Name << "\n";
	out << DirectorName << " ";
	out << DirectorLastName << "\n";
	out << Year << "\n";
	out << Country << "\n";
	out << Cost << "\n";
	out << Income << "\n";
	out << Benefit << "\n";
	out.close();
}

void Film::FillFilmFromFile(char* FileName)
{
	ifstream in;
	in.open(FileName);
	if (!in.is_open())
	{
		cout << " Cannot open file " << FileName << endl;
	}
	in.getline (Name, N, '\n');
	in.getline(DirectorName, N, '\n');
	in.getline (DirectorLastName, N, '\n');
	in >> Year;
	in.getline(Country, N, '\n');
	in >> Cost;
	in >> Income;
	in >> Benefit;
	in.close();
}
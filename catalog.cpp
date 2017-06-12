#include <iostream>
#include <fstream>
#include "string.h"
#include "film.h"
#include "catalog.h"
using namespace std;

Catalog::Catalog() 
{
	Film ArrayOfFilms[N];
	SetCatalog(0);

}
Catalog::Catalog(int number)
{
	Film ArrayOfFilms[N];
	NumberOfElements = number;
	for (int i = 0; i < number; i++)
		SetCatalog(i);
	cout << "Catalog is created ("  << number << ")" << endl;
	
}

Catalog::~Catalog()
{
	
}

void Catalog::FillCatalog(int number)
{
	NumberOfElements = number;
	for (int i = 0; i < NumberOfElements; i++)
		ArrayOfFilms[i].FillFilmFromConsol();
}

void Catalog::SetDefaultElementOfCatalog(int number)
{
	SetCatalog(number - 1);
}

void Catalog::FillElementOfCatalogFromConsol(int number)
{
	ArrayOfFilms[number - 1].FillFilmFromConsol();
}

Film* Catalog::GetCatalog()
{
	return ArrayOfFilms;
}

Film Catalog::GetElementOfCatalog(int number)
{
	return ArrayOfFilms[number - 1];
}

void Catalog::SetCatalog(int i)
{
	ArrayOfFilms[i].SetName("");
	ArrayOfFilms[i].SetDirectorName("");
	ArrayOfFilms[i].SetDirectorLastName("");
	ArrayOfFilms[i].SetYear(1901);
	ArrayOfFilms[i].SetCountry("");
	ArrayOfFilms[i].SetCost(1.0);
	ArrayOfFilms[i].SetIncome(1.1);
	ArrayOfFilms[i].CountBenefit();
}

void Catalog::DisplayCatalog()
{
	for (int i = 0; i < NumberOfElements; i++)
	{
		cout << "Number of element: " << i + 1 << endl;
		ArrayOfFilms[i].DisplayFilm();
	}
}

void Catalog::Swap(Film &a, Film &b)
{
	Film help = a;
	a = b;
	b = help;
}

void Catalog::SortName()
{
	for (int i = 0; i <= NumberOfElements; i++)
		for (int j = NumberOfElements - 1; j > i; j--)
			if (strcmp(ArrayOfFilms[j].GetName(), ArrayOfFilms[j - 1].GetName()) < 0)
				Swap(ArrayOfFilms[j], ArrayOfFilms[j - 1]);
}

void Catalog::SortBenefit()
{
	for (int i = 0; i <= NumberOfElements; i++)
		for (int j = NumberOfElements - 1; j > i; j--)
			if (ArrayOfFilms[j].GetBenefit() - ArrayOfFilms[j - 1].GetBenefit() < 0)
				Swap(ArrayOfFilms[j], ArrayOfFilms[j - 1]);
}

void Catalog::ChooseByYear(int min, int max)
{
	for (int i = 0; i < NumberOfElements; i++)
	{
		if (ArrayOfFilms[i].GetYear() >= min && ArrayOfFilms[i].GetYear() <= max)
			ArrayOfFilms[i].DisplayFilm();
	}
}

void Catalog::WriteCatalogToFile(char* FileName)
{
	ofstream out;
	out.open(FileName);
	if (!out.is_open())
	{
		cout << " Cannot open file " << FileName << endl;
	}
	out << NumberOfElements << '\n';
	for (int i = 0; i < NumberOfElements; i++)
		ArrayOfFilms[i].WriteFilmToFile(FileName);
}

void Catalog::FillCatalogFromFile(char* FileName)
{
	ifstream in;
	in.open(FileName);
	if (!in.is_open())
	{
		cout << " Cannot open file " << FileName << endl;
	}
	in >> NumberOfElements;
	for (int i = 0; i < NumberOfElements; i++)
		ArrayOfFilms[i].FillFilmFromFile(FileName);
}
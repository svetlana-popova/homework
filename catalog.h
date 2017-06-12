#pragma once
#include "film.h"

class Catalog 
{
private: 
	Film ArrayOfFilms[N];
	int NumberOfElements;
	void Swap(Film&, Film&);
public:
	Catalog();
	Catalog(int);
	~Catalog();
	void SetCatalog(int);
	void FillCatalog(int);
	void SetDefaultElementOfCatalog(int);
	void FillElementOfCatalogFromConsol(int);
	Film* GetCatalog();
	Film GetElementOfCatalog(int);
	void DisplayCatalog();
	void SortName();
	void SortBenefit();
	void ChooseByYear(int, int);
	void WriteCatalogToFile(char*);
	void FillCatalogFromFile(char*);
};
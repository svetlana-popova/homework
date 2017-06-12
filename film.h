#pragma once

const int N = 25;



class Film
{
public:
	Film();
	Film(char*, char*, char*, int, char*, float, float);
	~Film();
	void SetName(char*);
	void SetDirectorName(char*);
	void SetDirectorLastName(char*);
	void SetYear(int);
	void SetCountry(char*);
	void SetCost(float);
	void SetIncome(float);
	void SetFilm(char*, char*, char*, int, char*, float, float);
	char* GetName();
	char* GetDirectorName();
	char* GetDirectorLastName();
	int GetYear();
	char* GetCountry();
	float GetCost();
	float GetIncome();
	float GetBenefit();
	void DisplayFilm();
	void CountBenefit();
	void FillFilmFromConsol();
	void WriteFilmToFile(char*);
	void FillFilmFromFile(char*);

private:
	char Name[N];
	char DirectorName[N];
	char DirectorLastName[N];
	int Year;
	char Country[N];
	float Cost;
	float Income;
	float Benefit;
	
};


#pragma once
#include<vector>

using namespace std;

class Macierz
{
public:
	Macierz(int, int);
	//~Macierz();
	Macierz operator+(Macierz &);
	Macierz operator-(Macierz &);
	Macierz operator*(Macierz &);
	void transponuj();
	void wyznaczOdwrotna();
	void wyswietlMacierz();
	int zwrocWymiarX();
	int zwrocWymiarY();
private:
	void wpiszDane();
	bool czyZgodneWymiary(char, int, int, int, int);
	vector<vector<float>> daneMacierzy;
	int wymiarX = 0;
	int wymiarY = 0;
};
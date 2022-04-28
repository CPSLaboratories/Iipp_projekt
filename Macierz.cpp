#include "Macierz.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
//Do zrobienia:
//1 - przerobiæ na szablony
//2 - dorobiæ try catch
//3 - dorobiæ throw exception
	
//public
Macierz::Macierz(int tempWymiarX, int tempWymiarY)
{
	Macierz::wymiarX = tempWymiarX;
	Macierz::wymiarY = tempWymiarY;
	Macierz::wpiszDane();
}

Macierz Macierz::operator+(Macierz & skladnik)
{
	if ((Macierz::zwrocWymiarX() == skladnik.zwrocWymiarX()) && (Macierz::zwrocWymiarY() == skladnik.zwrocWymiarY()))
	{
		for (int i = 0; i < Macierz::zwrocWymiarY(); i++)
		{
			for (int k = 0; k < Macierz::zwrocWymiarX(); k++)
			{
				skladnik.daneMacierzy[i][k] += Macierz::daneMacierzy[i][k];
			}
		}
	}
	else
	{
		cout << "\nNie mo¿na wykonaæ operacji. Niezgodne wymiary.\n";
	}
	return skladnik;
}

Macierz Macierz::operator-(Macierz& skladnik)
{
	if ((Macierz::zwrocWymiarX() == skladnik.zwrocWymiarX()) && (Macierz::zwrocWymiarY() == skladnik.zwrocWymiarY()))
	{
		for (int i = 0; i < Macierz::zwrocWymiarY(); i++)
		{
			for (int k = 0; k < Macierz::zwrocWymiarX(); k++)
			{
				skladnik.daneMacierzy[i][k] -= Macierz::daneMacierzy[i][k];
			}
		}
	}
	else
	{
		cout << "\nNie mo¿na wykonaæ operacji. Niezgodne wymiary.\n";
	}
	return skladnik;
}

Macierz Macierz::operator*(Macierz& skladnik)
{
	if ((Macierz::zwrocWymiarX() == skladnik.zwrocWymiarY()))
	{
		vector<vector<float>> wynik;
		for (int i = 0; i < skladnik.zwrocWymiarX(); i++)
		{	
			vector<float> tempWiersz;
			tempWiersz.clear();

			for (int k = 0; k < Macierz::zwrocWymiarY(); k++)
			{
				float tempVar = 0;

				for (int l = 0; l < skladnik.zwrocWymiarY(); l++)
				{
					tempVar += skladnik.daneMacierzy[l][i] * Macierz::daneMacierzy[k][l];
				}

				tempWiersz.push_back(tempVar);
			}

			wynik.push_back(tempWiersz);
		}
		skladnik.daneMacierzy = wynik;
		skladnik.transponuj();
	}
	else
	{
		cout << "\nNie mo¿na wykonaæ operacji. Niezgodne wymiary.\n";
	}
	return skladnik;
}

void Macierz::transponuj()
{
	for (int i = 0; i < Macierz::zwrocWymiarX(); ++i)
	{
		for (int k = i+1; k < Macierz::zwrocWymiarY(); ++k)
		{
			swap(Macierz::daneMacierzy[k][i], Macierz::daneMacierzy[i][k]);
		}
	}
}

void Macierz::wyznaczOdwrotna()
{
	if ((Macierz::zwrocWymiarX() == 2) && (Macierz::zwrocWymiarY() == 2))
	{
		float wyznacznik = Macierz::daneMacierzy[0][0] * Macierz::daneMacierzy[1][1] - Macierz::daneMacierzy[1][0] * Macierz::daneMacierzy[0][1];
		if (!((wyznacznik < 0.0001) && (wyznacznik > -0.0001)))
		{
			float a = Macierz::daneMacierzy[0][0];
			float b = Macierz::daneMacierzy[0][1];
			float c = Macierz::daneMacierzy[1][0];
			float d = Macierz::daneMacierzy[1][1];
			Macierz::daneMacierzy[0][0] = (1 / wyznacznik) * d;
			Macierz::daneMacierzy[0][1] = (1 / wyznacznik) * (-b);
			Macierz::daneMacierzy[1][0] = (1 / wyznacznik) * (-c);
			Macierz::daneMacierzy[1][1] = (1 / wyznacznik) * a;
		}
		else
		{
			cout << "\nNie mo¿na wykonaæ operacji. Wyznacznik macierzy wynosi 0.\n";
		}
	}

	else if ((Macierz::zwrocWymiarX() == 3) && (Macierz::zwrocWymiarY() == 3))
	{
		float a11 = Macierz::daneMacierzy[0][0];
		float a12 = Macierz::daneMacierzy[0][1];
		float a13 = Macierz::daneMacierzy[0][2];

		float a21 = Macierz::daneMacierzy[1][0];
		float a22 = Macierz::daneMacierzy[1][1];
		float a23 = Macierz::daneMacierzy[1][2];

		float a31 = Macierz::daneMacierzy[2][0];
		float a32 = Macierz::daneMacierzy[2][1];
		float a33 = Macierz::daneMacierzy[2][2];

		float wyznacznik = (a11*a22*a33) + (a12*a23*a31) + (a21*a32*a13) - (a13*a22*a31) - (a11*a32*a23) - (a21*a12*a33);

		if (!((wyznacznik < 0.0001) && (wyznacznik > -0.0001)))
		{
			Macierz::daneMacierzy[0][0] = (1 / wyznacznik) * ((a22 * a33) - (a23 * a32));
			Macierz::daneMacierzy[0][1] = (1 / wyznacznik) * ((a13 * a32) - (a12 * a33));
			Macierz::daneMacierzy[0][2] = (1 / wyznacznik) * ((a12 * a23) - (a13 * a22));

			Macierz::daneMacierzy[1][0] = (1 / wyznacznik) * ((a23 * a31) - (a21 * a33));
			Macierz::daneMacierzy[1][1] = (1 / wyznacznik) * ((a11 * a33) - (a13 * a31));
			Macierz::daneMacierzy[1][2] = (1 / wyznacznik) * ((a13 * a21) - (a11 * a23));

			Macierz::daneMacierzy[2][0] = (1 / wyznacznik) * ((a21 * a32) - (a22 * a31));
			Macierz::daneMacierzy[2][1] = (1 / wyznacznik) * ((a12 * a31) - (a11 * a32));
			Macierz::daneMacierzy[2][2] = (1 / wyznacznik) * ((a11 * a22) - (a12 * a21));
		}
	}
	else
	{
		cout << "\nNie mo¿na wykonaæ operacji. Niezgodne wymiary.\n";
	}
}

int Macierz::zwrocWymiarX() //Zwraca szerokoœæ macierzy
{
	return Macierz::wymiarX;
}

int Macierz::zwrocWymiarY() //Zwraca wysokoœæ macierzy
{
	return Macierz::wymiarY;
}

void Macierz::wyswietlMacierz() //Wypisanie zawartoœci macierzy w konsoli
{
	string tempMessage = "";
	for (auto & elem : Macierz::daneMacierzy)
	{
		tempMessage = "";
		for (auto& insideElem : elem)
		{
			tempMessage += " ";
			tempMessage += to_string(insideElem);
		}
		cout << tempMessage << "\n\n";
	}
}

void Macierz::wpiszDane() //Metoda pozwalaj¹ca na wpisanie danych do macierzy przez u¿ytkownika
{
	vector<float> temp;
	float tempVar;

	for (int i = 0; i < Macierz::zwrocWymiarY(); i++)
	{
		temp.clear();
		for (int k = 0; k < Macierz::zwrocWymiarX(); k++)
		{
			cin >> tempVar;
			temp.push_back(tempVar);
		}
		Macierz::daneMacierzy.push_back(temp);
		cout << "\n";
	}
}


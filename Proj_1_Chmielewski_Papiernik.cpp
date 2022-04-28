#include <iostream>
#include <vector>
#include "Macierz.h"

using namespace std;

void Dodawanie()
{
	int rozmiarX1;
	int rozmiarY1;
	int rozmiarX2;
	int rozmiarY2;

	cout << "\nPodaj wymiar X pierwszej macierzy:\n";
	cin >> rozmiarX1;
	cout << "\nPodaj wymiar Y pierwszej macierzy:\n";
	cin >> rozmiarY1;

	cout << "\nWprowadz wartosci pierwszej macierzy:\n";
	Macierz macierz1 = Macierz(rozmiarX1, rozmiarY1);
	macierz1.wyswietlMacierz();

	cout << "\nPodaj wymiar X drugiej macierzy:\n";
	cin >> rozmiarX2;
	cout << "\nPodaj wymiar Y drugiej macierzy:\n";
	cin >> rozmiarY2;

	cout << "\nWprowadz wartosci drugiej macierzy:\n";
	Macierz macierz2 = Macierz(rozmiarX2, rozmiarY2);
	macierz2.wyswietlMacierz();

	Macierz suma = macierz1 + macierz2;
	cout << "\nWynik:\n";
	suma.wyswietlMacierz();
}

void Odejmowanie()
{
	int rozmiarX1;
	int rozmiarY1;
	int rozmiarX2;
	int rozmiarY2;

	cout << "\nPodaj wymiar X pierwszej macierzy:\n";
	cin >> rozmiarX1;
	cout << "\nPodaj wymiar Y pierwszej macierzy:\n";
	cin >> rozmiarY1;

	cout << "\nWprowadz wartosci pierwszej macierzy:\n";
	Macierz macierz1 = Macierz(rozmiarX1, rozmiarY1);
	cout << "\nUtworzona macierz:\n";
	macierz1.wyswietlMacierz();

	cout << "\nPodaj wymiar X drugiej macierzy:\n";
	cin >> rozmiarX2;
	cout << "\nPodaj wymiar Y drugiej macierzy:\n";
	cin >> rozmiarY2;

	cout << "\nWprowadz wartosci drugiej macierzy:\n";
	Macierz macierz2 = Macierz(rozmiarX2, rozmiarY2);
	cout << "\nUtworzona macierz:\n";
	macierz2.wyswietlMacierz();

	Macierz suma = macierz1 - macierz2;
	cout << "\nWynik:\n";
	suma.wyswietlMacierz();
}

void Mnozenie()
{
	int rozmiarX1;
	int rozmiarY1;
	int rozmiarX2;
	int rozmiarY2;

	cout << "\nPodaj wymiar X pierwszej macierzy:\n";
	cin >> rozmiarX1;
	cout << "\nPodaj wymiar Y pierwszej macierzy:\n";
	cin >> rozmiarY1;

	cout << "\nWprowadz wartosci pierwszej macierzy:\n";
	Macierz macierz1 = Macierz(rozmiarX1, rozmiarY1);
	cout << "\nUtworzona macierz:\n";
	macierz1.wyswietlMacierz();

	cout << "\nPodaj wymiar X drugiej macierzy:\n";
	cin >> rozmiarX2;
	cout << "\nPodaj wymiar Y drugiej macierzy:\n";
	cin >> rozmiarY2;

	cout << "\nWprowadz wartosci drugiej macierzy:\n";
	Macierz macierz2 = Macierz(rozmiarX2, rozmiarY2);
	cout << "\nUtworzona macierz:\n";
	macierz2.wyswietlMacierz();

	Macierz suma = macierz1 * macierz2;
	cout << "\nWynik:\n";
	suma.wyswietlMacierz();
}

void Transpozycja()
{
	int rozmiarX1;
	int rozmiarY1;

	cout << "\nPodaj wymiar X macierzy:\n";
	cin >> rozmiarX1;
	cout << "\nPodaj wymiar Y macierzy:\n";
	cin >> rozmiarY1;

	cout << "\nWprowadź wartości macierzy:\n";
	Macierz macierz = Macierz(rozmiarX1, rozmiarY1);
	cout << "\nUtworzona macierz:\n";
	macierz.wyswietlMacierz();
	macierz.transponuj();
	cout << "\nWynik:\n";
	macierz.wyswietlMacierz();
}

void MacierzOdwrotna()
{
	int rozmiarX1;
	int rozmiarY1;

	cout << "\nPodaj wymiar X macierzy:\n";
	cin >> rozmiarX1;
	cout << "\nPodaj wymiar Y macierzy:\n";
	cin >> rozmiarY1;

	cout << "\nWprowadź wartości macierzy:\n";
	Macierz macierz = Macierz(rozmiarX1, rozmiarY1);
	cout << "\nUtworzona macierz:\n";
	macierz.wyswietlMacierz();
	macierz.wyznaczOdwrotna();
	cout << "\nWynik:\n";
	macierz.wyswietlMacierz();
}

int main()
{
	cout << "Kalkulator macierzy\n";
	int menuIndex = 0;
	while (1)
	{
		cout << "\n    Dostepne operacje: \n    1 - Dodawanie macierzy \n    2 - Odejmowanie macierzy \n    3 - Mnozenie macierzy \n    4 - Transponuj macierz \n    5 - Wyznacz macierz odwrotna \n    Wybierz operacje: ";
		cin >> menuIndex;
		switch (menuIndex)
		{
			case 1:
			{
				Dodawanie();
				break;
			}
			case 2:
			{
				Odejmowanie();
				break;
			}
			case 3:
			{
				Mnozenie();
				break;
			}
			case 4:
			{
				Transpozycja();
				break;
			}
			case 5:
			{
				MacierzOdwrotna();
				break;
			}
			default:
				break;
		}
		menuIndex = 0;
	}
}




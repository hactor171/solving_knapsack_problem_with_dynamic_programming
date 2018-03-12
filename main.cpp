#include <stdio.h>
#include <tchar.h>
#include "Plik.h"
#include "Algorytm.h"
#include <iostream>
#include "windows.h"
#include "Timer.h"
using namespace std;
int main()
{
	Plik * plik = new Plik();
	Algorytm * algorytm = new Algorytm();
	Timer *czas = new Timer();
	char w;
	bool a, b;
	a = b = true;
	while (a) {
		cout << endl;
		cout << "\n== Menu Glowne ==\n" << endl;
		cout << "Wybierz:" << endl;
		cout << "-1-. Praca z danymi" << endl;
		cout << "-2-. Algorytm" << endl;
		cout << "-3-. Zakonc program" << endl;
		cout << "\nWpisz potrzebne: ";
		cin >> w;
		cout << endl;
		system("cls");
		switch (w) {
		case '1': {
			b = true;
			while (b)
			{
				cout << "\n<<Menu - Generowania danych>>\n" << endl;
				cout << "Wybierz opcje:" << endl;
				cout << "-1- Wczytaj dane z pliku:" << endl;
				cout << "-2- Zgeneruj dane samodzielnie:" << endl;
				cout << "\n-a- Powrot do ==Menu Glowne==\n" << endl;
				cout << "\nWpisz potrzebne: ";

				cin >> w;
				system("cls");
				switch (w)
				{
				case '1': {
					string string;
					cout << "Nazwa pliku dla wczytania: ";
					cin >> string;
					plik->wczytaj(string);
					plik->wyswietlplik();
					break;
				}
				case '2': {
					int ilosc;
					cout << "Ilosc miast: ";
					cin >> ilosc;
					plik->generuj(ilosc);
					break;
				}
				case 'a': {
					b = false;
					break;
				}
				}

			}
			break;
		}
		case '2': {
			int c = 0;
			plik->wyswietlplik();
			czas->startTimer();
			algorytm->oblicz(plik->odl, plik->X, plik->ilosc_m);
			czas->endTimer();
			cout << "Czas wykonania algorytmu: " << czas->endTimer() << endl;
			algorytm->wyswietl();
			break;
		}
		case '3':
		{
			a = false;
			break;
		}

		}
	}

}


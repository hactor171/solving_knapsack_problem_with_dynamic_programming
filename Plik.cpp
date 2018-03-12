#include <stdio.h>
#include <tchar.h>
#include "Plik.h"
#include <iomanip>


Plik::Plik()// konstruktor 
{
}
Plik::~Plik()// destruktor
{
}
void Plik::wczytaj(string name)
{
	fstream plik;
	plik.open(name, ios::in);

	if (plik >> ilosc_m)// jesli wpisujemy zwykly plik
	{
		odl = new int*[ilosc_m];
		for (int i = 0; i < ilosc_m; i++) {
			odl[i] = new int[ilosc_m];
		}
		for (int i = 0; i < ilosc_m; i++)
			for (int j = 0; j < ilosc_m; j++) {
				plik >> odl[i][j];
				if (i == j)// 
					odl[i][j] = -1;
			}
		X = new int*[(1 << ilosc_m)];
		for (int i = 0; i < (1 << ilosc_m); i++) {
			X[i] = new int[ilosc_m];
		}
	}
	else {// jesli wykorzystany plik formatu .atsp
		fstream plik;
		plik.open(name, ios::in);
		string wkladka;
		string tymcz = " ";
		while (!plik.eof() && tymcz != "")
		{
			getline(plik, tymcz);
			wkladka += tymcz + "  " + " \n";
		}
		string pierwszy = "DIMENSION: ";
		string drugi = "EDGE_WEIGHT_TYPE:";
		string trzeci = "EDGE_WEIGHT_SECTION";
		string czwarty = "EOF";
		wkladka.erase(0, wkladka.find(pierwszy) + pierwszy.length());
		wkladka.erase(wkladka.find(drugi) - 4, wkladka.find(trzeci) + trzeci.length());
		wkladka.erase(wkladka.find(czwarty), czwarty.length());

		ZapiszNowyPlik("NowyPlik.txt", wkladka);
		plik.close();

		fstream file;
		file.open("NowyPlik.txt", ios::in);
		file >> ilosc_m;
		odl = new int*[ilosc_m];
		for (int i = 0; i < ilosc_m; i++) {
			odl[i] = new int[ilosc_m];
		}
		for (int i = 0; i < ilosc_m; i++)
			for (int j = 0; j < ilosc_m; j++) {
				file >> odl[i][j];
				if (i == j)// 
					odl[i][j] = -1;
			}
		X = new int*[(1 << ilosc_m)];
		for (int i = 0; i < (1 << ilosc_m); i++) {
			X[i] = new int[ilosc_m];
		}
	}

}
void Plik::ZapiszNowyPlik(string nazwapliku, string Text)
{
	ofstream file;
	file.open(nazwapliku, ios::out | ios::app);
	if (file.is_open())
		file << Text << "\n\n";
	else
		cout << "Blad odczytu!" << endl;
}

void Plik::generuj(int ilosc) {// generowanie losowych danych 
	ilosc_m = ilosc;
	int N = 1 << ilosc_m;
	odl = new int*[ilosc_m];
	for (int i = 0; i < ilosc_m; i++) {
		odl[i] = new int[ilosc_m];
	}
	for (int i = 0; i < ilosc_m; i++)
		for (int j = 0; j < ilosc_m; j++) {
			odl[i][j] = rand() % 100;
			if (i == j)
				odl[i][j] = -1;
		}
	X = new int*[N];
	for (int i = 0; i < N; i++) {
		X[i] = new int[ilosc_m];
	}
}

void Plik::wyswietlplik() { // Wyswietlenie wczytanego pliku 
	cout << "Ilosc miast : " << ilosc_m << endl;
	for (int i = 0; i < ilosc_m; i++) {
		for (int j = 0; j < ilosc_m; j++)
			cout << setw(5) << odl[i][j];
		cout << endl;
	}
}

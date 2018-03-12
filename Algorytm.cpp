#include <stdio.h>
#include <tchar.h>
#include "Algorytm.h"

using namespace std;

Algorytm::Algorytm()// konstruktor
{
}
Algorytm::~Algorytm()// destruktor
{
}

void Algorytm::oblicz(int **o, int **X2, int ilosc) {// funkcja obliczenia minimalnej sciezki

	odl = o; // otrzymanie odlegosci 
	X = X2;
	ilosc_m = ilosc; // otzymanir ilosci miast

	for (int i = 0; i < (1 << ilosc_m); i++) // tworzymy  masyw w jakim znajduja podmaski i miasta
		for (int j = 0; j < ilosc_m; j++)
			X[i][j] = 99999;// wypelniamy caly masyw 99999 

	X[1][0] = 0; // maska 1 ma w sobie tylko zerowy element

	sciezka = new int[ilosc_m + 1]; // tworzenie sciezki dla n+1(wrocic do pierwszego) miast i wypelnienie zerami
	for (int i = 0; i < ilosc_m + 1; i++) {
		sciezka[i] = 0;
	}

	for (int i = 2; i < (1 << ilosc); i++) {// zaczynamy  od 2 maski 
		for (int j = 0; j < ilosc_m; j++) {// 
			if ((i >> j) & 1) { // Sprawdzamy czy i nalezy j
				int maska_bez_i = i ^ (1 << j);// maska bez dannego i, jest szukane przy pomocy funkcji XOR 

				for (int k = 0; k < ilosc_m; k++) {
					if (k != j && ((i >> k) & 1)) {  //Если k != j и mask содержит k
													 // k!=j wykluczamy liczby po przekatnej i sprawdzamy czy i nalezy k
						X[i][j] = min(X[i][j], X[maska_bez_i][k] + odl[k][j]); //szukanie minimalnego znaczenia
																			   //(jeśli jest jakies mniejsze od poprzedniego to zapisujemy go) 
					}
				}
			}
		}
	}

	minimalne_z = INT_MAX;// nadajemy minimum makszymalnego znaczenia
	int index;// tworzymy indeks
	int maska_cal = (1 << ilosc_m) - 1;// maska jaka miesci w sobie calosc
	for (int i = 1; i < ilosc_m; i++)// poruwnujemy otrzymane minimumy dla tego zeby wybrac najmniejszу
		if (X[maska_cal][i] + odl[i][0] < minimalne_z) { // otrzymany minimum + wrocenie do pierwszego mista 
			minimalne_z = X[maska_cal][i] + odl[i][0];
			index = i;// w jakim i zapisujemy minimalne znaczenia 
		}
	wylicz = ilosc_m - 1;// ilosc miast bez wrocenia 
	sciezka[wylicz] = index; // nadajemy sciezce index w jakim znajduje sie minimalne znaczenie 
	zapis_sziezki(maska_cal, index); // wylowamy funkcje jaka zrobi sciezke po jakiej przechodzimy

}
void Algorytm::zapis_sziezki(int zacz, int index) {// funkcja zapisywania sziezki
												   // zaczynamy zapisywanie od ostatniej ścieżki potem zmniejszamy licznik i zapisujemy kolejny etap 
												   // do tego czasu gdy nie będzie w początku
	if (zacz == 1)//znaczy to ze znajdujemy w pierwszym wierszu
		return;
	int od = 1 << index; 
	for (int j = 1; j < ilosc_m; j++) {
		if (X[zacz - od][j] + odl[j][index] == X[zacz][index]) { 
			sciezka[--wylicz] = j;// nadajemy sciezce znaczenie j(to i jest miasto)
			zapis_sziezki(zacz - od, j);// znowu wylowujemy funkcje, w tym juz mamy zapisane do sciezki miasto
			break;
		}
	}
}
void Algorytm::wyswietl() {// wyswietlenie wynikow po otrzymaniu naszej sciezki
	cout << endl << "Minimalna sciezka wynosi: " << minimalne_z << endl;// wyswitlenie optymalnej trasy
	cout << "Sciezka : ";
	for (int i = 0; i < ilosc_m + 1; i++) {// wyswietlenie przejsc 
		cout << sciezka[i] << " ";
	}

}

#pragma once
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Algorytm
{
public:
	Algorytm();
	void oblicz(int **odl, int **X, int ilosc);//funkcja obliczenia minimalnej sciezki
	int ilosc_m;// otrzymana ilosc miast
	int wylicz;
	int minimalne_z;
	int *sciezka;
	int **X;
	int **odl;
	void wyswietl();//wyswietlenie wynikow
	void zapis_sziezki(int zacz, int index);
	~Algorytm();
};


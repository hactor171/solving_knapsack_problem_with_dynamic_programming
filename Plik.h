#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Plik
{
public:
	Plik();
	void wczytaj(string name); // funkcja wczytania 
	void generuj(int ilosc_m);// funkacja generowania
	void wyswietlplik();// funkcja wyswietlenia
	void ZapiszNowyPlik(string nazwapliku, string Text);// funkcja jaka wykorzystana dla pomocy przy wczytaniu pliku.atsp
	int** odl;
	int **X;
	int ilosc_m;
	~Plik();
};


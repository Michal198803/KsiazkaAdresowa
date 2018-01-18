#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
using namespace std;

struct Osoba {
	int id;
	string imie, nazwisko, numerTelefonu, email, adres;
};

void wczytajOsobyZPliku(vector<Osoba>&osoby) {
	string linia;
	int nr_linii = 1;
	int iloscOsob = 0;
	Osoba osobaStr;
	string nazwaPlikuDoOtwarcia;
	cout << "Podaj nazwe pelna nazwe pliku do konwersji";

	cin >> nazwaPlikuDoOtwarcia;

	fstream plik;
	plik.open(nazwaPlikuDoOtwarcia, ios::in);
	if (plik.good() == true) {

		while (getline(plik, linia)) {
			switch (nr_linii) {
			case 1:
				osobaStr.id = atoi(linia.c_str());
				break;
			case 2:
				osobaStr.imie = linia;
				break;
			case 3:
				osobaStr.nazwisko = linia;
				break;
			case 4:
				osobaStr.numerTelefonu = linia;
				break;
			case 5:
				osobaStr.email = linia;
				break;
			case 6:
				osobaStr.adres = linia;
				break;
			}
			if (nr_linii >= 6) {
				osoby.push_back(osobaStr);
				nr_linii = 1;
				iloscOsob++;
			} else {
				nr_linii++;
			}
		}
		plik.close();
	}

	else {

		cout << "Bledna nazwa pliku." << endl;
		cout << "Sprawdz poprawna nazwe pliku pamietajac o rozszerzeniu (.txt)."
				<< endl;
		cout << "Uruchom program ponownie." << endl;
		exit(0);
	}

}

void konwersjaPliku(vector<Osoba>&osoby)

{

	fstream plik;

	plik.open("KsiazkaAdresowa_nowy_format.txt", ios::out | ios::app);

	for (int i = 0; i < osoby.size(); i++)

	{

		plik << osoby[i].id << "|" << osoby[i].imie << "|" << osoby[i].nazwisko
				<< "|" << osoby[i].email << "|" << osoby[i].numerTelefonu << "|"
				<< osoby[i].adres << endl;

	}
	plik.close();
	cout << "Konwersja zakonczona." << endl;

}

int main() {
	vector<Osoba> osoby;

	wczytajOsobyZPliku(osoby);

	int wybor;

	while (true) {
		system("cls");
		cout << "1. Potwierdz konwersje" << endl;

		cout << "2. Zakoncz program" << endl;
		cin >> wybor;

		if (wybor == 1) {

			konwersjaPliku(osoby);
		}
		if (wybor == 2) {

			exit(0);
		}

	}
	return 0;
}

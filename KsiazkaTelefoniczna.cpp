//============================================================================
// Name        : KsiazkaTelefoniczna.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <windows.h>

#include <fstream>

#include <string>

#include <vector>
//test

using namespace std;

struct Osoba {

	int id;

	string imie, nazwisko, numerTelefonu, email, adres;

};

int wczytajOsobyZPliku(vector<Osoba>&osoby) {

	int index = 0;
	string daneZLini[6];
	string danaZLini;
	string linia;

	int iloscOsob = 0;
	Osoba osobaStr;
	fstream plik;
	plik.open("KsiazkaAdresowa.txt", ios::in);
	if (plik.good() == true) {

		while (getline(plik, linia)) {

			for (int i = 0; i < linia.size(); i++) {

				if (linia[i] == '|') {
					daneZLini[index] = danaZLini;
					danaZLini = "";
					index++;
					continue;
				}
				danaZLini += linia[i];
			}
			daneZLini[5] = danaZLini;
			danaZLini = "";
			index = 0;
			string id = daneZLini[0];

			osobaStr.id = atoi(id.c_str());
			osobaStr.imie = daneZLini[1];
			osobaStr.nazwisko = daneZLini[2];
			osobaStr.numerTelefonu = daneZLini[3];
			osobaStr.email = daneZLini[4];
			osobaStr.adres = daneZLini[5];

			osoby.push_back(osobaStr);

			iloscOsob++;
		}

		plik.close();
	}
	return iloscOsob;
}
int dodajOsobe(vector<Osoba>&osoby, int iloscOsob)

{

	string imie, nazwisko, numerTelefonu, email, adres;

	system("cls");

	cout << "Dodawanie osoby" << endl;

	cout << "Podaj imie uzytkownika: ";

	cin >> imie;

	cout << "Podaj nazwisko uzytkownika: ";

	cin >> nazwisko;

	cout << "Podaj numer telefonu uzytkownika: ";

	cin.sync();

	getline(cin, numerTelefonu);

	cout << "Podaj email uzytkownika: ";

	cin >> email;

	cout << "Podaj adres uzytkownika: ";

	cin.sync();

	getline(cin, adres);

	if (osoby.size() > 1) {
		int osobaId = osoby[iloscOsob].id + 1;
	}

	int osobaId = iloscOsob + 1;

	Osoba temp;

	temp.id = osobaId;

	temp.imie = imie;

	temp.nazwisko = nazwisko;

	temp.numerTelefonu = numerTelefonu;

	temp.email = email;

	temp.adres = adres;

	osoby.push_back(temp);

	fstream plik;

	plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);

	if (plik.good())

	{

		plik << temp.id << "|" << temp.imie << "|" << temp.nazwisko << "|"
				<< temp.email << "|" << temp.numerTelefonu << "|" << temp.adres
				<< endl;

		plik.close();

		cout << "Osoba zostala dodana." << endl;

		Sleep(1000);

	}

	else

	{

		cout << "Nie mozna otworzyc pliku: KsiazkaAdresowa.txt" << endl;

	}

	iloscOsob++;

	return iloscOsob;

}

void imieOsobe(vector<Osoba>&osoby, int iloscOsob)

{
	bool czyZnalezionoKogos = false;
	string imie;

	system("cls");

	cout << "Podaj imie szukanej osoby: " << endl;

	cin >> imie;

	for (int indeks = 0; indeks < iloscOsob; indeks++)

	{
		if (osoby[indeks].imie == imie)

		{
			czyZnalezionoKogos = true;

			cout << "Zgodny z: " << "imie " << imie << endl;
			cout << endl;

			cout << "Numer dodania: " << osoby[indeks].id << endl;

			cout << "Imie: " << osoby[indeks].imie << endl;

			cout << "Nazwisko: " << osoby[indeks].nazwisko << endl;

			cout << "Telefon: " << osoby[indeks].numerTelefonu << endl;

			cout << "Email: " << osoby[indeks].email << endl;

			cout << "Adres: " << osoby[indeks].adres << endl;
			cout << endl;
		}
	}

	if (czyZnalezionoKogos == false) {
		cout << "Nie ma takiej osoby";
	}
	cout << endl;

	system("pause");

}

void nazwiskoOsobe(vector<Osoba>&osoby, int iloscOsob)

{
	bool czyZnalezionoKogos = true;

	string nazwisko;

	system("cls");

	cout << "Podaj nazwisko szukanej osoby: " << endl;

	cin >> nazwisko;

	for (int indeks = 0; indeks < iloscOsob; indeks++) {
		if (osoby[indeks].nazwisko == nazwisko)

		{
			cout << "Zgodny z: " << "nazwisko " << nazwisko << endl;
			cout << endl;

			cout << "Numer dodania: " << osoby[indeks].id << endl;

			cout << "Imie: " << osoby[indeks].imie << endl;

			cout << "Nazwisko: " << osoby[indeks].nazwisko << endl;

			cout << "Telefon: " << osoby[indeks].numerTelefonu << endl;

			cout << "Email: " << osoby[indeks].email << endl;

			cout << "Adres: " << osoby[indeks].adres << endl;
			cout << endl;

		}
	}

	if (czyZnalezionoKogos == false)

	{

		cout << "Nie ma takiej osoby";

	}
	cout << endl;
	system("pause");

}

void wyswietlOsoby(vector<Osoba>&osoby, int iloscOsob) {
	system("cls");

	{

		for (int indeks = 0; indeks < iloscOsob; indeks++)

		{
			cout << endl;

			cout << "Numer dodania:" << osoby[indeks].id << endl;

			cout << "Imie: " << osoby[indeks].imie << endl;

			cout << "Nazwisko: " << osoby[indeks].nazwisko << endl;

			cout << "Telefon: " << osoby[indeks].numerTelefonu << endl;

			cout << "Email: " << osoby[indeks].email << endl;

			cout << "Adres: " << osoby[indeks].adres << endl;

			cout << endl;
		}
	}
	system("pause");
}

void kasuj_wiersz(const string sciezka, vector<Osoba>&osoby) {
	int wiersz;
	cout << "Podaj id uzytkownika do usuniecia";
	cin >> wiersz;
	vector<std::string> vec;
	ifstream in(sciezka.c_str());
	string tmp;
	while (getline(in, tmp))
		vec.push_back(tmp);

	in.close();
	ofstream out(sciezka.c_str());
	for (size_t i = 0; i < vec.size(); ++i) {
		if (i + 1 != wiersz)
			out << vec[i] << std::endl;

	}
	osoby.clear();
	wczytajOsobyZPliku(osoby);
	cout << "Wpis usuniety";
	out.close();

}

void zmienDaneOsoby(vector<Osoba>&osoby) {
	system("cls");
	Osoba osobaStr;
	int wybor, index, iloscOsob, uzytkowniDoZmiany;
	string wyborZmiany, linia, danaZLini;
	string daneZLini[6];

	cout << "Wybierz dostepna opcje zmiany: " << endl;

	cout << "1. Imie" << endl;

	cout << "2. Nazwisko" << endl;

	cout << "3. Telefon" << endl;

	cout << "4. Email" << endl;

	cout << "5.Adres" << endl;

	cout << "6.Powrot do menu glownego" << endl;

	cin >> wybor;

	if (wybor == 1) {
		cout << "Wprowadz id uzytkownika do zmiany";
		cin >> uzytkowniDoZmiany;
		cout << "Wprowadz nowe imie";
		cin >> wyborZmiany;

		for (int i = 0; i < osoby.size(); i++) {
			if (osoby[i].id == uzytkowniDoZmiany) {
				osoby[i].imie = wyborZmiany;
			}
		}
	}

	if (wybor == 2) {
		cout << "Wprowadz id uzytkownika do zmiany";
		cin >> uzytkowniDoZmiany;
		cout << "Wprowadz nowe nazwisko";
		cin >> wyborZmiany;

		for (int i = 0; i < osoby.size(); i++) {
			if (osoby[i].id == uzytkowniDoZmiany) {
				osoby[i].nazwisko = wyborZmiany;
			}
		}
	}
	if (wybor == 3) {
		cout << "Wprowadz id uzytkownika do zmiany";
		cin >> uzytkowniDoZmiany;
		cout << "Wprowadz nowy numer telefonu";
		cin >> wyborZmiany;

		for (int i = 0; i < osoby.size(); i++) {
			if (osoby[i].id == uzytkowniDoZmiany) {
				osoby[i].numerTelefonu = wyborZmiany;
			}
		}
	}
	if (wybor == 4) {
		cout << "Wprowadz id uzytkownika do zmiany";
		cin >> uzytkowniDoZmiany;
		cout << "Wprowadz nowy email";
		cin >> wyborZmiany;

		for (int i = 0; i < osoby.size(); i++) {
			if (osoby[i].id == uzytkowniDoZmiany) {
				osoby[i].email = wyborZmiany;
			}
		}
	}
	if (wybor == 5) {
		cout << "Wprowadz id uzytkownika do zmiany";
		cin >> uzytkowniDoZmiany;
		cout << "Wprowadz nowy adres";
		cin >> wyborZmiany;

		for (int i = 0; i < osoby.size(); i++) {
			if (osoby[i].id == uzytkowniDoZmiany) {
				osoby[i].adres = wyborZmiany;
			}
		}
	}

	if (wybor == 6) {

		return;
	}

	ofstream plik;
	plik.open("KsiazkaAdresowa.txt");
	plik.clear();

	for (int i = 0; i < osoby.size(); i++) {

		plik << osoby[i].id << "|" << osoby[i].imie << "|" << osoby[i].nazwisko
				<< "|" << osoby[i].email << "|" << osoby[i].numerTelefonu << "|"
				<< osoby[i].adres << endl;

	}
	plik.close();

}
int main()

{

	vector<Osoba> osoby;

	int iloscOsob = 0;

	char wybor;

	iloscOsob = wczytajOsobyZPliku(osoby);

	while (true)

	{

		system("cls");

		cout << "1. Dodaj osobe do kontaktow" << endl;

		cout << "2. Wyszukaj osobe po imieniu" << endl;

		cout << "3. Wyszukaj osobe po nazwisku" << endl;

		cout << "4. Pokaz wszystkie kontakty" << endl;

		cout << "5. Zmien dane uzytkownika" << endl;

		cout << "6. Usun uzytkownika" << endl;

		cout << "9. Zakoncz program" << endl;

		cin >> wybor;

		if (wybor == '1')

		{

			iloscOsob = dodajOsobe(osoby, iloscOsob);

		}

		else if (wybor == '2')

		{

			imieOsobe(osoby, iloscOsob);

		}

		else if (wybor == '3')

		{

			nazwiskoOsobe(osoby, iloscOsob);

		}

		else if (wybor == '4')

		{

			wyswietlOsoby(osoby, iloscOsob);

		}

		else if (wybor == '5')

		{

			zmienDaneOsoby(osoby);

		}

		else if (wybor == '6')

		{

			kasuj_wiersz("KsiazkaAdresowa.txt", osoby);

		}

		else if (wybor == '9')

		{

			exit(0);

		}

	}

	return 0;

}

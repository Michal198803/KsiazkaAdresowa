#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
string nazwaPlikuLogowania = "Logowanie.txt";
string nazwaPliku = "KsiazkaAdresowa.txt";
struct Osoba {

    int id, idUsera;

    string imie, nazwisko, numerTelefonu, email, adres;

};

struct Logowanie {
    int idUsera;
    string login, haslo;
};

int numerIdZalogowanegoUsera;
string konwersjaIntNaString(int liczba) {

    ostringstream ss;
    ss << liczba;
    string string = ss.str();

    return string;

}

string formatujWpis(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

Osoba pobierzKontaktZPliku(string daneOsobyTxt) {

    Osoba kontakt;
    string pojedynczaDanakontakta = "";
    int numerPojedynczejDanejkontakta = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneOsobyTxt.length();
         pozycjaZnaku++) {
        if (daneOsobyTxt[pozycjaZnaku] != '|') {
            pojedynczaDanakontakta += daneOsobyTxt[pozycjaZnaku];
        } else {
            switch (numerPojedynczejDanejkontakta) {
                case 1:
                    kontakt.id = atoi(pojedynczaDanakontakta.c_str());
                    break;
                case 2:
                    kontakt.idUsera = atoi(pojedynczaDanakontakta.c_str());
                    break;
                case 3:
                    kontakt.imie = pojedynczaDanakontakta;
                    break;
                case 4:
                    kontakt.nazwisko = pojedynczaDanakontakta;
                    break;
                case 5:
                    kontakt.numerTelefonu = pojedynczaDanakontakta;
                    break;
                case 6:
                    kontakt.email = pojedynczaDanakontakta;
                    break;
                case 7:
                    kontakt.adres = pojedynczaDanakontakta;
                    break;
            }
            pojedynczaDanakontakta = "";
            numerPojedynczejDanejkontakta++;
        }
    }
    return kontakt;
}

void wyszukajPoImieniuKontaktu(vector<Osoba>&osoby)

{
    bool czyZnalezionoKogos = false;
    string imie;

    system("cls");
    cout << ">>> WUSZUKIWANIE KONTAKTU <<<" << endl << endl;
    cout << "Podaj imie szukanej osoby: " << endl;

    cin >> imie;

    for (int indeks = 0; indeks < osoby.size(); indeks++)

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

void wyszukajPoNazwiskuKontaktu(vector<Osoba>&osoby)

{
    bool czyZnalezionoKogos = true;

    string nazwisko;

    system("cls");
    cout << ">>> WUSZUKIWANIE KONTAKTU <<<" << endl << endl;
    cout << "Podaj nazwisko szukanej osoby: " << endl;

    cin >> nazwisko;

    for (int indeks = 0; indeks < osoby.size(); indeks++) {
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

void wyswietlWszystkieKontakty(vector<Osoba>&osoby) {
    system("cls");

    {
        cout << ">>> LISTA KONTAKTOW <<<" << endl << endl;
        for (int indeks = 0; indeks < osoby.size(); indeks++)

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

void wczytajWszystkieKontaktyDoVectora(vector<Osoba>&osobyWszystkieWpisy){
osobyWszystkieWpisy.clear();
Osoba kontakt;
string pojedynczaDanakontakta = "";

fstream plikTekstowy;
plikTekstowy.open("KsiazkaAdresowa.txt", ios::in);

if (plikTekstowy.good() == true) {
while (getline(plikTekstowy, pojedynczaDanakontakta)) {
kontakt = pobierzKontaktZPliku(pojedynczaDanakontakta);
osobyWszystkieWpisy.push_back(kontakt);

}}}

void kasujWiersz(  int idDoUsuniecia,vector<Osoba>osobyWszystkieWpisy)
{

   wczytajWszystkieKontaktyDoVectora(osobyWszystkieWpisy);

        for(int i = 0 ; i<osobyWszystkieWpisy.size(); i++){

            if(osobyWszystkieWpisy[i].id==idDoUsuniecia)
                osobyWszystkieWpisy.erase(osobyWszystkieWpisy.begin() + i);
        }

fstream plikFormat;
    plikFormat.open("KsiazkaAdresowa.txt", ios::in);
    plikFormat.clear();
    ofstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::trunc);


    for (int i = 0; i < osobyWszystkieWpisy.size(); i++) {

        plik << osobyWszystkieWpisy[i].id << "|"<< osobyWszystkieWpisy[i].idUsera << "|" << osobyWszystkieWpisy[i].imie << "|" <<osobyWszystkieWpisy[i].nazwisko
             << "|" << osobyWszystkieWpisy[i].email << "|" << osobyWszystkieWpisy[i].numerTelefonu << "|"
             << osobyWszystkieWpisy[i].adres << endl;

    }
    plik.close();

}

void usunKontaktZKsiazkiAdresowej(vector<Osoba>&osoby) {
    char potwierdzenieUsuniecia;
    bool usunietyAdresat = false;
    int wybor;
    int idDoUsuniecia;
    cout<<endl;
    cout << ">>> USUWANIE KONTAKTU <<<" << endl << endl;
    cout << "Podaj ID uzytkownika do usuniecia: " << endl << endl;
    cin >> idDoUsuniecia;

    for (int i = 0; i < osoby.size(); i++) {

        if (osoby[i].id == idDoUsuniecia) {

            cout << "Aby usunac adresata nacisnij klawisz t " << endl;
            cin >> potwierdzenieUsuniecia;

            if (potwierdzenieUsuniecia == 't') {

                osoby.erase(osoby.begin() + i);
                kasujWiersz(idDoUsuniecia,osoby);
                cout << "Adresat zostal usuniety: ";
                cout<<endl;
                usunietyAdresat = true;
            }}}

    if (usunietyAdresat == false) {
        cout << "Nie ma w bazie adresata o wskazanym ID ";
        cout << "Wybierz jedna z opcji:  ";
        cout << "1.Wprowadz raz jeszcze nr ID:  ";
        cout << "2.Wyswietl wszystkie kontakty:  ";
        cout << "3.Zakoncz program:  ";
        cout<<endl;

        switch(wybor){


            case 1:
                usunKontaktZKsiazkiAdresowej(osoby);
                break;
            case 2:
                wyswietlWszystkieKontakty(osoby);
                break;
            case 3:
                exit(0);
            break;


        }

    }



    }



void zmienDaneOsoby(vector<Osoba>&osoby) {

    system("cls");
    Osoba osobaStr;
    int wybor, uzytkowniDoZmiany;
    string wyborZmiany, linia, danaZLini;
    string daneZLini[6];
    cout << ">>> ZMIANA DANYCH KONTAKTU <<<" << endl << endl;
    cout << "Wybierz dostepna opcje zmiany: " << endl;

    cout << "1. Imie" << endl;

    cout << "2. Nazwisko" << endl;

    cout << "3. Telefon" << endl;

    cout << "4. Email" << endl;

    cout << "5. Adres" << endl;

    cout << "6.Powrot do menu glownego" << endl;

    cin >> wybor;

    switch (wybor) {

        case 1:

            cout << "Wprowadz id uzytkownika do zmiany: " << endl << endl;
            cin >> uzytkowniDoZmiany;


            for (int i = 0; i < osoby.size(); i++) {
                if (osoby[i].id == uzytkowniDoZmiany) {
                    cout << "Wprowadz nowe imie: " << endl << endl;
                    cin >> wyborZmiany;
                    osoby[i].imie = wyborZmiany;
                    cout<<"Dokonano zmiany";

                }


            }

            break;

        case 2:
            cout << "Wprowadz id uzytkownika do zmiany: " << endl << endl;
            cin >> uzytkowniDoZmiany;


            for (int i = 0; i < osoby.size(); i++) {
                if (osoby[i].id == uzytkowniDoZmiany) {
                    cout << "Wprowadz nowe nazwisko: " << endl << endl;
                    cin >> wyborZmiany;
                    osoby[i].nazwisko = wyborZmiany;
                    cout<<"Dokonano zmiany";

                }

            }

            break;

        case 3:
            cout << "Wprowadz id uzytkownika do zmiany: " << endl << endl;
            cin >> uzytkowniDoZmiany;


            for (int i = 0; i < osoby.size(); i++) {
                if (osoby[i].id == uzytkowniDoZmiany) {
                    cout << "Wprowadz nowy numer telefonu: " << endl << endl;
                    cin >> wyborZmiany;
                    osoby[i].numerTelefonu = wyborZmiany;
                    cout<<"Dokonano zmiany";

                }

            }
            break;

        case 4:
            cout << "Wprowadz id uzytkownika do zmiany: " << endl << endl;
            cin >> uzytkowniDoZmiany;


            for (int i = 0; i < osoby.size(); i++) {
                if (osoby[i].id == uzytkowniDoZmiany) {
                    cout << "Wprowadz nowy email: " << endl << endl;
                    cin >> wyborZmiany;
                    osoby[i].email = wyborZmiany;
                    cout<<"Dokonano zmiany";

                }

            }
            break;

        case 5:

            cout << "Wprowadz id uzytkownika do zmiany: " << endl << endl;
            cin >> uzytkowniDoZmiany;


            for (int i = 0; i < osoby.size(); i++) {
                if (osoby[i].id == uzytkowniDoZmiany) {
                    cout << "Wprowadz nowy adres: " << endl << endl;
                    cin >> wyborZmiany;
                    osoby[i].adres = wyborZmiany;
                    cout<<"Dokonano zmiany";

                }

            }
            break;

        case 6: {

            return;
        }
    }
    ofstream plik;
    plik.open(nazwaPliku);
    plik.clear();

    for (int i = 0; i < osoby.size(); i++) {

        plik << osoby[i].id << "|" << osoby[i].imie << "|" << osoby[i].nazwisko
             << "|" << osoby[i].email << "|" << osoby[i].numerTelefonu << "|"
             << osoby[i].adres << endl;

    }
    plik.close();


}

void wczytajDaneZPlikuLogowanie(vector<Logowanie>&loginy, vector<Osoba>&osoby,
                                Logowanie login, int &numerIdZalogowanegoUsera) {
    int index = 0;
    string daneZLini[3];
    string danaZLini;
    string linia;

    fstream plik;
    plik.open("Logowanie.txt", ios::in);
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
            daneZLini[2] = danaZLini;
            login.idUsera = atoi(daneZLini[0].c_str());
            login.login = daneZLini[1];
            login.haslo = daneZLini[2];
            index = 0;

            loginy.push_back(login);
            danaZLini = "";

        }
        plik.close();
    }
}

void wczytajKontaktyZplikuTxt(vector<Osoba>&osoby,
                              int &numerIdZalogowanegoUsera) {
    string nazwaPliku = "KsiazkaAdresowa.txt";
    Osoba kontakt;
    string pojedynczaDanakontakta = "";

    fstream plikTekstowy;
    plikTekstowy.open(nazwaPliku.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, pojedynczaDanakontakta)) {
            kontakt = pobierzKontaktZPliku(pojedynczaDanakontakta);
            if (kontakt.idUsera == numerIdZalogowanegoUsera)
                osoby.push_back(kontakt);
        }
        plikTekstowy.close();
    }
}

void dopiszOsobeDoPliku(Osoba osoba, int numerIdZalogowanegoUsera) {
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPliku.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        osoba.idUsera = numerIdZalogowanegoUsera;

        plikTekstowy << osoba.id << '|';
        plikTekstowy << osoba.idUsera << '|';
        plikTekstowy << osoba.imie << '|';
        plikTekstowy << osoba.nazwisko << '|';
        plikTekstowy << osoba.numerTelefonu << '|';
        plikTekstowy << osoba.email << '|';
        plikTekstowy << osoba.adres << '|' << endl;

        plikTekstowy.close();
        cout << endl << "Kontakt zostal dodany" << endl;
        system("pause");
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl
             << endl;
        system("pause");
    }
}

void dodajOsobe(vector<Osoba> &osoby, vector<Logowanie>&loginy,vector<Osoba>osobyWszystkieWpisy,
                int &numerIdZalogowanegoUsera) {
    wczytajWszystkieKontaktyDoVectora(osobyWszystkieWpisy);
    Osoba osoba;
    vector <int> numeryId;
    string linia, danaZLini;
    char c;
    int liczbaWierszyWPlikuKsiazkiAdresowej = 0;
    system("cls");
    cout << ">>> DODAWANIE NOWEGO KONTAKTU <<<" << endl << endl;

    fstream plik;
    plik.open("Logowanie.txt", ios::in);

    std::ifstream f("KsiazkaAdresowa.txt");

    if(osobyWszystkieWpisy.size()==0){
        osoba.id=1;
    }

    else if (osobyWszystkieWpisy.size()!=0){

    if (plik.good() == true) {

        while (f.get(c)) {
            if (c == '\n') {


                ++liczbaWierszyWPlikuKsiazkiAdresowej;
            }
        }
        osoba.id = liczbaWierszyWPlikuKsiazkiAdresowej + 1;

        if (osoba.id == osobyWszystkieWpisy[osobyWszystkieWpisy.size() - 1].id) {
            osoba.id++;
        }
    }

    }
    osoba.idUsera = loginy[numerIdZalogowanegoUsera].idUsera;
    cout << "Podaj imie: ";
    cin >> osoba.imie;
    osoba.imie = formatujWpis(osoba.imie);

    cout << "Podaj nazwisko: ";
    cin >> osoba.nazwisko;
    osoba.nazwisko = formatujWpis(osoba.nazwisko);

    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin, osoba.numerTelefonu);

    cout << "Podaj email: ";
    cin >> osoba.email;

    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, osoba.adres);

    osoby.push_back(osoba);

    dopiszOsobeDoPliku(osoba, numerIdZalogowanegoUsera);
}

void menuKsiazkiAdresowej(vector<Osoba>&osoby, vector<Logowanie>&loginy,
                          Logowanie login, int &numerIdZalogowanegoUsera,vector<Osoba>&osobyWszystkieWpisy) {
    system("cls");

    wczytajKontaktyZplikuTxt(osoby, numerIdZalogowanegoUsera);
    int wybor;

    while (true)

    {

        system("cls");

        cout << "1. Dodaj osobe do kontaktow" << endl;

        cout << "2. Wyszukaj osobe po imieniu" << endl;

        cout << "3. Wyszukaj osobe po nazwisku" << endl;

        cout << "4. Pokaz wszystkie kontakty" << endl;

        cout << "5. Zmien dane uzytkownika" << endl;

        cout << "6. Usun adresata" << endl;

        cout << "9. Zakoncz program" << endl;

        cin >> wybor;

        switch (wybor) {

            case 1:

                dodajOsobe(osoby, loginy, osobyWszystkieWpisy,numerIdZalogowanegoUsera);

                break;

            case 2:

                wyszukajPoImieniuKontaktu(osoby);

                break;

            case 3:

                wyszukajPoNazwiskuKontaktu(osoby);

                break;

            case 4:

                wyswietlWszystkieKontakty(osoby);

                break;

            case 5:

                zmienDaneOsoby(osoby);
                break;

            case 6:

                usunKontaktZKsiazkiAdresowej(osoby);

                break;

            case 9:

                exit(0);

        }

    }
}

int logowanie(vector<Logowanie>&loginy, vector<Osoba>&osoby, Logowanie login,
              int &numerIdZalogowanegoUsera,vector<Osoba>osobyWszystkieWpisy) {

    string haslo;
    string loginWprowadzony;

    cout << "Wprowadz login";
    cin >> loginWprowadzony;
    cout << "Wprowadz haslo:";
    cin >> haslo;

    wczytajDaneZPlikuLogowanie(loginy, osoby, login, numerIdZalogowanegoUsera);

    for (int i = 0; i < loginy.size(); i++) {
        if ((loginy[i].login == loginWprowadzony)
            && (loginy[i].haslo == haslo)) {
            numerIdZalogowanegoUsera = i + 1;

            menuKsiazkiAdresowej(osoby, loginy, login,
                                 numerIdZalogowanegoUsera,osobyWszystkieWpisy);
        }

    }
    return numerIdZalogowanegoUsera;
}

void rejestracja(vector<Logowanie>&loginy, vector<Osoba>&osoby, Logowanie login,
                 string &loginWprowadzony) {
    system("cls");
    wczytajDaneZPlikuLogowanie(loginy, osoby, login, numerIdZalogowanegoUsera);
    cout << "Wprowadź login nowego uzytkownika: " << endl << endl;
    cin >> login.login;
    cout << "Wprowadź haslo nowego uzytkownika: " << endl << endl;
    cin >> login.haslo;

    login.idUsera = loginy.size() + 1;
    fstream plikTekstowyLogowanie;
    plikTekstowyLogowanie.open(nazwaPlikuLogowania.c_str(),
                               ios::out | ios::app);

    if (plikTekstowyLogowanie.good() == true) {
        plikTekstowyLogowanie << login.idUsera << '|';
        plikTekstowyLogowanie << login.login << '|';
        plikTekstowyLogowanie << login.haslo << endl;
        plikTekstowyLogowanie.close();

        cout << "Login dodany" << endl << endl;
    } else {
        cout << "Nie mozna otworzyc pliku: logowanie.txt" << endl << endl;
    }

}

int main() {

    int wybor;
    int numerIdZalogowanegoUsera=0;
    int idDoUsuniecia = 0;
    string loginWprowadzony;
    vector<Osoba> osoby;
    vector<Osoba> osobyWszystkieWpisy;
    vector<Logowanie> loginy;
    Logowanie login;


    while (true) {

        cout << endl;
        cout << "1.Logowanie" << endl << endl;
        cout << "2.Rejestracja" << endl << endl;
        cout << "3.Zamknij program" << endl << endl;

        cin >> wybor;

        switch (wybor) {

            case 1:
                logowanie(loginy, osoby, login, numerIdZalogowanegoUsera, osobyWszystkieWpisy);
                break;
            case 2:
                rejestracja(loginy, osoby, login, loginWprowadzony);
                break;
            case 3:
                exit(0);

        }
    }

}

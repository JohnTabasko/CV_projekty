#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

const int liczba_liter = 25; // LICZBA LITER W ALFABECIE

using namespace std;

// STRUKTURA DLA UŁATWIENIA WYPISYWANIA
struct Osoba {
	string imie;
	string nazwisko;
	string data_urodzin;
	string data_imienin;
	string komentarz;
	string link;
};

// GENERUJE GÓRĘ PLIKU
void generuj_header(string nazwa_plik_html) {
	fstream plik_html(nazwa_plik_html, ios::out);
	plik_html << "<html>\n";
	plik_html << "<head>\n<meta charset=\"ISO-8859-2\">\n<title>Lista kontaktów</title>\n";
	plik_html << "<style>body{background-color:#607C38;} td {width:18%;text-align:center;} #top{height:20%;background-color:#A9FF2C;font-size:50px;text-align:center;} #left{height:80%;float:left;width:20%;background-color:#B2E863;text-align:center;font-size:24px;} ";
	plik_html << "#right{background-color:#607C38; height:80%; font-size:24px;}";
	plik_html<< "</style>\n";
	plik_html << "</head>\n";
	plik_html << "<body>\n";
	plik_html << "<div id=\"top\">Lista kontaktów</div>\n";
	plik_html << "<div id=\"right\">\n<table border=\"1\"><tr><td>Zdjęcie</td><td>Imię</td><td>Nazwisko</td><td>Urodziny</td><td>Imieniny</td><td>Komentarz</td></tr>\n";
	plik_html.close();
}
// GENERUJE KONIEC PLIKU
void generuj_footer(string nazwa_plik_html) {
	fstream plik_html(nazwa_plik_html, ios::out | ios::app); // ios::app MÓWI ŻEBY DOPISAĆ NA KOŃCU PLIKU
	plik_html << "</div>\n</body>\n</html>\n";
	plik_html.close();
}
void generuj_html(string nazwa_plik_dane,string nazwa_plik_html) 
{
	char opusc_znak = ' ';
	string linia;
	bool odnosniki[liczba_liter];

	// GENERUJE HEADER
	generuj_header(nazwa_plik_html);

	// GENERUJE TABELE
	fstream plik_dane(nazwa_plik_dane, ios::in);
	fstream plik_html(nazwa_plik_html, ios::out | ios::app);
	Osoba dodawana_osoba;

	plik_dane >> opusc_znak; // OPUSZCZAM PIERWSZY ZNAK #

	// DOPÓKI MOGĘ POBIERAĆ TO WYKONUJE
	while (getline(plik_dane, linia, '#')){
		
		string opusc_wyraz;
		stringstream ss(linia); // TWORZĘ Z TEKSTU STRUMIEŃ TAKI JAK NP. CIN/COUT CZYLI OMIJAM SPACJE TABULATORY I KOLEJNE SŁOWA MOGĘ POBIERAĆ

		ss >> dodawana_osoba.imie;
		ss >> dodawana_osoba.nazwisko;

		ss >> opusc_wyraz; // OPUSZCZAM URODZINY:

		ss >> dodawana_osoba.data_urodzin;
		
		// KONWERTUJĘ DATĘ
		// MA BYĆ dd.mm.rrrr A MOGĄ BYĆ TEŻ rrrr-mm-dd , mm/dd/rrrr
		if (dodawana_osoba.data_urodzin[2] != '.') {
			string dzien, miesiac, rok;
			if (dodawana_osoba.data_urodzin[2] == '/') {
				// mm/dd/rrrr
				rok = dodawana_osoba.data_urodzin.substr(6, 4);
				miesiac = dodawana_osoba.data_urodzin.substr(0, 2);
				dzien = dodawana_osoba.data_urodzin.substr(3, 2);
				dodawana_osoba.data_urodzin = dzien + "." + miesiac + "." + rok;
			}
			else {
				// rrrr-mm-dd
				rok = dodawana_osoba.data_urodzin.substr(0, 4);
				miesiac = dodawana_osoba.data_urodzin.substr(5, 2);
				dzien = dodawana_osoba.data_urodzin.substr(8, 2);
				dodawana_osoba.data_urodzin = dzien + "." + miesiac + "." + rok;
			}
		}
		ss >> opusc_wyraz; // OPUSZCZAM IMIENINY:
		
		// KONWERTUJĘ IMIENINY
		ss >> dodawana_osoba.data_imienin;

		if (dodawana_osoba.data_imienin[2] != '.') {
			string dzien, miesiac;
			if (dodawana_osoba.data_imienin[2] == '/') {
				// mm/dd
				miesiac = dodawana_osoba.data_urodzin.substr(0, 2);
				dzien = dodawana_osoba.data_urodzin.substr(3, 2);
				dodawana_osoba.data_urodzin = dzien + "." + miesiac;
			}
			else {
				// mm-dd
				miesiac = dodawana_osoba.data_urodzin.substr(0, 2);
				dzien = dodawana_osoba.data_urodzin.substr(3, 2);
				dodawana_osoba.data_urodzin = dzien + "." + miesiac;
			}
		}

		ss >> opusc_znak; // OPUSZCZAM '<'
		getline(ss, dodawana_osoba.komentarz, '>');
		ss >> opusc_znak; // OPUSZCZAM '['
		getline(ss, dodawana_osoba.link, ']');

		char odnosnik = toupper(dodawana_osoba.imie[0]); // POBIERAM PIERWSZY ZNAK Z IMIENIA DO LINKOWANIA I OD RAZU WYMUSZAM ŻEBY BYŁ Z WIELKIEJ LITERY
		// DOPISUJĘ WIERSZ W TABELI
		plik_html << "<tr><td><img src=\"" << dodawana_osoba.link << "\"></td><td><a name=\"" << odnosnik << "\">" << dodawana_osoba.imie << "</a></td><td>" << dodawana_osoba.nazwisko << "</td><td>" << dodawana_osoba.data_urodzin << "</td><td>" << dodawana_osoba.data_imienin << "</td><td>" << dodawana_osoba.komentarz << "</td></tr>\n";
		odnosniki[odnosnik - 65] = true; // WYSTĄPIŁA TA LITERKA WIĘC MAMY ODNOŚNIK ( KAŻDA LITERA MA SWÓJ KOD WIADOMO ŻE A - 65 , NP. Z - 90, WIĘC ODEJMUJĘ OD TEGO KODU 65 I ODNOTOWUJĘ W TABLICY ŻE POTRZEBUJĘ TAKIEGO ODNOŚNIKA)
	}
	plik_html << "<div id=\"left\">";
	for (int i = 0; i < liczba_liter; i++) {
		if (odnosniki[i] == true) {
			char literka = i + 65;
			plik_html << "<a href=\"" << nazwa_plik_html << "#" << literka << "\">"<<literka<<"</a></br>\n";
		}
	}
	plik_html<<"</div>\n";
	system("pause");
	plik_html.close();
	plik_dane.close();
	generuj_footer(nazwa_plik_html);
}

int main(int argc, char ** argv)
{
	string nazwa_plik_dane = "", nazwa_plik_html = "";
	if (argc >= 3) {
		nazwa_plik_dane = argv[1];
		nazwa_plik_html = argv[2];
	}
	else {
		cout << "Podaj nazwe pliku z danymi (z rozszerzeniem): ";
		cin >> nazwa_plik_dane;
		cout << "Podaj nazwe pliku docelowego (z rozszerzeniem): ";
		cin >> nazwa_plik_html;
	}

	generuj_html(nazwa_plik_dane, nazwa_plik_html);

	return 0;
}

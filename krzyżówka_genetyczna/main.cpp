#include <iostream>
#include <windows.h>
#include <cstring>
#include <string>

using namespace std;

void sciagawka()

{
	// POKAZUJĘ CECHY NA EKRANIE (ŚCIĄGAWKA)
	cout << "Baza cech (7 REC i 7 DOM): " << endl << endl;
	cout << "Cechy REC: " << "oczy_niebieskie, leworecznosc, piegi, dlugie_rzesy, wlosy_proste, wlosy_blond, brak_grupy_krwi_RH" << endl;
	cout << "Cechy DOM: " << "oczy_piwne, praworecznosc, brak_piegow, krotkie_rzesy, wlosy_krecone, wlosy_ciemne, grupa_krwi_RH" << endl << endl;
}






int main() {

	string cecha;

	// CECHY, Z KTORYCH TWORZYMY KRZYZOWKE - 7 recesywnych i 7 dominujacych 
	string cechaREC[2][7] = {
	{"oczy_niebieskie", "leworecznosc", "piegi", "dlugie_rzesy", "wlosy_proste", "wlosy_blond", "brak_grupy_krwi_RH"},
	{"a","b","c","d","e","f","g"}
	};

	string cechaDOM[2][7] = {
	{"oczy_piwne", "praworecznosc", "brak_piegow", "krotkie_rzesy", "wlosy_krecone", "wlosy_ciemne", "grupa_krwi_RH" },
	{"A","B","C","D","E","F","G"}
	};

	string cechyM[2][6] = { "X","X","X","Y","Y","Y" };
	string cechyK[2][3] = { "X","X","X" };


	// WYWOŁANIE VOID
	sciagawka();





	// MĘŻCZYZNA


	cout << "1. Cechy mezczyzny" << endl << endl;

	for (int i = 0; i < 3; i++) // PODAJE 3 CECHY Z BAZY CZTERNASTU, ANALOGICZNIE DLA KOBIETY I DZIECKA W TESCIE NA OJCOSTWO
	{
		cout << "podaj " << i + 1 << " ceche: ";



		// PĘTLA SPRAWDZA CZY UŻYTKOWNIK DOBRZE WPISAŁ CECHĘ (ANALOGICZNIE DLA KOBIETY I DZIECKA W TEŚCIE NA OJCOSTWO)
		while (cecha != "oczy_niebieskie" and cecha != "oczy_piwne" and cecha != "leworecznosc" and cecha != "praworecznosc" and cecha != "piegi" and cecha != "brak_piegow" and cecha != "dlugie_rzesy" and cecha != "krotkie_rzesy" and cecha != "wlosy_proste" and cecha != "wlosy_krecone" and cecha != "wlosy_blond" and cecha != "wlosy_ciemne" and cecha != "brak_grupy_krwi_RH" and cecha != "grupa_krwi_RH")
		{
			cin >> cecha;

			if (cecha != "oczy_niebieskie" and cecha != "oczy_piwne" and cecha != "leworecznosc" and cecha != "praworecznosc" and cecha != "piegi" and cecha != "brak_piegow" and cecha != "dlugie_rzesy" and cecha != "krotkie_rzesy" and cecha != "wlosy_proste" and cecha != "wlosy_krecone" and cecha != "wlosy_blond" and cecha != "wlosy_ciemne" and cecha != "brak_grupy_krwi_RH" and cecha != "grupa_krwi_RH")
			{
				cout << "\nBlad, wpisz ceche jeszcze raz:" << endl << endl;
			}
		}

		// SZUKA CECH RECESYWNYCH
		for (int r = 0; r < 7; r++)
		{
			if (cecha == cechaREC[0][r])
			{
				// DODAJE CHROMOSOM X
				cechyM[0][i] += cechaREC[1][r];
				// DODAJE CHROMOSOM Y
				cechyM[0][i + 3] += cechaREC[1][r];
				// OPIS CECHY
				cechyM[1][i] = cechaREC[0][r];


			}
		}
		for (int d = 0; d < 7; d++)
		{
			if (cecha == cechaDOM[0][d])
			{
				cechyM[0][i] += cechaDOM[1][d];

				cechyM[0][i + 3] += cechaDOM[1][d];

				cechyM[1][i] = cechaDOM[0][d];
			}
		}
		cout << endl;
		cecha = "";
	}







	//  KOBIETA

	cout << "2. Cechy kobiety" << endl << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "podaj " << i + 1 << " ceche: ";

		while (cecha != "oczy_niebieskie" and cecha != "oczy_piwne" and cecha != "leworecznosc" and cecha != "praworecznosc" and cecha != "piegi" and cecha != "brak_piegow" and cecha != "dlugie_rzesy" and cecha != "krotkie_rzesy" and cecha != "wlosy_proste" and cecha != "wlosy_krecone" and cecha != "wlosy_blond" and cecha != "wlosy_ciemne" and cecha != "brak_grupy_krwi_RH" and cecha != "grupa_krwi_RH")
		{
			cin >> cecha;

			if (cecha != "oczy_niebieskie" and cecha != "oczy_piwne" and cecha != "leworecznosc" and cecha != "praworecznosc" and cecha != "piegi" and cecha != "brak_piegow" and cecha != "dlugie_rzesy" and cecha != "krotkie_rzesy" and cecha != "wlosy_proste" and cecha != "wlosy_krecone" and cecha != "wlosy_blond" and cecha != "wlosy_ciemne" and cecha != "brak_grupy_krwi_RH" and cecha != "grupa_krwi_RH")
			{
				cout << "\nBlad, wpisz ceche jeszcze raz:" << endl << endl;
			}
		}


		for (int r = 0; r < 7; r++)
		{
			if (cechaREC[0][r] == cecha)
			{
				cechyK[0][i] += cechaREC[1][r];

				cechyK[1][i] = cechaREC[0][r];
			}
		}
		for (int d = 0; d < 7; d++)
		{
			if (cecha == cechaDOM[0][d])
			{
				cechyK[0][i] += cechaDOM[1][d];

				cechyK[1][i] = cechaDOM[0][d];
			}
		}
		cout << endl;
		cecha = "";
	}






	// WYŚWIETLANIE KRZYŻÓWKI GENETYCZNEJ

	cout << "3. Potomstwo: " << endl << endl;

	int k = 0, i, j;

	string tab[3][6];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 6; j++)
		{

			tab[i][j] = cechyK[0][i].substr(0, 1) + cechyM[0][j].substr(0, 1) + cechyK[0][i].substr(1, 1) + cechyM[0][j].substr(1, 1);

		}
	}


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 6; j++)
		{
			cout << tab[i][j] << " ";
		}

		// PODPIS CECH 'K' 

		cout << "|" << cechyK[0][i];
		cout << endl;
	}

	// PODPIS CECH 'M'
	for (j = 0; j < 30; j++)
	{
		cout << "-";
	}
	cout << endl;

	for (j = 0; j < 6; j++)
	{

		cout << " " << cechyM[0][j] << "  ";

	}
	cout << endl << endl << endl;






	// LEGENDA 
	for (int d = 0; d < 3; d++)
	{

		for (int a = 0; a < 3; a++)
		{
			if (*cechyM[0][d].rbegin() == *cechyK[0][a].rbegin())
			{
				cechyK[0][a] = "";
			}
		}

		cout << *cechyM[0][d].rbegin() << "   " << cechyM[1][d] << endl;
		cout << *cechyK[0][d].rbegin() << "   " << cechyK[1][d] << endl;

	}
	cout << endl << endl << endl;






	// TEST NA OJCOSTWO





	string Dziecko[3];
	string plec;
	cout << "Podaj plec dziecka: m lub k\n " << endl;
	cin >> plec;
	cout << endl;

	// IMPLEMENTACJA PŁCI DIZECKA

	if (plec == "m")
	{
		Dziecko[0] = "XY";
		Dziecko[1] = "XY";
		Dziecko[2] = "XY";
	}

	else
	{
		Dziecko[0] = "XX";
		Dziecko[1] = "XX";
		Dziecko[2] = "XX";
	}



	// CECHY DZIECKA

	for (int i = 0; i < 3; i++)
	{
		cout << "podaj " << i + 1 << " ceche: ";

		while (cecha != "oczy_niebieskie" and cecha != "oczy_piwne" and cecha != "leworecznosc" and cecha != "praworecznosc" and cecha != "piegi" and cecha != "brak_piegow" and cecha != "dlugie_rzesy" and cecha != "krotkie_rzesy" and cecha != "wlosy_proste" and cecha != "wlosy_krecone" and cecha != "wlosy_blond" and cecha != "wlosy_ciemne" and cecha != "brak_grupy_krwi_RH" and cecha != "grupa_krwi_RH")
		{
			cin >> cecha;
			if (cecha != "oczy_niebieskie" and cecha != "oczy_piwne" and cecha != "leworecznosc" and cecha != "praworecznosc" and cecha != "piegi" and cecha != "brak_piegow" and cecha != "dlugie_rzesy" and cecha != "krotkie_rzesy" and cecha != "wlosy_proste" and cecha != "wlosy_krecone" and cecha != "wlosy_blond" and cecha != "wlosy_ciemne" and cecha != "brak_grupy_krwi_RH" and cecha != "grupa_krwi_RH")
			{
				cout << "\nBlad, wpisz ceche jeszcze raz:" << endl << endl;
			}
		}


		// JEŚLI JEST 'M'

		if (plec == "m") {

			for (int r = 0; r < 7; r++)
			{
				// POSZUKIWANIE CECHY RECESYWNEJ

				if (cecha == cechaREC[0][r])
				{
					Dziecko[i] += cechaREC[1][r] + cechaREC[1][r];
				}
			}
			// POSZUKIWANIE CECHY DOMINUJĄCEJ

			for (int d = 0; d < 7; d++)
			{
				if (cecha == cechaDOM[0][d])
				{
					Dziecko[i] += cechaDOM[1][d] + cechaDOM[1][d];
				}
			}
			cout << endl;
			cecha = "";

		}

		else
		{

			// JEŚLI JEST 'K' 

			for (int r = 0; r < 7; r++)
			{

				// POSZUKIWANIE CECHY RECESYWNEJ

				if (cecha == cechaREC[0][r])
				{
					Dziecko[i] += cechaREC[1][r] + cechaREC[1][r];


				}
			}

			// POSZUKIWANIE CECHY DOMINUJĄCEJ

			for (int d = 0; d < 7; d++)
			{
				if (cecha == cechaDOM[0][d])
				{
					Dziecko[i] += cechaDOM[1][d] + cechaDOM[1][d];


				}
			}
			cout << endl;
			cecha = "";

		}
		cout << endl;
		cecha = "";
	}

	// POSZUKIWANIE RODZICA 

	for (int l = 0; l < 3; l++)
	{

		cout << Dziecko[l] << " ";

	}

	bool moze = false;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 6; j++)
		{
			for (int l = 0; l < 3; l++)
			{


				if (Dziecko[l] == tab[i][j])
				{
					moze = true;
				}


			}
		}

	}


	// KOMUNIKAT O OJCOSTWIE 

	if (moze == false)
		cout << " \n\nNie moga miec tego dziecka" << endl;
	else
		cout << " \n\nTo ich dziecko" << endl;


	cout << "\nWcisnij dwolny klawisz";
	cin.sync(); cin.get();

	return 0;
}

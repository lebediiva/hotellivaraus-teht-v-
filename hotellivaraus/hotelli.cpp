// Maria Lebedeva 24TietoB
// Hotellivaraus teht‰v‰

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int max_huoneet = 70;
const int min_huoneet = 30;
const int max_hinta_yolta = 100;
const int min_hinta_yolta = 80;
const int min_varausnumero = 10000;
const int max_varausnumero = 99999; 

struct huonenumero {
	bool varattu; // tarkistetaan onks huone jo varattu
	int hinta;
};
void tulostatiedot(const vector <huonenumero>& huoneet) {
	for (int i = 0; i < huoneet.size(); ++i) {
		std::cout << "huonenumero " << i + 1 << "hinta: " << huoneet[i].hinta << "Ä";
		std:: cout << (huoneet[i].varattu ? "varattu" : "vapaa") << endl;

	}

 }
bool tarkistavaraus(const vector < huonenumero>& huoneet, int huonenumero) {
	return huoneet[huonenumero - 1].varattu;

}

int teevarausnumero() {

	return rand() % (max_varausnumero - min_varausnumero + 1) + min_varausnumero;

}

int main() { // nyt alkaa p‰‰ohjelma 

	srand(time(0)); // satunnaislukuja
	// arvotaan paljon on huoneita ja mit‰ ne maksaa

	int huoneidenmaara = rand() % (max_huoneet - min_huoneet + 1) + min_huoneet;
	int yonhinta = rand() % (max_hinta_yolta - min_hinta_yolta + 1) + min_hinta_yolta;

	// annetaan huoneet 
	vector <huonenumero> huoneet(huoneidenmaara);
	for (int i = 0; i < huoneidenmaara; ++i) {
		huoneet[i].varattu = false; // aluks ne vapaana 
		huoneet[i].hinta = yonhinta;
	}
	string varaajannimi;
	int valinta;
	bool jatka = true;

	while (jatka) {
		std:: cout << "\n Tervetuloa Marian omaan hotelliin. Varataas sulle huone" << endl;
		std:: cout << "1. n‰yt‰ huoneet " << endl;
		std:: cout << "2. varaa huone" << endl;
		std:: cout << "3. valmis!" << endl;
		std:: cout << "valitse toiminto (1-3):";
		std:: cin >> valinta;
		std::cin.ignore();

		


		switch (valinta) {
		case 1:
			tulostatiedot(huoneet);
			break;

		case 2:
			{
			int huonenumero, yot;

			// kysyt‰‰n varaajan nimi

			std:: cout << "Anna varaajan nimi:";
			getline(cin, varaajannimi);

			// arvotaan varausnumero 
			int varausnumero = teevarausnumero();
			std :: cout << "varausnumerosi on :" << varausnumero << endl;

			// sit kysyn sun huonenumeron
			std:: cout << "anna huoneen numero (1-" << huoneidenmaara << "):";
			cin >> huonenumero;


			if (huonenumero < 1 || huonenumero >  huoneidenmaara) {
				std:: cout << "ei k‰y, anna toinen huonenumero :(" << endl;
				break;
			}

				if (huonenumero < 1 || huonenumero >  huoneidenmaara) {
					std:: cout << "t‰‰ huone on jo varattu, valitse uusi" << endl;
				}
				else {
					std:: cout << "monta yota haluut olla taalla";
					cin >> yot;

					if (yot <= 0) {
						std:: cout << "ei k‰y" << endl;
						break;
					}

					// merkkaan huoneen varatuks
					huoneet[huonenumero - 1].varattu = true;

					// lasketaan lopullinen hinta (ilman tippi‰ :/)

					int loppusumma = huoneet[huonenumero - 1].hinta * yot;
					std:: cout << "hinta huoneelle " << huonenumero << "on" << loppusumma << "euroa" << endl;

					// varaajan nimi ja varausnumero n‰kkyy t‰ss‰

					std:: cout << "\nKiitos varauksesta! " << endl;
					std:: cout << "varaajan nimi:" << varaajannimi << endl;
					std:: cout << "varausnumerosi:" << varausnumero << endl;
				}
				break;
			}
		case 3:
			jatka = false;
			std:: cout << "Kiitti t marian oma hotelli" << endl;
			break;

		default:
			std:: cout << "ei k‰y!" << endl;
			break;
		}
	}
	return 0;
}






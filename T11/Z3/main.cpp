/*
    TP 16/17 (Tutorijal 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>

class Tim
{
	char ime_tima[20];
	int broj_odigranih;
	int broj_pobjeda;
	int broj_nerijesenih;
	int broj_poraza;
	int broj_datih;
	int broj_primljenih;
	int broj_poena;
public:
	Tim(const char ime[]);
	void ObradiUtakmicu(int dati, int primljeni);
	const char *DajImeTima() const
	{
		return ime_tima;
	}
	int DajBrojPoena() const
	{
		return broj_poena;
	}
	int DajGolRazliku() const
	{
		return broj_datih-broj_primljenih;
	}
	void IspisiPodatke() const;
};

Tim::Tim(const char ime[])
{
	if(std::strlen(ime)>=20) throw std::range_error("Predugacko ime tima");
	std::strcpy(ime_tima, ime);
	broj_odigranih=0;
	broj_pobjeda=0;
	broj_nerijesenih=0;
	broj_poraza=0;
	broj_datih=0;
	broj_primljenih=0;
	broj_poena=0;
}

void Tim::ObradiUtakmicu(int dati, int primljeni)
{
	if(dati<0 || primljeni<0) throw std::range_error("Neispravan broj golova");
	broj_odigranih++;
	broj_datih=broj_datih+dati;
	broj_primljenih=broj_primljenih+primljeni;

	if(dati>primljeni) {
		broj_pobjeda++;
		broj_poena=broj_poena+3;
	} else if(dati==primljeni) {
		broj_nerijesenih++;
		broj_poena=broj_poena+1;
	} else {
		broj_poraza++;
	}
}

void Tim::IspisiPodatke() const
{
	std::cout << std::left << std::setw(20) << DajImeTima();
	std::cout << std::right << std::setw(4) << broj_odigranih;
	std::cout << std::right << std::setw(4) << broj_pobjeda;
	std::cout << std::right << std::setw(4) << broj_nerijesenih;
	std::cout << std::right << std::setw(4) << broj_poraza;
	std::cout << std::right << std::setw(4) << broj_datih;
	std::cout << std::right << std::setw(4) << broj_primljenih;
	std::cout << std::right << std::setw(4) << broj_poena << std::endl;
}

int main ()
{
	Tim t1("FK Sarajevo");
	Tim t2("HSK Zrinjski");
	Tim t3("FK Olimpik");

	t1.ObradiUtakmicu(1, 0);
	t1.ObradiUtakmicu(3, 0);
	t2.ObradiUtakmicu(1, 1);
	t2.ObradiUtakmicu(1, 0);
	t3.ObradiUtakmicu(0, 1);
	t3.ObradiUtakmicu(0, 2);

	t1.IspisiPodatke();
	t2.IspisiPodatke();
	t3.IspisiPodatke();
	return 0;
}

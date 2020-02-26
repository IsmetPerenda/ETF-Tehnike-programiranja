/* 
    TP 16/17 (Tutorijal 11, Zadatak 5)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>

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





class Liga
{
	std::vector<std::shared_ptr<Tim>> timovi;

	int DaLiJePronadjenTim(const char* ime_tima) const
	{
		for(int i=0; i<timovi.size(); i++) {
			if(std::strcmp(ime_tima, timovi[i]->DajImeTima())==0) return i;
		}
		return -1;
	}
public:
	explicit Liga()=default;

	explicit Liga(std::initializer_list<Tim> lista_timova)
	{
		try{
			for(auto it=lista_timova.begin(); it!=lista_timova.end(); it++){
				timovi.push_back(std::make_shared<Tim>(*it));
			}
		}
		catch(...){
			throw;
		}
	}

	Liga(const Liga &l) : timovi(l.timovi.size())
	{
		for(int i=0; i<l.timovi.size(); i++){
			timovi[i]=std::make_shared<Tim>(*l.timovi[i]);
		}
	}

	Liga(Liga &&l) =default;

	Liga &operator =(const Liga &l)
	{
		if(&l==this) return *this;
		timovi.resize(l.timovi.size());
		try{
			for(int i=0; i<l.timovi.size(); i++){
				timovi[i]=std::make_shared<Tim>(*l.timovi[i]);
			}
		}
		catch(...){
			throw;
		}
		return *this;
	}

	Liga &operator = (Liga &&l) =default;
	
	void DodajNoviTim(const char ime_tima[])
	{
		if(DaLiJePronadjenTim(ime_tima)!=-1) throw std::logic_error("Tim je vec u ligi");
		try {
			timovi.push_back(std::make_shared<Tim>(ime_tima));
		} catch(...) {
			throw;
		}
	}

	void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
	{
		if(DaLiJePronadjenTim(tim1)==-1 || DaLiJePronadjenTim(tim2)==-1) throw std::logic_error("Tim nije nadjen");
		if(rezultat_1<0 || rezultat_2<0) throw std::range_error("Neispravan broj golova");
		timovi[DaLiJePronadjenTim(tim1)]->ObradiUtakmicu(rezultat_1, rezultat_2);
		timovi[DaLiJePronadjenTim(tim2)]->ObradiUtakmicu(rezultat_2, rezultat_1);
	}
	void IspisiTabelu()
	{
		std::sort(timovi.begin(), timovi.end(), [](std::shared_ptr<Tim> tim1, std::shared_ptr<Tim> tim2) {
			if(tim1->DajBrojPoena()>tim2->DajBrojPoena()) return true;
			if(tim1->DajBrojPoena()<tim2->DajBrojPoena()) return false;
			if(tim1->DajGolRazliku()>tim2->DajGolRazliku()) return true;
			if(tim1->DajGolRazliku()<tim2->DajGolRazliku()) return false;
			if(strcmp(tim1->DajImeTima(), tim2->DajImeTima())<0) return true;
			if(strcmp(tim1->DajImeTima(), tim2->DajImeTima())>0) return false;
			return false;
		});
		
		for(int i=0; i<timovi.size(); i++){
			timovi[i]->IspisiPodatke();
		}
	}
};


int main ()
{
	Liga l1{"FK Sarajevo", "HSK Zrinjski", "NK Zeljeznicar", "FK Sloboda", "FK Krupa", "FK Borac"};
	l1.RegistrirajUtakmicu("NK Zeljeznicar", "HSK Zrinjski",0,2);
	l1.RegistrirajUtakmicu("FK Sarajevo", "HSK Zrinjski",4,0);
	l1.RegistrirajUtakmicu("FK Sloboda", "FK Borac",3,1);
	l1.RegistrirajUtakmicu("FK Krupa", "FK Sloboda",4,4);
	l1.RegistrirajUtakmicu("FK Borac", "NK Zeljeznicar",2,2);
	l1.RegistrirajUtakmicu("FK Borac", "FK Sarajevo",2,3);
	Liga l2(l1);

	std::cout << "Orginalna Liga za Prvaka: " << std::endl;
	l1.IspisiTabelu();
	std::cout << std::endl << "Kopija Lige za Prvaka: " << std::endl;
	l2.IspisiTabelu();

	l2.RegistrirajUtakmicu("NK Zeljeznicar", "HSK Zrinjski",2,2);
	l2.RegistrirajUtakmicu("FK Sarajevo", "HSK Zrinjski",4,3);
	l2.RegistrirajUtakmicu("FK Sloboda", "FK Borac",3,2);
	l2.RegistrirajUtakmicu("FK Krupa", "FK Sloboda",3,1);
	l2.RegistrirajUtakmicu("FK Borac", "NK Zeljeznicar",3,2);
	l1.RegistrirajUtakmicu("FK Borac", "FK Sarajevo",2,5);

	std::cout << std::endl << "Nakon izmjene kopije: " << std::endl << std::endl;

	std::cout << "Orginalna Liga za Prvaka: " << std::endl;
	l1.IspisiTabelu();
	std::cout << std::endl << "Kopija Lige za Prvaka: " << std::endl;
	l2.IspisiTabelu();
	return 0;
}
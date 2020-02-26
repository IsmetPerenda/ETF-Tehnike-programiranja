/*
    TP 16/17 (Tutorijal 11, Zadatak 4)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <initializer_list>
#include <algorithm>

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
	int broj_timova;
	int max_br_timova;
	mutable Tim **timovi;

	int DaLiJePronadjenTim(const char* ime_tima) const
	{
		for(int i=0; i<broj_timova; i++) {
			if(std::strcmp(ime_tima, timovi[i]->DajImeTima())==0) return i;
		}
		return -1;
	}
public:
	explicit Liga(int velicina_lige) : broj_timova(0), max_br_timova(velicina_lige), timovi(nullptr)
	{
		try {
			timovi=new Tim*[max_br_timova];
		} catch(...) {
			if(timovi==nullptr) return;
			for(int i=0; i<broj_timova; i++) {
				delete timovi[i];
			}
			delete[] timovi;
		}
	}

	explicit Liga(std::initializer_list<Tim> lista_timova) : max_br_timova(lista_timova.size()), broj_timova(lista_timova.size())
	{
		timovi=new Tim*[lista_timova.size()];
		int i=0;
		try {
			for(auto it=lista_timova.begin(); it!=lista_timova.end(); it++) {
				timovi[i]=new Tim(*it);
				i++;
			}
		} catch(...) {
			if(timovi==nullptr) return;
			for(int i=0; i<broj_timova; i++) {
				delete timovi[i];
			}
			delete[] timovi;
		}
	}

	~Liga()
	{
		for(int i=0; i<broj_timova; i++) {
			delete timovi[i];
		}
		delete[] timovi;
	}

	Liga(const Liga &l) : timovi(new Tim*[l.max_br_timova] {}), broj_timova(l.broj_timova), max_br_timova(l.max_br_timova)
	{
		try {
			for(int i=0; i<l.broj_timova; i++) {
				timovi[i]=new Tim(*l.timovi[i]);
			}
		} catch(...) {
			for(int i=0; i<l.broj_timova; i++) {
				delete timovi[i];
			}
			delete[] timovi;
		}
	}

	Liga(Liga &&l) : max_br_timova(l.max_br_timova), broj_timova(l.broj_timova)
	{
		timovi=l.timovi;
		l.broj_timova=0;
		l.timovi=nullptr;
	}

	Liga &operator =(const Liga &l)
	{
		if(max_br_timova!=l.max_br_timova) throw std::logic_error("Nesaglasni kapaciteti liga");
		if(&l==this) return *this;
		for(int i=0; i<broj_timova; i++) {
			delete timovi[i];
		}
		broj_timova=l.broj_timova;

		try {
			for(int i=0; i<broj_timova; i++) {
				timovi[i]=new Tim(*l.timovi[i]);
			}
		} catch(...) {
			for(int i=0; i<broj_timova; i++) {
				delete timovi[i];
			}
			delete[] timovi;
		}
	}

	Liga &operator = (Liga &&l)
	{
		if(l.max_br_timova==max_br_timova) {
			max_br_timova=l.max_br_timova;
			broj_timova=l.broj_timova;
			std::swap(timovi, l.timovi);
			l.timovi=nullptr;
			return *this;
		} else throw std::logic_error("Nesaglasni kapaciteti liga");
	}
	void DodajNoviTim(const char ime_tima[])
	{
		if(broj_timova==max_br_timova) throw std::range_error("Liga popunjena");
		if(DaLiJePronadjenTim(ime_tima)!=-1) throw std::logic_error("Tim je vec u ligi");
		try {
			timovi[broj_timova++]=new Tim(ime_tima);
		} catch(...) {
			broj_timova--;
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
		std::sort(timovi, timovi+broj_timova, [](Tim *tim1, Tim *tim2) {
			if(tim1->DajBrojPoena()>tim2->DajBrojPoena()) return true;
			if(tim1->DajBrojPoena()<tim2->DajBrojPoena()) return false;
			if(tim1->DajGolRazliku()>tim2->DajGolRazliku()) return true;
			if(tim1->DajGolRazliku()<tim2->DajGolRazliku()) return false;
			if(strcmp(tim1->DajImeTima(), tim2->DajImeTima())<0) return true;
			if(strcmp(tim1->DajImeTima(), tim2->DajImeTima())>0) return false;
			return false;
		});

		for(int i=0; i<broj_timova; i++) {
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
	Liga l2(l1);

	std::cout << "Orginalna Liga za Prvaka: " << std::endl;
	l1.IspisiTabelu();
	std::cout << std::endl << "Kopija Lige za Prvaka: " << std::endl;
	l2.IspisiTabelu();

	l2.RegistrirajUtakmicu("FK Krupa", "FK Sloboda",1,1);
	l2.RegistrirajUtakmicu("FK Sarajevo", "FK Sloboda",2,1);

	std::cout << std::endl << "Nakon izmjene kopije: " << std::endl << std::endl;

	std::cout << "Orginalna Liga za Prvaka: " << std::endl;
	l1.IspisiTabelu();
	std::cout << std::endl << "Kopija Lige za Prvaka: " << std::endl;
	l2.IspisiTabelu();
	return 0;
}

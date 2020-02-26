/*
    TP 16/17 (Tutorijal 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class StedniRacun
{
	double stanje;
	static int kreirani;
	static int aktivni;
public:
	StedniRacun()
	{
		stanje=0;
		kreirani++;
		aktivni++;
	}
	StedniRacun(double x)
	{
		if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		stanje=x;
		kreirani++;
		aktivni++;
	}
	StedniRacun(const StedniRacun &racun)
	{
		if(racun.stanje<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		stanje=racun.stanje;
		kreirani++;
		aktivni++;
	}
	~StedniRacun()
	{
		aktivni--;
	}
	void Ulozi(double x)
	{
		if(-x>stanje) throw std::logic_error("Transakcija odbijena");
		else stanje+=x;
	}
	void Podigni(double x)
	{
		if(x>stanje) throw std::logic_error("Transakcija odbijena");
		else stanje-=x;
		//return Ulozi(-x);											Pozivamo funkciju Ulozi unutar Podigni
	}
	double DajStanje()
	{
		return stanje;
	}
	void ObracunajKamatu(double x)
	{
		if(x<0) throw std::logic_error("Nedozvoljena kamatna stopa");
		else stanje+=stanje*(x/100);
	}
	static int DajBrojKreiranih()
	{
		return kreirani;
	}
	static int DajBrojAktivnih()
	{
		return aktivni;
	}
};

int StedniRacun::aktivni=0;
int StedniRacun::kreirani=0;

int main ()
{
	StedniRacun s1, s2(100);
	{ StedniRacun s3(50); }
	std::cout << StedniRacun::DajBrojKreiranih() << " " << StedniRacun::DajBrojAktivnih();
 	return 0;
}

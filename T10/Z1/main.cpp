/*
    TP 16/17 (Tutorijal 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class StedniRacun
{
	double stanje;
public:
	StedniRacun()
	{
		stanje=0;
	}
	StedniRacun(double x)
	{
		if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		else stanje=x;
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
};


int main ()
{
	try {
		StedniRacun s1=20;
		StedniRacun s2(100);
		StedniRacun s3;
		s1.Ulozi(100);

		std::cout << s1.DajStanje() << std::endl;
		std::cout << s2.DajStanje() << std::endl;
		std::cout << s3.DajStanje() << std::endl;

		try {
			s1.Podigni(100);
			std::cout << s1.DajStanje() << std::endl;
		} catch(std::logic_error e) {
			std::cout << e.what();
		}
	} catch(std::logic_error e) {
		std::cout << e.what();
	}
	return 0;
}

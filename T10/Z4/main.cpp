/* 
    TP 16/17 (Tutorijal 10, Zadatak 4)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

int Pretvori(double ugao){
	return ugao*180/(4*atan(1))*60*60+0.0000000001;
}

double OsnovniPeriod(double ugao){
	while(ugao<0){
		ugao=ugao+2*4*atan(1);
	}
	while(ugao>=2*4*atan(1)){
		ugao=ugao-2*4*atan(1);
	}
	
	return ugao;
}

class Ugao {
	double ugao;
	public:
	Ugao(double radijani=0) { ugao=OsnovniPeriod(radijani); }
	Ugao(int stepeni, int minute, int sekunde){
		ugao=OsnovniPeriod(4*atan(1)/180*(double(stepeni)+double(minute/60.)+double(sekunde/3600.)));
	}
	void Postavi(double radijani) { ugao=OsnovniPeriod(radijani); }
	void Postavi(int stepeni, int minute, int sekunde){
		ugao=OsnovniPeriod(4*atan(1)/180*(double(stepeni)+double(minute/60.)+double(sekunde/3600.)));
	}
	double DajRadijane() const { return ugao; }
	void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde){
		stepeni=int(ugao*180/(4*atan(1)));
		minute=int(ugao*180/(4*atan(1))*60);
		sekunde=int(ugao*180/(4*atan(1))*60*60);
	}
	int DajStepene() const { return Pretvori(ugao)/3600; }
	int DajMinute() const { return (Pretvori(ugao)/60)%60; }
	int DajSekunde() const { return (Pretvori(ugao)%60); }
	void Ispisi() const { std::cout << std::fixed << std::setprecision(5) << DajRadijane(); }
	void IspisiKlasicno() const { std::cout << DajStepene() << "deg " << DajMinute() << "min " << DajSekunde() << "sec"; }
	Ugao &SaberiSa(const Ugao &u){
		double rez=OsnovniPeriod(u.DajRadijane()+ugao)+0.00000005;
		Postavi(rez);
		return *this;
	}
	Ugao &PomnoziSa(double x){
		double rez=OsnovniPeriod(x*ugao);
		Postavi(rez);
		return *this;
	}
	friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
};

Ugao ZbirUglova(const Ugao &u1, const Ugao &u2){
	Ugao u;
	double ugao=u1.DajRadijane()+u2.DajRadijane();
	u.Ugao::Postavi(ugao);
	return u;
}

Ugao ProduktUglaSaBrojem(const Ugao &u, double x){
	Ugao rez;
	double produkt=u.DajRadijane()*x;
	rez.Ugao::Postavi(produkt);
	return rez;
}


int main ()
{
	Ugao u(30, 0, 30);
	u.Ispisi();
	u.IspisiKlasicno();
	
	int a,b,c;
	u.OcitajKlasicneJedinice(a,b,c);
	
	Ugao u1;
	
	u.SaberiSa(u1);
	std::cout << std::endl;
	u.PomnoziSa(5);
	std::cout << std::endl;
	u.IspisiKlasicno();
	
	auto rez=ZbirUglova(u1, u);
	rez.IspisiKlasicno();
	
	rez=ProduktUglaSaBrojem(u1, 4);
	rez.Ispisi();
	
	return 0;
}
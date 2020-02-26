/* 
    TP 16/17 (Tutorijal 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

class Krug {
	double r;
	public:
	explicit Krug(double x) { if(x<=0) throw std::domain_error("Neispravan poluprecnik"); else r=x; }
	void Postavi(double x) { if(x<=0) throw std::domain_error("Neispravan poluprecnik"); else r=x; }
	double DajPoluprecnik() const { return r; }
	double DajObim() const { return 2*r*4*atan(1); }
	double DajPovrsinu() const { return r*r*4*atan(1); }
	void Skaliraj(double s) { if(s<=0) throw std::domain_error("Neispravan faktor skaliranja"); else r*=s; }
	void Ispisi() const {
		std::cout << "R=" << std::fixed << std::setprecision(5) << DajPoluprecnik();
		std::cout << " O=" << std::fixed << std::setprecision(5) << DajObim();
		std::cout << " P=" << std::fixed << std::setprecision(5) << DajPovrsinu();
	}
};

class Valjak {
	Krug baza{1};
	double visina;
	public:
	explicit Valjak(double r, double h){
		if(r<=0) throw std::domain_error("Neispravan poluprecnik");
		if(h<=0) throw std::domain_error("Neispravna visina");
		baza=Krug(r); visina=h;
	}
	void Postavi(double r, double h){
		if(r<=0) throw std::domain_error("Neispravan poluprecnik");
		if(h<=0) throw std::domain_error("Neispravna visina");
		baza=Krug(r);
		visina=h;
	}
	Krug DajBazu() const { return baza; }
	double DajPoluprecnikBaze() const { return baza.DajPoluprecnik(); }
	double DajVisinu() const { return visina; }
	double DajPovrsinu() const { return baza.DajPovrsinu()*2+baza.DajObim()*visina; }
	double DajZapreminu() const { return baza.DajPovrsinu()*visina; }
	void Skaliraj(double s) {
		if(s<=0) throw std::domain_error("Neispravan faktor skaliranja");
		else{
			baza.Postavi(baza.DajPoluprecnik()*s);
			visina*=s;
		}
	}
	void Ispisi() const {
		std::cout << "R=" << std::fixed << std::setprecision(5) << DajPoluprecnikBaze();
		std::cout << " H=" << std::fixed << std::setprecision(5) << DajVisinu();
		std::cout << " P=" << std::fixed << std::setprecision(5) << DajPovrsinu();
		std::cout << " V=" << std::fixed << std::setprecision(5) << DajZapreminu(); 
	}
};


int main ()
{
	try{
	Krug k1(5);
	Valjak v1(3,4);
	
	const Krug k2(k1);
	const Valjak v2(v1);
	
	k2.Ispisi();
	std::cout << std::endl;
	
	v2.Ispisi();
	std::cout << std::endl;
	
	k1.Skaliraj(-1);
	v1.Skaliraj(-1);
	}
	catch(std::domain_error e){
		std::cout << e.what();
	}
	
	return 0;
}
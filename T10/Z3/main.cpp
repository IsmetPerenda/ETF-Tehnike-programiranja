/* 
    TP 16/17 (Tutorijal 10, Zadatak 3)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>

class Vektor3d{
	double koordinate[3];
	mutable int brojac=0;
	public:
	Vektor3d() { Vektor3d::koordinate[0]=0; Vektor3d::koordinate[1]=0; Vektor3d::koordinate[2]=0; }
	Vektor3d(double x, double y, double z) { Vektor3d::koordinate[0]=x; Vektor3d::koordinate[1]=y; Vektor3d::koordinate[2]=z; }
	Vektor3d(const Vektor3d &v) { koordinate[0]=v.koordinate[0]; koordinate[1]=v.koordinate[1]; koordinate[2]=v.koordinate[2]; }
	void Postavi(double x, double y, double z){
		koordinate[0]=x; koordinate[1]=y; koordinate[2]=z;
	}
	void Ocitaj(double &x, double &y, double &z) const{
		x=koordinate[0], y=koordinate[1]; z=koordinate[2];
	}
	void Ispisi() const{
		std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
		brojac++;
	}
	double DajX() const { return koordinate[0]; }
	double DajY() const { return koordinate[1]; }
	double DajZ() const { return koordinate[2]; }
	double DajDuzinu() const { return std::sqrt(koordinate[0]*koordinate[0]+koordinate[1]*koordinate[1]+koordinate[2]*koordinate[2]); }
	Vektor3d &PomnoziSaSkalarom(double s) { koordinate[0]*=s; koordinate[1]*=s; koordinate[2]*=s; return *this;}
	Vektor3d &SaberiSa(const Vektor3d &v) { koordinate[0]+=v.koordinate[0]; koordinate[1]+=v.koordinate[1]; koordinate[2]+=v.koordinate[2]; return *this;}
	friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
	void PostaviX(double x) { koordinate[0]=x; };
	void PostaviY(double y) { koordinate[1]=y; };
	void PostaviZ(double z) { koordinate[2]=z; };
	int DajBrojIspisa() const { return brojac; }
};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2){
	Vektor3d v;
	v.koordinate[0]=v1.koordinate[0]+v2.koordinate[0]; v.koordinate[1]=v1.koordinate[1]+v2.koordinate[1]; v.koordinate[2]=v1.koordinate[2]+v2.koordinate[2];
	return v;
}


int main ()
{
	Vektor3d v1, v2;
	v1.Postavi(3, 4, 5);
	v2.Postavi(7, 3, 2);
	std::cout << v1.DajDuzinu() << std::endl;
	v1.PomnoziSaSkalarom(5);
	v1.Ispisi();
	std::cout << std::endl;
	v1.SaberiSa(v2);
	v2.Ispisi();
	
	Vektor3d v3;
	v3.Postavi(1, 2, 3);
	v3.Ispisi();
	v3.Ispisi();
	v3.Ispisi();
	
	Vektor3d v4{v3};
	v4.Ispisi();
	v4.Ispisi();
	
	std::cout << std::endl;
	
	std::cout << v4.DajBrojIspisa();
	return 0;
}
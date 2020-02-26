/* 
    TP 16/17 (Tutorijal 10, Zadatak 5)
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
	int deg;
	int min;
	int sec;
	public:
	Ugao(double radijani=0){
		radijani=OsnovniPeriod(radijani);
		deg=Pretvori(radijani)/3600;
		min=int(Pretvori(radijani)/60)%60;
		sec=int(Pretvori(radijani))%60;
	}
	Ugao(int stepeni, int minute, int sekunde){
		while(sekunde>=60){
			sekunde-=60;
			minute+=1;
		}
		while(sekunde<0){
			sekunde+=60;
			minute-=1;
		}
		while(minute>=60){
			minute-=60;
			stepeni+=1;
		}
		while(minute<0){
			minute+=60;
			stepeni-=1;
		}
		while(stepeni>=360){
			stepeni-=360;
		}
		while(stepeni<0){
			stepeni+=360;
		}
		deg=stepeni;
		min=minute;
		sec=sekunde;
	}
	void Postavi(double radijani){
		radijani=OsnovniPeriod(radijani);
		double rez=Pretvori(radijani);
		deg=rez/3600;
		min=int(rez/60)%60;
		sec=int(rez)%60;
	}
	void Postavi(int stepeni, int minute, int sekunde){
		while(sekunde>=60){
			sekunde-=60;
			minute+=1;
		}
		while(sekunde<0){
			sekunde+=60;
			minute-=1;
		}
		while(minute>=60){
			minute-=60;
			stepeni+=1;
		}
		while(minute<0){
			minute+=60;
			stepeni-=1;
		}
		while(stepeni>=360){
			stepeni-=360;
		}
		while(stepeni<0){
			stepeni+=360;
		}
		deg=stepeni;
		min=minute;
		sec=sekunde;
	}
	double DajRadijane() const{
		double rez;
		rez=(deg+min/60.+sec/3600.)*4*atan(1)/180;
		return rez;
	}
	void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde){
		stepeni=DajStepene();
		minute=DajMinute();
		sekunde=DajSekunde();
	}
	int DajStepene() const { return deg; }
	int DajMinute() const { return min; }
	int DajSekunde() const { return sec; }
	void Ispisi() const { std::cout << std::fixed << std::setprecision(5) << DajRadijane(); }
	void IspisiKlasicno() const { std::cout << DajStepene() << "deg " << DajMinute() << "min " << DajSekunde() << "sec"; }
	Ugao &SaberiSa(const Ugao &u){
		Postavi(DajRadijane()+u.DajRadijane());
		return *this;
	}
	Ugao &PomnoziSa(double x){
		Postavi(DajRadijane()*x);
		return *this;
	}
	friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
};

Ugao ZbirUglova(const Ugao &u1, const Ugao &u2){
	Ugao rez=(u1.DajRadijane()+u2.DajRadijane()+0.0000000001);
	return rez;
}

Ugao ProduktUglaSaBrojem(const Ugao &u, double x){
	Ugao rez=(u.DajRadijane()*x);
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
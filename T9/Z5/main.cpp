/* 
    TP 16/17 (Tutorijal 9, Zadatak 5)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <iomanip>

class Sat{
	int sekundi;
	
	public:
	static bool DaLiJeIspravno(int sati, int minuta, int sekundi){
		if(sati<0 || sati>23 || minuta<0 || minuta>59 || sekundi<0 || sekundi>59) return false;
		return true;
	}
	void Postavi(int sat, int min, int sec){
		if(!DaLiJeIspravno(sat,min,sec)){
			throw std::domain_error("Neispravno vrijeme");
		}
		Sat::sekundi=sat*60*60+min*60+sec;
	}
	void PostaviNormalizirano(int sat, int min, int sec);
	Sat Sljedeci();
	Sat Prethodni();
	Sat PomjeriZa(int br);
	void Ispisi() const { 
		std::cout << std::setw(2) << std::setfill('0') << DajSate() << ":";
		std::cout << std::setw(2) << std::setfill('0') << DajMinute() << ":";
		std::cout << std::setw(2) << std::setfill('0') << DajSekunde();
	}
	int DajSate() const { return sekundi/3600%24; };
	int DajMinute() const { return sekundi%3600/60%60; };
	int DajSekunde() const { return sekundi%3600%60; };
	friend int BrojSekundiIzmedju(Sat sat1, Sat sat2);
	static int Razmak(const Sat sat1, const Sat sat2);
};

void Sat::PostaviNormalizirano(int sat, int min, int sec){
	if(sec<0){																//provjerimo da li su sekunde manje od 0
		sec=sec%60+60;
		if(min==0) min=59;
		else min=min-1;
		if(min==59){
			if(sat==0) sat=23;
			else sat=sat-1;
		}
	}
	if(min<0){																//provjerimo da li su minute manje od 0
		min=min%60+60;
		if(sat==0) sat=23;
		else sat=sat-1;
	}
	if(sat<0) sat=sat%24+24;														//provjerimo da li su sati manji od 0
	
	Sat::sekundi=sat*60*60+min*60+sec;
}

Sat Sat::Sljedeci(){
	sekundi=sekundi+1;
	Sat::PostaviNormalizirano(DajSate(), DajMinute(), DajSekunde());
	
	return *this;
}

Sat Sat::Prethodni(){
	sekundi=sekundi-1;
	Sat::PostaviNormalizirano(DajSate(), DajMinute(), DajSekunde());
	
	return *this;
}

int BrojSekundiIzmedju(Sat sat1, Sat sat2){
	int ukupno;
	ukupno=sat1.sekundi-sat2.sekundi;
	return ukupno;
}

int Sat::Razmak(Sat sat1, Sat sat2){
	/*int ukupno;
	ukupno=sat1.sekundi-sat2.sekundi;
	return ukupno;*/
	return BrojSekundiIzmedju(sat1, sat2);
}

Sat Sat::PomjeriZa(int br){
	sekundi=sekundi+br;
	Sat::PostaviNormalizirano(DajSate(), DajMinute(), DajSekunde());
	
	return *this;
}

int main ()
{
	Sat sat1;
	Sat sat2;
	
	sat1.Postavi(20,50,59);
	sat2.Postavi(4,3,2);
	
	sat1.Ispisi();
	std::cout << std::endl;
	
	sat2.Ispisi();
	std::cout << std::endl;
	
	std::cout << BrojSekundiIzmedju(sat1, sat2) << std::endl;
	
	sat1.Sljedeci();
	sat1.Ispisi();
	
	std::cout << std::endl;
	
	sat2.Sljedeci();
	sat2.Ispisi();
	
	return 0;
}
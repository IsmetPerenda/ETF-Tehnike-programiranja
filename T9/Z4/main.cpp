/* 
    TP 16/17 (Tutorijal 9, Zadatak 4)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <iomanip>

class Sat{
	int sati;
	int minuta;
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
		Sat::sati=sat;
		Sat::minuta=min;
		Sat::sekundi=sec;
	}
	void PostaviNormalizirano(int sat, int min, int sec);
	Sat Sljedeci();
	Sat Prethodni();
	Sat PomjeriZa(int br);
	void Ispisi() const { 
		std::cout << std::setw(2) << std::setfill('0') << sati << ":";
		std::cout << std::setw(2) << std::setfill('0') << minuta << ":";
		std::cout << std::setw(2) << std::setfill('0') << sekundi;
	}
	int DajSate() const { return sati; };
	int DajMinute() const { return minuta; };
	int DajSekunde() const { return sekundi; };
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
	
	Sat::sekundi=sec%60;
	Sat::minuta=(min+sec/60)%60;
	Sat::sati=(sat+(min+sec/60)/60)%24;
}

Sat Sat::Sljedeci(){
	int sec=sekundi;
	int min=minuta;
	
	sec=sekundi+1;
	sekundi=sec%60;
	minuta=(min+sec/60)%60;
	sati=(sati+(min+sec/60)/60)%24;
	
	return *this;
}

Sat Sat::Prethodni(){
	if(sekundi==0) sekundi=59;
	else sekundi=sekundi-1;
	
	if(sekundi==59){
		if(minuta==0) minuta=59;
		else minuta=minuta-1;
	}
	
	if(minuta==59){
		if(sati==0) sati=23;
		else sati=sati-1;
	}
	
	return *this;
}

int BrojSekundiIzmedju(Sat sat1, Sat sat2){
	int sec1;
	int sec2;
	int ukupno;
	sec1=sat1.sati*60*60+sat1.minuta*60+sat1.sekundi;
	sec2=sat2.sati*60*60+sat2.minuta*60+sat2.sekundi;
	ukupno=sec1-sec2;
	return ukupno;
}

int Sat::Razmak(Sat sat1, Sat sat2){
	/*int sec1;
	int sec2;
	int ukupno;
	sec1=sat1.sati*60*60+sat1.minuta*60+sat1.sekundi;
	sec2=sat2.sati*60*60+sat2.minuta*60+sat2.sekundi;
	ukupno=sec1-sec2;
	return ukupno;*/
	return BrojSekundiIzmedju(sat1, sat2);
}

Sat Sat::PomjeriZa(int br){
	sekundi=sekundi+br;
	Sat::PostaviNormalizirano(sati, minuta, sekundi);
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
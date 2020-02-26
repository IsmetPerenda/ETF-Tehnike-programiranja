#include <iostream>
#include <iomanip>

class Sat{
	int sati;
	int minuta;
	int sekundi;
	public:
	Sat() : sati(0), minuta(0), sekundi(0) {}
	Sat(int h, int m, int s) { PostaviNormalizirano(h, m, s); }
	static bool DaLiJeIspravno(int sati, int minuta, int sekundi){
		if(sati<0 || sati>23 || minuta<0 || minuta>59 || sekundi<0 || sekundi>59) return false;
		return true;
	}
	Sat &Postavi(const int &sat, const int &min, const int &sec){
		if(!DaLiJeIspravno(sat,min,sec)){
			throw std::domain_error("Neispravno vrijeme");
		}
		sati=sat;
		minuta=min;
		sekundi=sec;
		
		return *this;
	}
	Sat &PostaviNormalizirano(int h, int m, int s);
	Sat &operator ++();
	Sat &operator --();
	Sat operator ++(int);
	Sat operator --(int);
	Sat &operator +=(int pomak);
	Sat &operator -=(int pomak);
	int DajSate() const { return sati; };
	int DajMinute() const { return minuta; };
	int DajSekunde() const { return sekundi; };
	friend std::ostream &operator <<(std::ostream &tok, const Sat &s);
	friend int operator -(Sat &s1, Sat &s2);
	friend Sat operator +(Sat s, int pomak);
	friend Sat operator -(Sat s, int pomak);
};

Sat &Sat::PostaviNormalizirano(int h, int m, int s){
	while(s<0){
		s+=60;
		m--;
	}
	
	while(m<0){
		m+=60;
		h--;
	}
	
	while(h<0) h+=24;
	
	sekundi=s%60;
	m+=s/60;
	minuta=m%60;
	h+=m/60;
	sati=h%24;
	
	return *this;
}

Sat &Sat::operator ++(){
	sekundi++;
	return PostaviNormalizirano(sati, minuta, sekundi);
}

Sat &Sat::operator --(){
	sekundi--;
	return PostaviNormalizirano(sati, minuta, sekundi);
}

Sat Sat::operator ++(int){
	auto pom(*this);
	++sekundi;
	PostaviNormalizirano(sati, minuta, sekundi);
	return pom;
}

Sat Sat::operator --(int){
	auto pom(*this);
	sekundi--;
	PostaviNormalizirano(sati, minuta, sekundi);
	return pom;
}

Sat &Sat::operator +=(int pomak){
	sekundi+=pomak;
	return PostaviNormalizirano(sati, minuta, sekundi);
}

Sat &Sat::operator -=(int pomak){
	sekundi-=pomak;
	return PostaviNormalizirano(sati, minuta, sekundi);
}

int operator -(Sat &s1, Sat &s2){
	int razlika;
	razlika=(s1.DajSekunde()+s1.DajMinute()*60+s1.DajSate()*3600)-(s2.DajSekunde()+s2.DajMinute()*60+s2.DajSate()*3600);
	return razlika;
}

Sat operator +(Sat sat, int pomak){
	Sat pom=sat;
	pom+=pomak;
	return pom;
}

Sat operator -(Sat sat, int pomak){
	Sat pom=sat;
	pom-=pomak;
	return pom;
}

std::ostream &operator <<(std::ostream &tok, const Sat &s){
	tok.width(2); tok.fill('0'); tok << s.sati << ':';
	tok.width(2); tok.fill('0'); tok << s.minuta << ':';
	tok.width(2); tok.fill('0'); tok << s.sekundi;
	
	return tok;
}

/*Sat Sat::Sljedeci(){
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
	return BrojSekundiIzmedju(sat1, sat2);
}

Sat Sat::PomjeriZa(int br){
	sekundi=sekundi+br;
	Sat::PostaviNormalizirano(sati, minuta, sekundi);
	return *this;
}*/

int main ()
{
	Sat s1(11, 22, 33);
	Sat s2(20, 20, 20);
	Sat s3=s1++;
	Sat s4=++s2;
	
	std::cout << s4 << std::endl;
	s1++;
	std::cout << s1;
	std::cout << s3 << std::endl;
	s1+=2;
	std::cout << s1 << std::endl;
	s2+=5;
	std::cout << s2 << std::endl;
	
	std::cout << "Sat1: " << s1 << std::endl;
	std::cout << "Sat2: " << s2 << std::endl;
	
	
	return 0;
}
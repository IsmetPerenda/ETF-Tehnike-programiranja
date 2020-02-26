/* 
    TP 16/17 (Tutorijal 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

class Lik{
	public:
	virtual ~Lik(){}
	virtual void IspisiSpecificnosti() const=0;
	virtual double DajObim() const=0;
	virtual double DajPovrsinu() const=0;
	void Ispisi() const{
		IspisiSpecificnosti();
		std::cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu() << std::endl;
	}
};

class Krug: public Lik{
	double r;
	static constexpr double PI=3.141592653589793;
	public:
	Krug(double poluprecnik){
		if(poluprecnik<=0) throw std::domain_error("Neispravni parametri");
		r=poluprecnik;
	}
	double DajObim() const { return 2*PI*r; }
	double DajPovrsinu() const { return r*r*PI; }
	void IspisiSpecificnosti() const{
		std::cout << "Krug poluprecnika " << r << std::endl;
	}
};

class Pravougaonik: public Lik{
	double a;
	double b;
	public:
	Pravougaonik(double str1, double str2){
		if(str1<=0 || str2<=0) throw std::domain_error("Neispravni parametri");
		a=str1;
		b=str2;
	}
	double DajObim() const { return 2*a+2*b; }
	double DajPovrsinu() const { return a*b; }
	void IspisiSpecificnosti() const{
		std::cout << "Pravougaonik sa stranicama duzine " << a << " i " << b << std::endl;
	}
};

class Trougao: public Lik{
	double a;
	double b;
	double c;
	public:
	Trougao(double str1, double str2, double str3){
		if(str1<=0 || str2<=0 || str3<=0) throw std::domain_error("Neispravni parametri");
		if(str1+str2<=str3) throw std::domain_error("Neispravni parametri");
		if(str2+str3<=str1) throw std::domain_error("Neispravni parametri");
		if(str1+str3<=str2) throw std::domain_error("Neispravni parametri");
		a=str1;
		b=str2;
		c=str3;
	}
	/*virtual*/ double DajObim() const { return a+b+c; }
	/*virtual*/ double DajPovrsinu() const{
		double p;
		double s=(a+b+c)/2;
		p=s*(s-a)*(s-b)*(s-c);
		return sqrt(p);
	}
	/*virtual*/ void IspisiSpecificnosti() const{
		std::cout << "Trougao sa stranicama duzine " << a << ", " << b << " i " << c << std::endl;
	}
};

int main ()
{
	
	std::cout << "Koliko zelite likova: ";
	int n;
	std::cin >> n;
	
	std::vector<std::shared_ptr<Lik>> vektor(n);
	
	for(int i=0; i<n; i++){
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		
		std::cout << "Lik " << i+1 << ": ";
		char slovo_lika;
		
		std::cin >> slovo_lika;
		
		char znak;																		//kupi zarez ili neki drugi znak
		
		if(slovo_lika=='K'){															//provjeravamo da li je krug
			double r;
			
			std::cin >> r;
			
			if(!std::cin || std::cin.peek()!='\n'){
				std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
				i--;
				continue;
			}
			try{
				vektor[i]=std::make_shared<Krug>(r);
			}
			catch(std::domain_error e){
				std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
				i--;
				continue;
			}
		}
		
		else if(slovo_lika=='P'){														//provjeravamo da li je pravougaonik
			double a,b;
			
			std::cin >> a >> znak >> b;
			
			if(!std::cin || znak!=',' || std::cin.peek()!='\n'){
				std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
				i--;
				continue;
			}
			try{
				vektor[i]=std::make_shared<Pravougaonik>(a,b);
			}
			catch(std::domain_error e){
				std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
				i--;
				continue;
			}
		}
		
		else if(slovo_lika=='T'){
			double a,b,c;
			
			std::cin >> a >> znak;
			if(znak==',') std::cin >> b >> znak >> c;
			if(!std::cin || znak!=',' || std::cin.peek()!='\n'){
				std::cout << "Pogresni podacim ponovite unos!" << std::endl;
				i--;
				continue;
			}
			try{
				vektor[i]=std::make_shared<Trougao>(a,b,c);
			}
			catch(std::domain_error e){
				std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
				i--;
				continue;
			}
		}
		
		else{
			std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
			i--;
		}
	}
	
	std::cout << std::endl;
	
	for(auto x : vektor) x->Ispisi();
	
	return 0;
}
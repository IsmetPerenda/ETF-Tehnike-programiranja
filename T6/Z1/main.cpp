/*
    TP 2018/2019: Tutorijal 6, Zadatak 1

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <limits>

template<typename Tip>
auto GenerirajStepeneDvojke(Tip n) -> Tip*{
	if(n<=0){
		throw std::domain_error("Broj elemenata mora biti pozitivan");
	}
	
	Tip* p;
	try{
		p=new Tip[int(n)];
	}
	catch(std::bad_alloc){
		throw std::runtime_error("Alokacija nije uspjela");
	}
	
	for(int i=0; i<n; i++){
		if(Tip(powl(Tip(2),i))>=std::numeric_limits<Tip>::max() || std::numeric_limits<Tip>::min()>=Tip(powl(Tip(2),i))){
			delete[] p;
			throw std::overflow_error("Prekoracen dozvoljeni opseg");
		}
		p[i]=pow(2,i);
	}
	
	return p;
}

int main ()
{
	std::cout << "Koliko zelite elemenata: ";
	int n;
	std::cin >> n;
	
	try{
		int *p=GenerirajStepeneDvojke<int>(n);
		for(int i=0; i<n; i++){
			std::cout << p[i] << " ";
		}
		delete[] p;
	}
	catch(std::domain_error poruka){
		std::cout << "Izuzetak: " << poruka.what();
	}
	catch(std::runtime_error poruka){
		std::cout << "Izuzetak: " << poruka.what();
	}
	return 0;
}

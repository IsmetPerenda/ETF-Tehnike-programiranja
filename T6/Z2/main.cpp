/*
    TP 2018/2019: Tutorijal 6, Zadatak 2

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <type_traits>

template<typename IterTip>
auto KreirajIzvrnutiNiz(IterTip pocetak, IterTip izakraja) -> typename std::remove_reference<decltype(*pocetak)>::type*
{
	IterTip p=pocetak;
	int brojac=0;//posto ne znamo duzina niza jer smo slali pokazivace, treba nam brojac da izbrojimo

	while(p!=izakraja) {
		brojac++;
		p++;
	}

	p=pocetak;
	auto niz2=new typename std::remove_reference<decltype(*pocetak)>::type[brojac];
	for(int i=0; i<brojac; i++) {
		niz2[brojac-1-i]=*p;
		p++;
	}

	return niz2;
}

int main ()
{
	try {
		std::cout << "Koliko zelite elemenata: ";
		int n;
		std::cin >> n;
		std::vector<double> v(n);
		std::cout << "Unesite elemente: ";

		for(int i=0; i<n; i++) {
			double broj;
			std::cin >> broj;
			v.at(i)=broj;
		}
		try {
			std::cout << "Kreirani niz: ";

			double *novi=KreirajIzvrnutiNiz(v.begin(),v.end());
			for(int i=0; i<n; i++) {
				std::cout << novi[i] << " ";
			}
			delete[] novi;
		} catch(std::bad_alloc) {
			std::cout << "Nedovoljno memorije!";
		}

		

	} catch(std::bad_alloc) {
		std::cout << "Nedovoljno memorije!";
	}


	return 0;
}
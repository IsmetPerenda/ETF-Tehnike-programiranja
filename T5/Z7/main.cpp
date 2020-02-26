/* 
    TP 2018/2019: Tutorijal 5, Zadatak 7
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <algorithm>
#include <deque>

template <typename IterTip>
auto SumaBloka(IterTip pocetak, IterTip izakraja) -> decltype(*pocetak+*pocetak){
	
	if(izakraja==pocetak){
		throw std::range_error("Blok je prazan");
	}
	
	decltype(*pocetak+*pocetak) sum=*pocetak;
	
	IterTip p = ++pocetak;
	
	while(p!=izakraja){
		sum=sum+(*p);
		p++;
	}
	
	return sum;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::deque<double> d(n);
	std::cout << "Unesite elemente: ";
	std::for_each(d.begin(),d.end(),[](double &broj){ std::cin >> broj; });
	
	try{
		std::cout << "Suma bloka je: " << SumaBloka(d.begin(),d.end());
	}
	catch(std::range_error poruka){
		std::cout << poruka.what();
	}
	return 0;
}
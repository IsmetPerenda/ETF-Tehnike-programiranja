/*
    TP 2018/2019: Tutorijal 5, Zadatak 2

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
#include <vector>
#include <string>

template<typename Tip1, typename Tip2>
Tip2 RazmijeniBlokove(Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2)
{
	while(pocetak1!=kraj1) {
		auto tmp=*pocetak1;
		*pocetak1=*pocetak2;
		*pocetak2=tmp;
		pocetak1++;
		pocetak2++;
	}

	return pocetak2;
}



int main ()
{
	//kratki program za vektor cijelih brojeva
	std::vector<int> v1{2,4,6,8,10};
	std::vector<int> v2{1,3,5,7,9};
	
	RazmijeniBlokove(v1.begin(),v1.end(),v2.begin());
	
	std::cout << "Prvi niz: " << std::endl;
	for(auto &a : v1){
		std::cout << a << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Drugi niz: " << std::endl;
	for(auto &b : v2){
		std::cout << b << " ";
	}
	std::cout << std::endl;
	
	//a sada i za fiksni par stringova
	std::string s1("Pada kisa");
	std::string s2("Kisa pada");
	
	RazmijeniBlokove(s1.begin(),s1.end(),s2.begin());
	
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	return 0;
}

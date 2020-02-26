/* 
    TP 2018/2019: Tutorijal 5, Zadatak 3
	
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
#include <cmath>
#include <deque>
#include <vector>

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::deque<int> d(n);
	std::cout << "Unesite elemente: ";
	std::for_each(d.begin(), d.end(), [](int &broj){ std::cin >> broj; });
	
	int najveci=*std::max_element(d.begin(), d.end());
	std::cout << "Najveci element deka je " << najveci << std::endl;
	
	int najmanji= *std::min_element(d.begin(), d.end());
	int brojac=std::count(d.begin(), d.end(), najmanji);
	std::cout << "Najmanji element deka se pojavljuje " << brojac << " puta u deku" << std::endl;
	
	int kvadrati=std::count_if(d.begin(), d.end(), [](int broj){ if(int(sqrt(broj))*int(sqrt(broj))==broj){ return true; } else return false;});
	std::cout << "U deku ima " << kvadrati << " brojeva koji su potpuni kvadrati" << std::endl;
	
	std::deque<int> brojCifri(n);
	std::transform(d.begin(), d.end(), brojCifri.begin(), [](int broj){
		if(broj==0){
			broj=1;
			return broj;
		}
		return broj=int(log10(abs(broj)))+1;
	});
	auto iter=brojCifri.begin();
	auto najmanjecifri=std::find(brojCifri.begin(), brojCifri.end(), *std::min_element(brojCifri.begin(), brojCifri.end()));
	std::cout << "Prvi element sa najmanjim brojem cifara je " << d.at(najmanjecifri-iter) << std::endl;
	
	std::deque<int> neTrocifreni(n);
	auto netrocifreni=std::remove_copy_if(d.begin(), d.end(), neTrocifreni.begin(), [](int broj){
		if(int(log10(abs(broj)))+1==3) return true;
		return false;
	});
	std::cout << "Elementi koji nisu trocifreni su: ";
	
	std::for_each(neTrocifreni.begin(), netrocifreni, [](int &broj){ std::cout << broj << " "; });
	

	return 0;
}
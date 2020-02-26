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

void Unos(int &broj){
	std::cin >> broj;
}

void Ispis(int &broj){
	std::cout << broj << " ";
}

bool PotpunKvadrat(int broj){
	if(int(sqrt(broj))*int(sqrt(broj))==broj){
		return true;
	}
	return false;
}

int BrojCifri(int broj){
	if(broj==0){
		return 1;
	}
	
	return int(broj=int(log10(std::abs(broj)))+1);
}

bool JelTrocifren(int broj){
	if(int(log10(abs(broj)))+1==3){
		return true;
	}
	return false;
}

int main ()
{
	int niz[1000];
	int n;
	std::cout << "Unesite broj elemenata (max. 1000): ";
	std::cin >> n;
	std::cout << "Unesite elemente: ";
	std::for_each(niz, niz+n, Unos);
	
	int najveci=*std::max_element(niz, niz+n);
	std::cout << "Najveci element niza je " << najveci << std::endl;
	
	int najmanji= *std::min_element(niz, niz+n);
	int brojac=std::count(niz, niz+n, najmanji);
	std::cout << "Najmanji element niza se pojavljuje " << brojac << " puta u nizu" << std::endl;
	
	int kvadrati=std::count_if(niz, niz+n, PotpunKvadrat);
	std::cout << "U nizu ima " << kvadrati << " brojeva koji su potpuni kvadrati" << std::endl;
	
	int brojCifri[1000];
	std::transform(niz, niz+n, brojCifri, BrojCifri);
	auto najmanjecifri=std::find(brojCifri, brojCifri+n, *std::min_element(brojCifri, brojCifri+n));
	std::cout << "Prvi element sa najmanjim brojem cifara je " << niz[najmanjecifri-brojCifri] << std::endl;
	
	int nizNeTrocifrenih[1000];
	auto netrocifreni=std::remove_copy_if(niz, niz+n, nizNeTrocifrenih, JelTrocifren);
	std::cout << "Elementi koji nisu trocifreni su: ";
	std::for_each(nizNeTrocifrenih, netrocifreni, Ispis);
	
	
	return 0;
}
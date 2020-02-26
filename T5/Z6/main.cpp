/* 
    TP 2018/2019: Tutorijal 5, Zadatak 6
	
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
#include <algorithm>

int SumaCifara(int n){
	if(n!=0){
		return (n%10+SumaCifara(n/10));
	}
	else{
		return 0;
	}
}

bool VecaCifra(int broj1, int broj2){
	int brojcifri1=SumaCifara(abs(broj1));
	int brojcifri2=SumaCifara(abs(broj2));
	
	if(brojcifri1!=brojcifri2){
		return brojcifri1<brojcifri2;
	}
	
	return broj1<broj2;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::vector<int> a(n);
	std::cout << "Unesite elemente: ";
	std::for_each(a.begin(), a.end(), [](int &broj){std::cin >> broj;});
	
	std::sort(a.begin(), a.end(), VecaCifra);
	std::cout << "Niz sortiran po sumi cifara glasi: ";
	std::for_each(a.begin(), a.end(), [](const int &x){ std::cout << x << " ";});
	std::cout << std::endl;
	
	std::cout << "Unesite broj koji trazite: ";
	int trazeni;
	std::cin >> trazeni;
	
	auto trazenibroj=std::find(a.begin(), a.end(), trazeni);
	if(trazenibroj==a.end()){
		std::cout << "Trazeni broj ne nalazi se u nizu!";
	}
	else{
		std::cout << "Trazeni broj nalazi se na poziciji " << (trazenibroj-a.begin());
	}
	return 0;
}
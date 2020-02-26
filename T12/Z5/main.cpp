/* 
    TP 16/17 (Tutorijal 12, Zadatak 5)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main ()
{
	int n;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;
	
	std::vector<double> v(n);
	
	std::cout << "Unesite elemente: ";
	
	for(int i=0; i<n; i++){
		int broj;
		std::cin >> broj;
		v.at(i)=broj;
	}
	
	std::transform(v.begin(), v.end(), v.begin(), std::bind1st (std::divides<double>(),1));
	
	std::cout << "Transformirani elementi: ";
	for(int i=0; i<n; i++){
		std::cout << v.at(i) << " ";
	}
	
	return 0;
}
/* 
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>
#include <string>

template <typename Tip>
auto Unija (std::set<Tip> set1, std::set<Tip> set2) -> decltype(set1){
	std::set<Tip> unija;
	for(Tip x : set1){
		unija.insert(x);
	}
	for(Tip x : set2){
		unija.insert(x);
	}
	
	return unija;
}

template <typename Tip>
auto Presjek (std::set<Tip> set1, std::set<Tip> set2) -> decltype(set1){
	std::set<Tip> presjek;
	for(Tip x : set1){
		for(Tip y : set2){
			if(x==y){
				presjek.insert(x);
			}
		}
	}
	
	return presjek;
}

int main ()
{
	std::set<std::string> s1{"rijec", "slovo", "broj", "cifra", "recenica"};
	std::set<std::string> s2{"unija", "presjek", "skup", "broj", "cifra"};
	auto unija=Unija(s1,s2);
	auto presjek=Presjek(s1,s2);
	std::cout << std::endl;
	for(auto x : unija){
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for(auto x : presjek){
		std::cout << x << " ";
	}
	return 0;
}
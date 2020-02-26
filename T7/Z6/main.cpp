/* 
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
#include <iterator>
#include <type_traits>

template <typename Tip>
void SortirajListu (std::list<Tip> &lista){
	auto it1=lista.begin();
	
	while(it1!=lista.end()){
		auto it2=it1;
		auto mini=it1;
		
		while(it2!=lista.end()){
			if(*it2<*mini){
				mini=it2;
			}
			it2++;
		}
		
		auto tmp=*it1;
		*it1=*mini;
		*mini=tmp;
		it1++;
		
	}
}

int main ()
{
	int n;
	std::cout << "Koliko ima elemenata: ";
	std::cin >> n;
	std::list<int> lista;
	std::cout << "Unesite elemente: ";
	for(int i=0; i<n; i++){
		int broj;
		std::cin >> broj;
		lista.push_back(broj);
	}
	
	std::cout << "Sortirana lista: ";
	SortirajListu(lista);
	for(auto a : lista){
		std::cout << a << " ";
	}
	
	return 0;
}
/*
    TP 2018/2019: Tutorijal 6, Zadatak 5

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

template<typename KontejnerskiTip>
auto KreirajDinamickuKopiju2D(KontejnerskiTip v) -> typename std::remove_reference<decltype(v.at(0).at(0))>::type**
{
	try {
		auto m=new typename std::remove_reference<decltype(v.at(0).at(0))>::type*[v.size()]{};
		int duzina=v.size();

		try {
			for(int i=0; i<duzina; i++){
				m[i]=new typename std::remove_reference<decltype(v.at(0).at(0))>::type[v.at(i).size()];
			}
			for(int i=0; i<duzina; i++) {
				for(int j=0; j<v.at(i).size(); j++) {
					m[i][j]=v.at(i).at(j);
				}
			}
		} catch(std::bad_alloc) {
			for(int i=0; i<duzina; i++) {
				delete[] m[i];
			}
			delete[] m;
			throw;
		}

		return m;

	} catch(std::bad_alloc) {
		throw;
	}
}

int main ()
{
	std::cout << "Unesite broj redova kvadratne matrice: ";

	try {
		int n;
		std::cin >> n;
		std::vector<std::deque<int>> v(n,std::deque<int>(n));

		std::cout << "Unesite elemente matrice: ";

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				int broj;
				std::cin >> broj;
				v.at(i).at(j)=broj;
			}
		}

		int **matrica=KreirajDinamickuKopiju2D(v);

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				std::cout << matrica[i][j] << " ";
			}
			std::cout << std::endl;
		}

		for(int i=0; i<n; i++) {
			delete[] matrica[i];
		}
		delete[] matrica;
	} 
	catch(std::bad_alloc) {
		std::cout << "Nedovoljno memorije";
	}

	return 0;
}

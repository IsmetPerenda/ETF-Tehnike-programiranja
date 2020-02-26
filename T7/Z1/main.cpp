/*
    TP 16/17 (Tutorijal 7, Zadatak 1)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdexcept>

void Sortiranje(char **recenice, int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(strcmp(recenice[j],recenice[j+1])>0){
				auto tmp=recenice[j];
				recenice[j]=recenice[j+1];
				recenice[j+1]=tmp;
			}
		}
	}
}


int main ()
{
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite recenice: " << std::endl;
	try {
		char **recenice=new char*[n]{};
		for(int i=0; i<n; i++) {
			char radni_prostor[1000];
			std::cin.getline(radni_prostor, sizeof radni_prostor);
			try{
				recenice[i]=new char[std::strlen(radni_prostor)+1];
			}
			catch(std::bad_alloc){
				for(int i=0; i<n; i++){
					delete[] recenice[i];
				}
				delete[] recenice;
				throw;
			}
			std::strcpy(recenice[i], radni_prostor);
		}

		Sortiranje(recenice, n);
		
		std::cout << "Sortirane recenice:" << std::endl;
		for(int i=0; i<n; i++) {
			std::cout << recenice[i] << std::endl;
		}
		for(int i=0; i<n; i++){
			delete[] recenice[i];
		}
		delete[] recenice;
	} catch(std::bad_alloc e) {
		std::cout << "Problemi s memorijom!";
	}
	return 0;
}

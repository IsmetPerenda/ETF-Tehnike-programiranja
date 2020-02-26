/* 
    TP 16/17 (Tutorijal 7, Zadatak 5)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <new>



int main ()
{
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite recenice: " << std::endl;

	try {
		std::shared_ptr<std::shared_ptr<std::string>>recenice(new std::shared_ptr<std::string>[n] {}, [](std::shared_ptr<std::string>* s) {delete[] s;});
		for(int i=0; i<n; i++) {
			recenice.get()[i]=std::make_shared<std::string>();
			std::getline(std::cin, *recenice.get()[i]);
		}

		for(int i=0; i<n-1; i++) {
			for(int j=0; j<n-i-1; j++) {
				if(*recenice.get()[j]>*recenice.get()[j+1]) {
					auto tmp=recenice.get()[j];
					recenice.get()[j]=recenice.get()[j+1];
					recenice.get()[j+1]=tmp;
				}
			}
		}

		std::cout << "Sortirane recenice: " << std::endl;
		for(int i=0; i<n; i++) {
			std::cout << *recenice.get()[i] << std::endl;
		}
	} catch(std::bad_alloc) {
		std::cout << "Problemi s memorijom!";
		return 0;
	}
	return 0;
}
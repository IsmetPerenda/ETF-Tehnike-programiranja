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
#include <string>


int main ()
{
	int n;
	std::cout << "Koliko zelite recenica: ";
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	std::cout << "Unesite recenice: " << std::endl;
	std::string** recenice=nullptr;
	try {
		recenice=new std::string *[n]{};
		try{
			for(int i=0; i<n; i++){
				recenice[i]=new std::string {};
				std::getline(std::cin, *recenice[i]);
			}
		}
		catch(std::bad_alloc){
			for(int i=0; i<n; i++){
				delete recenice[i];
			}
			delete[] recenice;
			std::cout << "Problemi s memorijom!";
			return 0;
		}
	} 
	catch(std::bad_alloc) {
		delete[] recenice;
		std::cout << "Problemi s memorijom!";
		return 0;
	}
	
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(*recenice[j]>*recenice[j+1]){
				std::string *tmp=recenice[j];
				recenice[j]=recenice[j+1];
				recenice[j+1]=tmp;
			}
		}
	}
	
	std::cout << "Sortirane recenice: " << std::endl;
	for(int i=0; i<n; i++){
		std::cout << *recenice[i] << std::endl;
	}
	
	for(int i=0; i<n; i++){
		delete recenice[i];
	}
	delete[] recenice;
	
	return 0;
}
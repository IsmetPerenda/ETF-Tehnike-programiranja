/* 
    TP 2018/2019: Tutorijal 6, Zadatak 3
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <stdexcept>

int **KreirajTrougao(int n){
	if(n<=0){															//bacamo izuzetak ukoliko je unesen negativan broj ili nula za broj redova
		throw std::domain_error("Broj redova mora biti pozitivan");
	}
	
	try{
		int **matrica=new int*[n];
		for(int i=0; i<n; i++){
			try{
				int duzinareda=2*i+1;
				matrica[i]=new int[duzinareda];
				
				for(int j=0; j<duzinareda; j++){
					matrica[i][j]=j+1-i;								//krecemo s pocetka reda
					matrica[i][duzinareda-1-j]=j+1-i;					//krecemo s kraja reda
				}
			}
			catch(std::bad_alloc){
				for(int i=0; i<n; i++){
					delete[] matrica[i];
				}
				delete[] matrica;
				throw;
			}
		}
		
		return matrica;
	}
	catch(std::bad_alloc){
		throw;
	}
}

int main ()
{
	std::cout << "Koliko zelite redova: ";
	try{
		int n;
		std::cin >> n;
		int **matrica=KreirajTrougao(n);
		
		for(int i=0; i<n; i++){
			int duzinareda=2*i+1;
			for(int j=0; j<duzinareda; j++){
				std::cout << matrica[i][j] << " ";
			}
			std::cout << std::endl;
		}
		
		for(int i=0; i<n; i++){
			delete[] matrica[i];
		}
		delete[] matrica;
	}
	catch(std::domain_error poruka){
		std::cout << "Izuzetak: " << poruka.what();
	}
	catch(std::bad_alloc){
		std::cout << "Izuzetak: Nedovoljno memorije!";
	}
	
	return 0;
}
/* 
    TP 2018/2019: Tutorijal 6, Zadatak 4
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <stdexcept>

int **KreirajTrougao(int n){
	if(n<=0){
		throw std::domain_error("Broj redova mora biti pozitivan");
	}
	
	try{
		int **matrica=new int*[n]{};
		try{
			matrica[0]=new int[n*n];
		}
		catch(std::bad_alloc){
			delete[] matrica;
			throw;
		}
		
		for(int i=0; i<n; i++){
			int duzinareda;
			if(i==0){
				matrica[0][0]=1;
				duzinareda=1;
			}
			else{
				try{
					matrica[i]=matrica[i-1]+duzinareda;
					duzinareda=2*i+1;
					for(int j=0; j<duzinareda; j++){
						matrica[i][j]=j+1-i;					//krecemo s pocetka reda
						matrica[i][duzinareda-j-1]=j+1-i;		//sada krecemo s kraja reda
					}
				}
				catch(std::bad_alloc){
					delete[] matrica[0];
					delete[] matrica;
					throw;
				}
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
		
		delete[] matrica[0];
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
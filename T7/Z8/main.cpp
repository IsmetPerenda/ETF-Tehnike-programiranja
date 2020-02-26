/* 
    TP 16/17 (Tutorijal 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

std::string IzvrniBezRazmaka (std::string s){
	std::string izvrnuti;
	
	remove_copy(s.rbegin(), s.rend(), std::back_inserter(izvrnuti), ' ');
	
	return izvrnuti;
}


int main ()
{
	std::string probni("Ovo je string koji cemo izvrnuti bez razmaka");
	auto izvrnuti=IzvrniBezRazmaka(probni);
	std::cout << izvrnuti << std::endl;
	
	return 0;
}
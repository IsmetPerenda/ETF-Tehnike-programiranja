/* 
    TP 2018/2019: Tutorijal 5, Zadatak 5
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <cmath>
#include <iomanip>

double TrapeznoPravilo (double (*f)(double), double a, double b, int n){
	double sum=0;
	for(int k=1; k<=n-1; k++){
		sum=sum+(f(a+((b-a)/n)*k));
	}
	double integral=((b-a)/n * (f(a)/2.+f(b)/2.+sum));
	
	return integral;
}


int main ()
{
	int n;
	std::cout << "Unesite broj podintervala: ";
	std::cin >> n;
	std::cout << "Za taj broj podintervala priblizne vrijednosti integrala iznose: " << std::endl;
	double integral;
	const double PI=atan(1)*4;
	integral=TrapeznoPravilo(std::sin,0,PI,n);
	std::cout << "- Za funkciju sin x na intervalu (0,pi): " << std::fixed << std::setprecision(5) << integral;
	integral=TrapeznoPravilo([](double x)-> double{return x*x*x;},0,10,n);
	std::cout << std::endl;
	std::cout << "- Za funkciju x^3 na intervalu (0,10): " << std::setprecision(2) << integral;
	integral=TrapeznoPravilo([](double x)-> double{return 1./x;},1,2,n);
	std::cout << std::endl;
	std::cout << "- Za funkciju 1/x na intervalu (1,2): " << std::setprecision(5) << integral;
	return 0;
}
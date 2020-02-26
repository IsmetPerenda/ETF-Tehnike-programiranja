/*
    TP 16/17 (Tutorijal 7, Zadatak 10)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <functional>

std::function<int(int)> IteriranaFunkcija(std::function<int(int)> f, int n)
{
	if(n<=0) {
		return [](int x) {
			return x;
		};
	}

	else {
		return [f, n](int rez) {
			for(int i=1; i<=n; i++) {
				rez=f(rez);
			}
			return rez;
		};
	}
}

int f(int x)
{
	return x*x*x;
}

int main ()
{
	auto g(IteriranaFunkcija(f, 10));
	std::cout << g(5);
	std::cout << std::endl;

	std::cout << IteriranaFunkcija(f, 10)(5);
	std::cout << std::endl;
	
	std::cout << f(f(f(f(f(f(f(f(f(f(5))))))))));
	std::cout << std::endl;

	return 0;
}

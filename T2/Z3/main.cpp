//TP 2017/2018: Tutorijal 2, Zadatak 3
#include <iostream>
#include <complex>

int main ()
{
    std::cout << "Unesite broj elemenata: " << std::endl;
    
    int n;
    
    std::cin >> n;
    
    std::complex<double> sum(0, 0);
    
    for(int i=1; i<=n; i++)
    {
        std::cout << "Z_" << i << " = ";
        std::complex<double> z;
        std::cin >> z;
        sum=sum+(1./z);
    }
    
    std::cout << std::endl;
    std::cout << "Paralelna veza ovih elemenata ima impedansu Z_ = " << 1./sum << "." << std::endl;
	return 0;
}
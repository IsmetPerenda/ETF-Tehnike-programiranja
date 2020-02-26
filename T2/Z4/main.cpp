//TP 2017/2018: Tutorijal 2, Zadatak 4
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
        std::complex<double> z(0, 0);
        double r,x;
        std::cout << "R" << i << " = ";
        std::cin >> r;
        std::cout << "X" << i << " = ";
        std::cin >> x;
        
        z.real(r); z.imag(x);
        sum=sum+(1./z);
        
        std::cout << std::endl;
    }
    
    sum=1./sum;
    
    std::cout << std::endl;
    std::cout << "Paralelna veza ovih elemenata ima R = " << sum.real() << " i X = " << sum.imag() << "." << std::endl;
	return 0;
}
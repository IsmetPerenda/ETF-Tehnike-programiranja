//TP 2017/2018: Tutorijal 2, Zadatak 5
#include <iostream>
#include <complex>
#include <cmath>

int main ()
{
    const double PI=4*atan(1);
    std::cout << "Unesi broj elemenata: " << std::endl;
    
    int n;
    
    std::cin >> n;
    
    std::complex<double> sum;
    sum = std::polar(0, 0);
    
    for(int i=1; i<=n; i++)
    {
        std::complex<double> com(0, 0);
        double z,fi;
        std::cout << "Z" << i << " = ";
        std::cin >> z;
        std::cout << "fi" << i << " = ";
        std::cin >> fi;
        
        fi=(fi*PI)/180.0;
        
        com = std::polar(z, fi);
        sum=sum+(1./com);
        
        std::cout << std::endl;
    }
    
    sum=1./sum;
    
    std::cout << "Paralelna veza ovih elemenata ima Z = " << std::abs(sum) << " i fi = " << std::arg(sum)*180/PI << "." << std::endl;
	return 0;
}
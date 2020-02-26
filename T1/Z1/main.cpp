//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
int main ()
{
    int a,b,c,d;
    
    std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin >> a >> b >> c;
    
    std::cout << "Unesite sirinu plocice u centimetrima: " << std::endl;
    std::cin >> d;
    
    a=a*100;
    b=b*100;
    c=c*100;
    
    int pPlocice;
    int pBazena;
    
    pPlocice=d*d;
    pBazena=a*b+(2*a*c)+(2*b*c);
    
    if(a%d==0 && b%d==0 && c%d==0)
    {
        std::cout << "Za poplocavanje bazena dimenzija " << a/100 << "x" << b/100 << "x" << c/100 << "m sa plocicama dimenzija " << d << "x" << d <<
        "cm " << std::endl << "potrebno je " << pBazena/pPlocice << " plocica." << std::endl;
    }
    
    else
    {
        std::cout << "Poplocavanje bazena dimenzija " << a/100 << "x" << b/100 << "x" << c/100 << "m sa plocicama dimenzija " << d << "x" << d  << "cm" << std::endl <<
        "nije izvodljivo bez lomljenja plocica!" << std::endl;
    }
	return 0;
}
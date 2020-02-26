//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <limits>

int Cifre (long long int broj, int &c_min, int &c_max)
{
    int brojac=0;
    int cifra;

    if(broj==0) {
        c_min=0;
        c_max=0;
        brojac=1;
        return brojac;
    }

    if(broj<0) {
        c_min=broj%10*(-1);
        c_max=broj%10*(-1);
        broj=broj/10*(-1);
        brojac++;
    } else {
        c_min=broj%10;
        c_max=broj%10;
        broj=broj/10;
        brojac++;
    }


    while(broj>0) {
        cifra=broj%10;
        if(cifra>c_max) {
            c_max=cifra;
        } else if(cifra<c_min) {
            c_min=cifra;
        }
        brojac++;
        broj=broj/10;
    }
    return brojac;
}

int main ()
{
    long long int n;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    int maxi,mini;
    int e=Cifre(n,mini,maxi);
    std::cout << "Broj " << n << " ima " << e << " cifara, najveca je " << maxi << " a najmanja " << mini << "." << std::endl;
    return 0;
}

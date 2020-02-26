//TP 2017/2018: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>
#include <cmath>

bool TestPerioda(std::vector<double> b, int p)
{
    if(p<1 || p>=b.size()) 
    {
        return false;
    } 
    else 
    {
        for(int i=0; i<b.size()-p; i++) {
            if(fabs(b[i]-b[i+p])>0.00001) {
                return false;
            }
        }
    }

    return true;
}

int OdrediOsnovniPeriod(std::vector<double> a)
{
    int period=0;
    
    for(int i=1; i<a.size(); i++)
    {
        if(TestPerioda(a,i))
        {
            period=i;
            break;
        }
    }
    
    return period;
}

int main ()
{
    std::vector<double> vektor;
    double a;

    std::cout << "Unesite slijed brojeva (0 za kraj): ";

    for(;;) {
        std::cin >> a;
        if(fabs(a)<0.00001) {
            break;
        }
        vektor.push_back(a);
    }

    if(OdrediOsnovniPeriod(vektor)!=0) {
        std::cout << "Slijed je periodican sa osnovnim periodom " << OdrediOsnovniPeriod(vektor) << ".";
    } else {
        std::cout << "Slijed nije periodican!";
    }

    return 0;
}

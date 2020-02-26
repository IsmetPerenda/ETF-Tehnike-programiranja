//TP 2017/2018: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector>

bool DaLiJeProst(int n)
{
    
    if(n==2)
    {
        return true;
    }
    if(n<=1 || n%2==0)
    {
        return false;
    }
    
    for(long int i=3; i*i<=n; i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    
    return true;
}

std::vector<int> ProstiBrojeviUOpsegu(int a, int b)
{
    long int i;
    
    std::vector<int> vektor;
    
    for(i=a; i<=b; i++)
    {
        if(DaLiJeProst(i))
        {
            vektor.push_back(i);
        }
    }
    
    return vektor;
}

int main ()
{
    int a,b;
    std::cout << "Unesite pocetnu i krajnju vrijednost: ";
    std::cin >> a >> b;
    
    auto prosti=ProstiBrojeviUOpsegu(a, b);
    
    if(prosti.size()!=0)
    {
        std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
        
        for(int i=0; i<prosti.size(); i++)
        {
            if(i==prosti.size()-1)
            {
                std::cout << prosti[i];
            }
            else
            {
                std::cout << prosti[i] << ", ";
            }
        }
    }
    
    else
    {
        std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b << "!";
    }
    
    std::cout << std::endl;
    
	return 0;
}

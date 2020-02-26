//TP 2017/2018: Tutorijal 3, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> IzdvojiElemente (std::vector<int> v, bool a)
{
    std::vector<int> c;
    
    if(a==true)
    {
        for(int i: v)
        {
            int x=abs(i);
            int sum=0;
            while(x!=0)
            {
                sum=sum+(x%10);
                x=x/10;
            }
            
            if(sum%2==0)
            {
                c.push_back(i);
            }
            
            sum=0;
        }
    }
    else
    {
        for(int i: v)
        {
            int x=fabs(i);
            int sum=0;
            while(x!=0)
            {
                sum=sum+(x%10);
                x=x/10;
            }
            
            if(sum%2!=0)
            {
                c.push_back(i);
            }
            
            sum=0;
        }
    }
    
    return c;
}

int main ()
{
    int n,x;
    std::cout << "Koliko zelite unijeti elemenata: ";
    std::cin >> n;
    
    if(n==0)
    {
        std::cout << "Broj elemenata mora biti veci od 0!";
        return 0;
    }
    std::cout << "Unesite elemente: ";
    
    std::vector<int> a;
    
    for(int i=0; i<n; i++)
    {
        std::cin >> x;
        a.push_back(x);
    }
    
    auto b=IzdvojiElemente(a,true);
    for(int i : b)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    auto c=IzdvojiElemente(a,false);
    for(int i : c)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
	return 0;
}
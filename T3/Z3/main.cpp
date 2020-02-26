//TP 2017/2018: Tutorijal 3, Zadatak 3
#include <iostream>
#include <deque>
#include <cmath>

std::deque<int> IzdvojiElemente (std::deque<int> v, bool a)
{
    std::deque<int> c;
    
    if(a==true)
    {
        for(int i=0; i<v.size(); i++)
        {
            int x=fabs(v[i]);
            int sum=0;
            while(x!=0)
            {
                sum=sum+(x%10);
                x=x/10;
            }
            
            if(sum%2==0)
            {
                c.push_back(v[i]);
            }
            
            sum=0;
        }
    }
    else
    {
        for(int i=0; i<v.size(); i++)
        {
            int x=fabs(v[i]);
            int sum=0;
            while(x!=0)
            {
                sum=sum+(x%10);
                x=x/10;
            }
            
            if(sum%2!=0)
            {
                c.push_back(v[i]);
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
    
    std::deque<int> a;
    
    for(int i=0; i<n; i++)
    {
        std::cin >> x;
        a.push_back(x);
    }
    
    auto b=IzdvojiElemente(a,true);
    for(int i=0; i<b.size(); i++)
    {
        if(i==b.size()-1)
        {
            std::cout << b[i];
        }
        else
        {
            std::cout << b[i] << ",";
        }
    }
    std::cout << std::endl;
    
    auto c=IzdvojiElemente(a,false);
    for(int i=0; i<c.size(); i++)
    {
        if(i==c.size()-1)
        {
            std::cout << c[i];
        }
        else
        {
            std::cout << c[i] << ",";
        }
    }
    std::cout << std::endl;
    
	return 0;
}
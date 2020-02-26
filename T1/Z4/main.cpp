#include <iostream>
#include <cmath>
 
int main()
{
   double broj;
   
   while(1)
   {
    std::cout << "Unesite prirodan broj ili 0 za kraj: ";
    
    if(!(std::cin>>broj) || broj<0 || broj-floor(broj)!=0)
    {
        std::cout << "Niste unijeli prirodan broj!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        continue;
    }
    
    else if(broj==0)
    {
        std::cout << "Dovidjenja!";
        break;
    }
   
   else
   {
       int broj1=broj;
       int sum=0;
       for(int i=1; i<broj1; i++)
       {
           if(broj1%i==0)
           {
               sum=sum+i;
           }
       }
       
       if(sum<broj1)
       {
           std::cout<< "Broj " << broj1 << " je manjkav!" << std::endl;
       }
       else if(sum>broj1)
       {
           std::cout<< "Broj " << broj1 << " je obilan!" << std::endl;
       }
       else if(sum==broj1)
       {
           std::cout<< "Broj " << broj1 << " je savrsen!" << std::endl;
       }
   }
       
   }
   
   return 0;
   
}
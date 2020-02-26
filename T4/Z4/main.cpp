//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <string>
#include <cmath>

template<typename Tip>

void UnosBroja(std::string s1, std::string s2, Tip &n)
{
    std::cout << s1 << std::endl;
    while(!(std::cin>>n) || std::cin.peek()!='\n') {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << s2 << std::endl;
        std::cout << s1 << std::endl;
    }
}


int main ()
{
    double br1;
    int br2;
    std::string baza("Unesite bazu: ");
    std::string pokusaj("Neispravan unos, pokusajte ponovo...");
    std::string eksponent("Unesite cjelobrojni eksponent: ");
    UnosBroja(baza,pokusaj,br1);
    std::cout << std::endl;
    UnosBroja(eksponent,pokusaj,br2);
    
    double konacni=1;
    
    if(br2<0){
        int broj=fabs(br2);
        for(int i=0; i<broj; i++){
            konacni=konacni*(1./br1);
        }
    }
    else if(br2==0){
        konacni=1;
    }
    else{
        for(int i=0; i<br2; i++){
            konacni=konacni*br1;
        }
    }
    
    std::cout << std::endl << br1 << " na " << br2 << " iznosi " << konacni;

    return 0;
}

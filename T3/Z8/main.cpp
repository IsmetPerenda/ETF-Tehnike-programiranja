//TP 2017/2018: Tutorijal 3, Zadatak 8
#include <iostream>
#include <string>

int BrojRijeci (std::string s){
    int brojac=0;
    int razmak=1;
    
    for(int i=0; i<s.length(); i++){
        if(s.at(i)==' '){
            razmak=1;
        }
        else if(razmak==1){
            razmak=0;
            brojac++;
        }
    }
    return brojac;
}

std::string IzdvojiRijec (std::string s, int n){
    s.push_back(' '); //dodaje space na kraju stringa
    std::string a;
    std::string rijec;
    int rijeci=BrojRijeci(s);
    
    if(n<1 || n>rijeci){
        throw std::range_error("IZUZETAK: Pogresan redni broj rijeci!");
    }
    
    int brojac=0;
    int razmak=1;
    int duzinarijeci=0;
    for(int i=0; i<s.length(); i++){
        if(s.at(i)==' '){
            razmak=1;
        }
        else if(razmak==1){
            razmak=0;
            brojac++;
            
            if(brojac==n){
                int j=i;
                while(s.at(i)!=' ' && i<=s.length()){
                    duzinarijeci++;
                    i++;
                }
                
                rijec=s.substr(j, duzinarijeci);
                break;
            }
        }
    }
    
    return rijec;
}

int main ()
{
    int n;
    std::string rijec;
    std::cout << "Unesite redni broj rijeci: ";
    std::cin >> n;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::string s;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, s);
    
    try {
        std::cout << "Rijec na poziciji " << n << " je " << IzdvojiRijec(s,n);
    }
    catch(std::range_error n) {
        std::cout << n.what();
    }
	return 0;
}

//TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::string VelikaSlova(std::string rijec){
    for(int i=0; i<rijec.length(); i++){
        if((rijec.at(i)>='a') && (rijec.at(i)<='z')){
            rijec.at(i)=std::toupper(rijec.at(i));
        }
    }
    return rijec;
}

bool VecaOd(std::string a, std::string najveca){
    if(VelikaSlova(a)>VelikaSlova(najveca)){
        return true;
    }
    return false;
}

bool ManjaOd(std::string a, std::string najmanja){
    if(VelikaSlova(a)<VelikaSlova(najmanja)){
        return true;
    }
    return false;
}

void IzdvojiKrajnjeRijeci(std::vector<std::string> s, std::string &prva, std::string &posljednja){
    
    if(s.size()==0){
        prva="";
        posljednja="";
        return;
    }
    
    prva=s.at(0);
    posljednja=s.at(0);
    for(int i=1; i<s.size(); i++){
        if(ManjaOd(s.at(i),prva)){
            prva=s.at(i);
        }
        if(VecaOd(s.at(i),posljednja)){
            posljednja=s.at(i);
        }
    }
}

void ZadrziDuplikate(std::vector<std::string> &s){
    std::vector<std::string> duplikati;
    
    for(int i=0; i<s.size(); i++){
        bool duplikat=false;
        for(int j=i+1; j<s.size(); j++){
            if(s.at(i)==s.at(j)){
                duplikat=true;
                break;
            }
        }
        if(duplikat==true){
            bool ponavljanje=false;
            for(int j=0; j<duplikati.size(); j++){
                if(s.at(i)==duplikati.at(j)){
                    ponavljanje=true;
                    break;
                }
            }
            if(ponavljanje==false){
                duplikati.push_back(s.at(i));
            }
        }
    }
    
    s=duplikati;
}

int main ()
{
    int n;
    std::string rijec;
    std::vector<std::string> rijeci;
    std::cout << "Koliko zelite unijeti rijeci: ";
    std::cin >> n;
    std::cout << "Unesite rijeci: " << std::endl;
    
    for(int i=0; i<n; i++){
        std::cin >> rijec;
        rijeci.push_back(rijec);
    }
    
    std::string prva;
    std::string posljednja;
    IzdvojiKrajnjeRijeci(rijeci,prva,posljednja);
    
    std::cout << "Prva rijec po abecednom poretku je: " << prva << std::endl;
    std::cout << "Posljednja rijec po abecednom poretku je: " << posljednja << std::endl;
    
    ZadrziDuplikate(rijeci);
    std::cout << "Rijeci koje se ponavljaju su: ";
    for(int i=0; i<rijeci.size(); i++){
        std::cout << rijeci.at(i) << " ";
    }
    
	return 0;
}
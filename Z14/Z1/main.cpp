//TP 2018/2019: Tutorijal 14, Zadatak 1
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

double Prosjek(std::vector<int> temp){
    double suma=0;
    double prosjek;
    
    for(int i=0; i<temp.size(); i++){
        suma+=temp.at(i);
    }
    
    prosjek=suma/temp.size();
    
    return prosjek;
}

struct Temperatura {
    int dan, mjesec, godina;
    std::string komentar;
    std::vector<int> temp;
};


int main ()
{
    std::vector<Temperatura> vektor;

    std::ifstream ulazni_tok("TEMPERATURE.TXT");
    if(!ulazni_tok) std::cout << "Datoteka TEMPERATURE.TXT ne postoji!\n";
    else {
        while(!ulazni_tok.eof()) {
            int d,m,g;
            std::string kom;
            std::vector<int> pomocni;
            char znak;

            ulazni_tok >> d >> znak >> m >> znak >> g;
            ulazni_tok.ignore(10000, '\n');
            std::getline(ulazni_tok, kom);

            for(;;) {
                int temp;
                char zarez;

                ulazni_tok >> temp;

                pomocni.push_back(temp);

                if(ulazni_tok.peek()==',') {
                    ulazni_tok >> zarez;
                    continue;
                } else break;
            }
            
            vektor.push_back({d, m, g, kom, pomocni});
        }
        if(ulazni_tok.bad()) std::cout << "Problemi pri citanju datoteke TEMPERATURE.TXT\n";
    }
    
    std::sort(vektor.begin(), vektor.end(), [](Temperatura temp1, Temperatura temp2) {
        if(temp1.godina!=temp2.godina) return temp1.godina<temp2.godina;
        if(temp1.mjesec!=temp2.mjesec) return temp1.mjesec<temp2.mjesec;
        if(temp1.dan!=temp2.dan) return temp1.dan<temp2.dan;
        double suma1=0;
        double suma2=0;
        double prosjek1;
        double prosjek2;
        
        for(int i=0; i<temp1.temp.size(); i++){
            suma1+=temp1.temp.at(i);
        }
        for(int i=0; i<temp2.temp.size(); i++){
            suma2+=temp2.temp.at(i);
        }
        
        prosjek1=suma1/temp1.temp.size();
        prosjek2=suma2/temp2.temp.size();
        
        return prosjek1<prosjek2;
    });
    
    ulazni_tok.close();
    
    std::ofstream izlazni_tok("IZVJESTAJ.TXT");
    
    for(int i=0; i<vektor.size(); i++){
        izlazni_tok << vektor.at(i).komentar << std::endl;
        for(int j=0; j<vektor.at(i).komentar.length(); j++) izlazni_tok << "-";
        
        izlazni_tok << std::endl;
        
        izlazni_tok << "Datum mjerenja: " << vektor.at(i).dan << "/" << vektor.at(i).mjesec << "/" << vektor.at(i).godina << std::endl;
        
        auto minimalni_element=std::min_element(vektor.at(i).temp.begin(), vektor.at(i).temp.end());
        auto maksimalni_element=std::max_element(vektor.at(i).temp.begin(), vektor.at(i).temp.end());
        
        izlazni_tok << "Minimalna temperatura: " << *minimalni_element << std::endl;
        izlazni_tok << "Maksimalna temperatura: " << *maksimalni_element << std::endl;
        
        //double suma=0;
        double prosjek;
        
        prosjek=Prosjek(vektor.at(i).temp);
        
        /*for(int k=0; k<vektor.at(i).temp.size(); k++){
            suma+=vektor.at(i).temp.at(k);
        }
        prosjek=suma/vektor.at(i).temp.size();*/
        
        izlazni_tok << "Prosjecna temperatura: " << std::fixed << std::setprecision(2) << prosjek << std::endl << std::endl;
    }
    
    izlazni_tok.close();
    
    return 0;
}

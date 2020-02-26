//TP 2018/2019: Tutorijal 14, Zadatak 4
#include <iostream>
#include <fstream>

void IzvrniDatoteku(std::string datoteka){
    std::fstream tok_1(datoteka, std::ios::binary | std::ios::in | std::ios::out);
    if(!tok_1) throw std::logic_error("Datoteka ne postoji");
    std::fstream tok_2(datoteka, std::ios::binary | std::ios::in | std::ios::out);
    if(!tok_2) throw std::logic_error("Datoteka ne postoji");
    
    tok_1.seekg(0, std::ios::end); //pomjeram pokazivac na kraj, kako bih kasnije izracunao velicinu
    int duzina=tok_1.tellg();
    int br_elemenata=duzina/sizeof(double);
    //tellg() vraca broj bajta, pa cemo podijeliti sa velicinom double kako bi dobili broj elemenata
    
    int granica=br_elemenata/2; //do kojeg mjesta cemo ici u petlji
    
    for(int i=0; i<granica; i++) //idemo do pola jer obrcemo prvi sa posljednjim i sve tako
    {
        tok_1.seekg(0, std::ios::beg); //pomjeramo kursor na pocetak
        tok_2.seekg(0, std::ios::end); //pomjeramo kursor na kraj
        
        tok_1.seekg(i*sizeof(double), std::ios::beg); //pomjeram na trenutni element koji gledam
        tok_2.seekg((br_elemenata-i-1)*sizeof(double), std::ios::beg); //pomjeramo sa kraja
        
        double a, b;
        
        if(!tok_1.read(reinterpret_cast<char*>(&a), sizeof a)) throw std::logic_error("Problemi pri citanju datoteke"); //ucitavamo broj s lijeve strane
        if(!tok_2.read(reinterpret_cast<char*>(&b), sizeof b)) throw std::logic_error("Problemi pri citanju datoteke"); //ucitavamo broj s desne strane
        
        tok_1.seekp(i*sizeof(double), std::ios::beg); //pomjeramo kursor na i-ti element gledajuci od pocetka
        tok_2.seekp((br_elemenata-i-1)*sizeof(double), std::ios::beg); //pomjeramo kursor s kraja
        
        tok_1.write(reinterpret_cast<char*>(&b), sizeof b); //upisujemo b na mjesto gdje je pokazivao kursor u tok_1 tj tamo gdje je a
        tok_2.write(reinterpret_cast<char*>(&a), sizeof a); //upisujemo a na mjesto gdje je pokazivao kursor u tok_2 tj tamo gdje je b
    }
    
    tok_1.close();
    tok_2.close();
}

int main ()
{
    double niz[5]={2,4,6,8,10};
    double novi[5]{};
    
    std::ofstream dat1("IZVRTANJE.BIN", std::ios::binary);
    dat1.write((char *)niz, sizeof niz);
    dat1.close();
    
    IzvrniDatoteku("IZVRTANJE.BIN");
    
    std::ifstream dat2("IZVRTANJE.BIN", std::ios::binary);
    dat2.read((char *)novi, sizeof novi);
    
    for(int i=0; i<5; i++){
        std::cout << novi[i] << " ";
    }
    dat2.close();
    
	return 0;
}
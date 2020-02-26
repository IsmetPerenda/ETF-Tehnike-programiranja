//TP 2017/2018: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;

Matrica KreirajMatricu (int br_redova, int br_kolona){
    return Matrica (br_redova, std::vector<int>(br_kolona));
}

int BrojRedova (Matrica m){
    return m.size();
}

int SirinaKolone (Matrica m, int i){
    return m[i].size();
}

Matrica KroneckerovProizvod (std::vector<int> a, std::vector<int> b){
    auto c = KreirajMatricu(a.size(), b.size());
    
    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<b.size(); j++)
        {
            c[i][j]=a[i]*b[j];
        }
    }
    
    return c;
}

int NajvecaSirina (Matrica c){
    int maks=0;
    
    for(int i=0; i<BrojRedova(c); i++){
        for(int j=0; j<SirinaKolone(c,i); j++){
            int broj=c[i][j];
            int brojac=0;
            if(broj<0){
                brojac++;
                broj=abs(broj);
            }
            while(broj!=0){
                brojac++;
                broj=broj/10;
            }
            if(brojac>maks){
                maks=brojac;
            }
        }
    }
    
    return maks;
}

int main ()
{
    int m,n;
    int broj;
    std::vector<int> v1;
    std::vector<int> v2;
    
    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> m;
    std::cout << "Unesite elemente prvog vektora: ";
    for(int i=0; i<m; i++)
    {
        std::cin >> broj;
        v1.push_back(broj);
    }
    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n;
    std::cout << "Unesite elemente drugog vektora: ";
    for(int i=0; i<n; i++)
    {
        std::cin >> broj;
        v2.push_back(broj);
    }
    std::cout << std::endl;
    
    auto v3=KroneckerovProizvod(v1,v2);
    
    int sirina=NajvecaSirina(v3);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            std::cout << std::right << std::setw(sirina+1) << v3[i][j];
        }
        std::cout << std::endl;
    }
    
	return 0;
}
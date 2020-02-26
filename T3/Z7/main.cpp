//TP 2017/2018: Tutorijal 3, Zadatak 7
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;

Matrica KreirajMatricu (int br_redova, int br_kolona)
{
    return Matrica (br_redova, std::vector<int>(br_kolona));
}

int BrojRedova (Matrica m)
{
    return m.size();
}

int BrojKolona (Matrica m)
{
    return m[0].size();
}

int SirinaKolone (Matrica m, int i)
{
    return m[i].size();
}

Matrica PascalovTrougao (int n)
{
    if(n==0){
        auto m=KreirajMatricu(1,1);
        m[0][0]=0;
    }
    if(n<0) throw std::domain_error("Broj redova ne smije biti negativan");
    auto m=KreirajMatricu(n,n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(j>i) {
                break;
            }
            if(j==0) {
                m[i][j]=1;
            } else if(j==i) {
                m[i][j]=1;
            } else {
                m[i][j]=m[i-1][j]+m[i-1][j-1];
            }
        }
    }

    return m;
}

int NajvecaSirina (Matrica c)
{
    int maks=0;

    for(int i=0; i<BrojRedova(c); i++) {
        for(int j=0; j<SirinaKolone(c,i); j++) {
            if(j>i) break;
            else {
                int broj=c[i][j];
                int brojac=0;
                if(broj<0) {
                    brojac++;
                    broj=abs(broj);
                }
                while(broj!=0) {
                    brojac++;
                    broj=broj/10;
                }
                if(brojac>maks) {
                    maks=brojac;
                }
            }
        }
    }

    return maks;
}

int main ()
{
    int n;
    try {
        std::cout << "Unesite broj redova:";
        std::cin >> n;
        std::cout << std::endl;
    }
    catch(const char poruka[]) {
        std::cout << poruka << std::endl;
        return 0;
    }

    auto m=PascalovTrougao(n);

    int sirina=NajvecaSirina(m);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j>i) break;
            else {
                std::cout << std::right << std::setw(sirina+1) << m[i][j];
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

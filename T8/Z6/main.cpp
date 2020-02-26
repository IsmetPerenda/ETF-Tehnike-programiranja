//TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>

template <typename TipElemenata>
struct Cvor{
    TipElemenata element;
    Cvor *veza;
};

template <typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni){
    Cvor<TipElemenata> *pocetak=nullptr; Cvor<TipElemenata> *prethodni;
    for(;;){
        TipElemenata broj;
        std::cin >> broj;
        if(abs(broj-zavrsni)<0.000001) break;
        Cvor<TipElemenata> *novi=new Cvor<TipElemenata>;
        novi->element=broj;
        novi->veza=nullptr;
        if(!pocetak) pocetak=novi;
        else prethodni->veza=novi;
        prethodni=novi;
    }
    
    return pocetak;
}

template <typename TipElemenata>
int BrojElemenata(Cvor<TipElemenata> *pocetak){
    int brojac=0;                                                   //brojac elemenata te liste
    if(pocetak!=nullptr){
        for(Cvor<TipElemenata>* p=pocetak; p!=nullptr; p=p->veza){
            brojac++;
        }
    }
    
    return brojac;
}

template <typename TipElemenata>
TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak){
    TipElemenata suma{};                                            //postavljamo sumu na podrazumijevanu vrijednost za taj tip elemenata
    if(pocetak!=nullptr){
        for(Cvor<TipElemenata>* p=pocetak; p!=nullptr; p=p->veza){
            suma=suma+(p->element);                                 //vrtimo petlju i dodajemo na sumu
        }
    }
    
    return suma;
}

template <typename TipElemenata>
int BrojVecihOd(Cvor<TipElemenata> *pocetak, TipElemenata prag){
    int brojac=0;
    if(pocetak!=nullptr){
        for(Cvor<TipElemenata>* p=pocetak; p!=nullptr; p=p->veza){
            if((p->element)>prag){
                brojac++;                                           //ako je element veci od praga koji smo prenijeli u funkciju, povecamao brojac
            }
        }
    }
    
    return brojac;
}

template <typename TipElemenata>
void UnistiListu(Cvor<TipElemenata> *pocetak){
    /*Cvor<TipElemenata> *trenutni=pocetak;
    Cvor<TipElemenata> *naredni=pocetak;
    while(naredni!=nullptr){
        naredni=trenutni->veza;
        delete trenutni;
        trenutni=naredni;
    }*/
    
    if(pocetak==nullptr) return;
    else{
        UnistiListu(pocetak->veza);
        delete pocetak;
    }
}

int main ()
{
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    auto lista=KreirajPovezanuListu<double>(0);                     //kreiramo listu, a 0 je za kraj
    auto suma=SumaElemenata(lista)           ;                      //racunamo sumu elemenata liste
    auto broj_elemenata=BrojElemenata(lista);                       //racunamo koliko ima elemenata
    auto veci=BrojVecihOd(lista, (suma/broj_elemenata));            //racunamo koliko ima brojeva vecih od zadanog
    std::cout << "U slijedu ima " << veci << " brojeva vecih od njihove aritmeticke sredine";
    UnistiListu(lista);
    
	return 0;
}
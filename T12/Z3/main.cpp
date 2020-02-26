/* 
    TP 16/17 (Tutorijal 12, Zadatak 3)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

std::ostream &operator <<(std::ostream &tok, Dani d){
	if(d==0) tok << "Ponedjeljak";
	if(d==1) tok << "Utorak";
	if(d==2) tok << "Srijeda";
	if(d==3) tok << "Cetvrtak";
	if(d==4) tok << "Petak";
	if(d==5) tok << "Subota";
	if(d==6) tok << "Nedjelja";
	
	return tok;
}

Dani operator ++(Dani &d, int){
	Dani pomocni=d;
	if(d==0) d=Dani(1);
	else if(d==1) d=Dani(2);
	else if(d==2) d=Dani(3);
	else if(d==3) d=Dani(4);
	else if(d==4) d=Dani(5);
	else d=Dani(6);
	
	return pomocni;
}

int main ()
{
	for(Dani d=Ponedjeljak; d<=Petak; d++) std::cout << d << std::endl;
	return 0;
}
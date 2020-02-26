//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>

void IzvrniString (std::string &s){
    for(int i=0; i<s.length()/2; i++){
        char tmp=s.at(i);
        s.at(i)=s.at(s.length()-i-1);
        s.at(s.length()-i-1)=tmp;
    }
}

int main ()
{
    std::string s;
    std::cout << "Unesi string: ";
    std::getline(std::cin, s);
    std::cout << "Izvrnuti string je: ";
    IzvrniString(s);
    std::cout << s;
	return 0;
}
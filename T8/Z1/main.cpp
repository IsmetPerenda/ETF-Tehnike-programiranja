//TP 2018/2019: Tutorijal 8, Zadatak 1
#include <iostream>
#include <iomanip>

struct Vrijeme {
    int sati;
    int minute;
    int sekunde;
};

void TestirajVrijeme(const Vrijeme &v)
{
    if(v.sati<0 || v.sati>23 || v.minute<0 || v.minute>59|| v.sekunde<0 || v.sekunde>59) {
        throw std::domain_error("Neispravno vrijeme");
    }
}

void UnesiVrijeme(Vrijeme &v)
{
    std::cin >> v.sati >> v.minute >> v.sekunde;
}

void IspisiVrijeme(const Vrijeme &v)
{
    try {
        TestirajVrijeme(v);
    } catch(...) {
        throw;
    }
    std::cout << std::setw(2) << std::setfill('0') << v.sati << ":";
    std::cout << std::setw(2) << std::setfill('0') << v.minute << ":";
    std::cout << std::setw(2) << std::setfill('0') << v.sekunde;
}

Vrijeme SaberiVrijeme(const Vrijeme &v1, const Vrijeme &v2)
{
    try {
        TestirajVrijeme(v1);
        TestirajVrijeme(v2);
    } catch(std::domain_error e) {
        std::cout << e.what() << std::endl;
    }
    
    Vrijeme v;
    
    v.sekunde=v1.sekunde+v2.sekunde;
    v.minute=v1.minute+v2.minute;
    v.sati=v1.sati+v2.sati;
    
    if(v.sekunde>59){
        v.sekunde=v.sekunde-60;
        v.minute++;
    }
    
    if(v.minute>59){
        v.minute=v.minute-60;
        v.sati++;
    }
    
    if(v.sati>23){
        v.sati=v.sati%24;
    }

    return v;
}

int main ()
{
    Vrijeme v1;
    Vrijeme v2;

    try {
        std::cout << "Unesite prvo vrijeme (h m s): ";
        UnesiVrijeme(v1);
        TestirajVrijeme(v1);

        std::cout << "Unesite drugo vrijeme (h m s): ";
        UnesiVrijeme(v2);
        TestirajVrijeme(v2);

        std::cout << "Prvo vrijeme: ";
        IspisiVrijeme(v1);
        std::cout << std::endl;

        std::cout << "Drugo vrijeme: ";
        IspisiVrijeme(v2);
        std::cout << std::endl;

        std::cout << "Zbir vremena: ";
        IspisiVrijeme(SaberiVrijeme(v1,v2));

    } catch(std::domain_error e) {
        std::cout << e.what();
    }


    return 0;
}

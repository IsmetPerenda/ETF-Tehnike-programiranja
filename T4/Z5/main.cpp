//TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
template<typename Tip>

std::vector<Tip> Presjek(std::vector<Tip> v1, std::vector<Tip> v2)
{
    std::vector<Tip> presjek;

    for(int i=0; i<v1.size(); i++) {
        for(int j=0; j<v2.size(); j++) {
            if(v1.at(i)==v2.at(j)) {
                presjek.push_back(v1.at(i));
            }
        }
    }

    for(int i=0; i<presjek.size(); i++) {
        for(int j=i+1; j<presjek.size(); j++) {
            if(presjek.at(j)==presjek.at(i)) {
                presjek.erase(presjek.begin()+j);
                j--;
            }
        }
    }

    return presjek;
}

int main ()
{
    //testovi za realne brojeve
    int m1;
    double broj;
    std::vector<double> v1;
    std::cout << "Test za realne brojeve..." << std::endl;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> m1;
    std::cout << "Unesite elemente prvog vektora: ";
    for(int i=0; i<m1; i++) {
        std::cin >> broj;
        v1.push_back(broj);
    }
    int n1;
    std::vector<double> v2;
    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n1;
    std::cout << "Unesite elemente drugog vektora: ";
    for(int i=0; i<n1; i++) {
        std::cin >> broj;
        v2.push_back(broj);
    }
    std::cout << "Zajednicki elementi su: ";
    auto v3=Presjek(v1,v2);
    for(int i=0; i<v3.size(); i++) {
        std::cout << v3.at(i) << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    //testovi za stringove
    int m2;
    std::vector<std::string> s1;
    std::cout << "Test za stringove..." << std::endl;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> m2;
    std::cin.ignore(10000,'\n');
    std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
    for(int i=0; i<m2; i++) {
        std::string s;
        std::getline(std::cin,s);
        s1.push_back(s);
    }
    int n2;
    std::vector<std::string> s2;
    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n2;
    std::cin.ignore(10000,'\n');
    std::cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
    for(int i=0; i<n2; i++) {
        std::string s;
        std::getline(std::cin,s);
        s2.push_back(s);
    }
    std::cout << "Zajednicki elementi su: " << std::endl;
    auto s3=Presjek(s1,s2);
    for(int i=0; i<s3.size(); i++) {
        std::cout << s3.at(i);
        std::cout << std::endl;
    }


    return 0;
}

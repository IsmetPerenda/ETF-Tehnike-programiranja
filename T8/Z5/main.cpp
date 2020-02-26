//TP 2018/2019: Tutorijal 8, Zadatak 5
#include <iostream>
#include <tuple>

typedef std::tuple<double, double, double> Vektor3d;

void UnesiVektor(Vektor3d &v) {
    double x,y,z;
    std::cout << "X = ";
    std::cin >> x;
    std::get<0>(v)=x;
    
    std::cout << "Y = ";
    std::cin >> y;
    std::get<1>(v)=y;
    
    std::cout << "Z = ";
    std::cin >> z;
    std::get<2>(v)=z;
}

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2){
    double x,y,z;
    x=std::get<0>(v1)+std::get<0>(v2);
    y=std::get<1>(v1)+std::get<1>(v2);
    z=std::get<2>(v1)+std::get<2>(v2);
    
    auto v=std::tie(x, y, z);
    
    return v;
}

Vektor3d VektorskiProizvod(const Vektor3d &v1, const Vektor3d &v2){
    double x,y,z;
    x=(std::get<1>(v1)*std::get<2>(v2))-(std::get<2>(v1)*std::get<1>(v2));
    y=(std::get<2>(v1)*std::get<0>(v2))-(std::get<0>(v1)*std::get<2>(v2));
    z=(std::get<0>(v1)*std::get<1>(v2))-(std::get<1>(v1)*std::get<0>(v2));
    
    auto v=std::tie(x, y, z);
    
    return v;
}

void IspisiVektor(const Vektor3d &v){
    std::cout << "{" << std::get<0>(v) << "," << std::get<1>(v) << "," << std::get<2>(v) << "}";
}

int main ()
{
    Vektor3d a, b;
    std::cout << "Unesi prvi vektor:\n";
    UnesiVektor(a);
    std::cout << "Unesi drugi vektor:\n";
    UnesiVektor(b);
    std::cout << "Suma ova dva vektora je: ";
    IspisiVektor(ZbirVektora(a, b));
    std::cout << std::endl << "Njihov vektorski prozivod je: ";
    IspisiVektor(VektorskiProizvod(a, b));
	return 0;
}
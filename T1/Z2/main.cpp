#include <iostream>
#include <cmath>

int main ()
{
    double a,b,c;
    
    std::cout << "Unesite tri broja: ";
    std::cin >> a >> b >> c;
    
    if(a+b>c && a+c>b && b+c>a && a>0 && b>0 && c>0)
    {
        double s=(a+b+c)/2;
        double P=sqrt(s*(s-a)*(s-b)*(s-c));
        const double PI=4*atan(1);
        double alfa,beta,gama;
        alfa=acos((b*b+c*c-a*a)/(2*b*c));
        beta=acos((a*a+c*c-b*b)/(2*a*c));
        gama=acos((a*a+b*b-c*c)/(2*a*b));
        
        double najmanji;
        if(alfa<=beta && alfa<=gama) najmanji=alfa;
        if(beta<=alfa && beta<=gama) najmanji=beta;
        if(gama<=alfa && gama<=beta) najmanji=gama;
        
        double step;
        step=(najmanji*180.0)/PI;
        double stepeni = int(step);
        double min=(step-stepeni)*60;
        double minute = int(min);
        double sek = int(min);
        int sekunde=(min-sek)*60;
        
        std::cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i " << c << " iznosi " << a+b+c << "." << std::endl;
        std::cout << "Njegova povrsina iznosi " << P << "." << std::endl;
        std::cout << "Njegov najmanji ugao ima " << stepeni << " stepeni, " << minute << " minuta i " << sekunde << " sekundi.";
    }
    
    else
    {
        std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b << " i " << c << "!";
    }
	return 0;
}
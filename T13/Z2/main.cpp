/* 
    TP 16/17 (Tutorijal 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>

class ApstraktniStudent{
protected:
	std::string ime;
	std::string prezime;
	int indeks;
	int polozeni;
	double prosjek;
public:
	ApstraktniStudent(std::string ime, std::string prezime, int indeks) : ime(ime), prezime(prezime), indeks(indeks), polozeni(0), prosjek(5) {}
	virtual ~ApstraktniStudent(){}
	std::string DajIme() const { return ime; }
	std::string DajPrezime() const { return prezime; }
	int DajBrojIndeksa() const { return indeks; }
	int DajBrojPolozenih() const { return polozeni; }
	double DajProsjek() const { return prosjek; }
	void RegistrirajIspit(int ocjena){
		if(ocjena<5 || ocjena>10) throw std::domain_error("Neispravna ocjena");
		if(ocjena==5) return;									//ocjena 5 legalna, ali ne treba nista uraditi funkcija
		
		double suma;
		suma=prosjek*polozeni;
		polozeni++;
		prosjek=(suma+ocjena)/polozeni;
	}
	void PonistiOcjene(){										//resetiramo sve ako pozovemo ovu funkciju
		polozeni=0;
		prosjek=5;
	}
	virtual void IspisiPodatke() const=0;
	virtual ApstraktniStudent* DajKopiju() const=0;
};

class StudentBachelor : public ApstraktniStudent{
	public:
	StudentBachelor(std::string ime, std::string prezime, int indeks) : ApstraktniStudent(ime, prezime, indeks) {}
	void IspisiPodatke() const override{
		std::cout << "Student bachelor studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << "," << std::endl << "ima prosjek " << DajProsjek() << "." << std::endl;
	}
	ApstraktniStudent* DajKopiju() const override { return new StudentBachelor(*this); }
};

class StudentMaster : public ApstraktniStudent{
	int godina_diplomiranja;
	public:
	StudentMaster(std::string ime, std::string prezime, int indeks, int godina_diplomiranja) : ApstraktniStudent(ime, prezime, indeks), godina_diplomiranja(godina_diplomiranja) {}
	void IspisiPodatke() const override{
		std::cout << "Student master studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << "," << std::endl << "zavrsio bachelor studij godine " << godina_diplomiranja << ",ima prosjek " << DajProsjek() << "." << std::endl;
	}
	ApstraktniStudent* DajKopiju() const override { return new StudentMaster(*this); }
};

int main ()
{
	StudentMaster s("Kemal", "Kemalovic", 18181, 2016);
	s.RegistrirajIspit(5); s.RegistrirajIspit(6);
	s.RegistrirajIspit(7); s.RegistrirajIspit(8);
	s.RegistrirajIspit(9); s.RegistrirajIspit(10);
	s.IspisiPodatke();
	std::cout << std::endl;
	
	std::cout << "Ime: " << s.DajIme() << std::endl;
	std::cout << "Prezime: " << s.DajPrezime() << std::endl;
	std::cout << "Indeks: " << s.DajBrojIndeksa() << std::endl;
	std::cout << "Broj polozenih: " << s.DajBrojPolozenih() << std::endl;
	std::cout << "Prosjek: " << s.DajProsjek() << std::endl;
	return 0;
}
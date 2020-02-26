/* 
    TP 16/17 (Tutorijal 13, Zadatak 4)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ApstraktniStudent{
	protected:
	std::string ime;
	std::string prezime;
	int indeks;
	int polozeni;
	double prosjek;
	public:
	ApstraktniStudent(std::string ime, std::string prezime, int indeks) : ime(ime), prezime(prezime), indeks(indeks), polozeni(0), prosjek(5) {}
	virtual ~ApstraktniStudent() {}
	std::string DajIme() const { return ime; }
	std::string DajPrezime() const { return prezime; }
	int DajBrojIndeksa() const { return indeks; }
	int DajBrojPolozenih() const { return polozeni; }
	double DajProsjek() const { return prosjek; }
	void RegistrirajIspit(int ocjena){
		if(ocjena<5 || ocjena>10) throw std::domain_error("Neispravna ocjena");
		if(ocjena==5) return;
		
		double suma;
		suma=prosjek*polozeni;
		polozeni++;
		prosjek=(suma+ocjena)/polozeni;
	}
	void PonistiOcjene(){
		polozeni=0;
		prosjek=5;
	}
	virtual void IspisiPodatke() const=0;
	virtual ApstraktniStudent* DajKopiju() const=0;
};

class StudentBachelor: public ApstraktniStudent{
	public:
	StudentBachelor(std::string ime, std::string prezime, int indeks) : ApstraktniStudent(ime, prezime, indeks) {}
	void IspisiPodatke() const override{
		std::cout << "Student bachelor studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << "," << std::endl << "ima prosjek " << DajProsjek() << "." << std::endl;
	}
	ApstraktniStudent* DajKopiju() const override { return new StudentBachelor(*this); }
};

class StudentMaster: public ApstraktniStudent{
	int godina_diplomiranja;
	public:
	StudentMaster(std::string ime, std::string prezime, int indeks, int godina_diplomiranja) : ApstraktniStudent(ime, prezime, indeks), godina_diplomiranja(godina_diplomiranja) {}
	void IspisiPodatke() const override{
		std::cout << "Student master studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << "," << std::endl << "zavrsio bachelor studij godine " << godina_diplomiranja << ",ima prosjek " << DajProsjek() << "." << std::endl;
	}
	ApstraktniStudent* DajKopiju() const override { return new StudentMaster(*this); }
};

class Student{
	ApstraktniStudent *p_student;
	void Test() const{
		if(!p_student) throw std::logic_error("Nespecificiran student!");
	}
	public:
	Student() : p_student(nullptr) {}
	~Student() { delete p_student; }
	Student(const ApstraktniStudent &student) : p_student(student.DajKopiju()) {}
	Student(const Student &student){
		if(!student.p_student) p_student=nullptr;
		else p_student=student.p_student->DajKopiju();
	}
	Student(Student &&student){
		p_student=student.p_student;
		student.p_student=nullptr;
	}
	Student &operator =(const Student &student){
		ApstraktniStudent *p_novi(nullptr);
		if(student.p_student!=nullptr) p_novi=student.p_student->DajKopiju();
		delete p_student;
		p_student=p_novi;
		return *this;
	}
	Student &operator =(Student &&student){
		std::swap(p_student, student.p_student);
		return *this;
	}
	std::string DajIme() const { return p_student->DajIme(); }
	std::string DajPrezime() const { return p_student->DajPrezime(); }
	int DajBrojIndeksa() const { return p_student->DajBrojIndeksa(); }
	int DajBrojPolozenih() const { return p_student->DajBrojPolozenih(); }
	double DajProsjek() const { return p_student->DajProsjek(); }
	void RegistrirajIspit(int ocjena){
		p_student->RegistrirajIspit(ocjena);
	}
	void PonistiOcjene() { p_student->PonistiOcjene(); }
	void IspisiPodatke() const { p_student->IspisiPodatke(); }
};

int main ()
{
	StudentBachelor sb("Dusko", "Dugousko", 1234);
	StudentMaster sm("Paja", "Patak", 4312, 2015);
	Student s1(sb); Student s2(sm);
	s1 = s2;
	s1.IspisiPodatke();
	return 0;
}
/* 
    TP 16/17 (Tutorijal 13, Zadatak 3)
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
	virtual ~ApstraktniStudent(){}											//destruktor za sve izvedene klase
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

class Fakultet{
	std::vector<ApstraktniStudent*> vektor;
	public:
	~Fakultet(){
		for(int i=0; i<vektor.size(); i++) delete vektor[i];
	}
	Fakultet()=default;
	Fakultet(const Fakultet &f){
		vektor.resize(f.vektor.size());
		for(int i=0; i<f.vektor.size(); i++){
			vektor[i]=f.vektor[i]->DajKopiju();
		}
	}
	Fakultet(Fakultet &&f){
		vektor=std::move(f.vektor);
	}
	Fakultet &operator =(Fakultet f){
		std::swap(vektor, f.vektor);
		return *this;
	}
	void UpisiStudenta(std::string ime, std::string prezime, int indeks){
		for(int i=0; i<vektor.size(); i++){
			if(vektor[i]->DajBrojIndeksa()==indeks) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
		}
		
		vektor.push_back(new StudentBachelor(ime, prezime, indeks));
	}
	void UpisiStudenta(std::string ime, std::string prezime, int indeks, int godina_diplomiranja){
		for(int i=0; i<vektor.size(); i++){
			if(vektor[i]->DajBrojIndeksa()==indeks) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
		}
		
		vektor.push_back(new StudentMaster(ime, prezime, indeks, godina_diplomiranja));
	}
	void ObrisiStudenta(int indeks){
		bool jelobrisan=false;
		
		for(int i=0; i<vektor.size(); i++){
			if(vektor[i]->DajBrojIndeksa()==indeks){
				delete vektor[i];
				vektor.erase(vektor.begin()+i);
				jelobrisan=true;
			}
		}
		
		if(!jelobrisan) throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	ApstraktniStudent &operator [](int indeks) const{
		for(int i=0; i<vektor.size(); i++){
			if(vektor[i]->DajBrojIndeksa()==indeks) return *vektor[i];
		}
		
		throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	void IspisiSveStudente() const{
		auto novi=vektor;//jer treba da se ne promijeni stari vektor;
		
		std::sort(novi.begin(), novi.end(), [](ApstraktniStudent* student1, ApstraktniStudent* student2)->bool {
			if(student1->DajProsjek()!=student2->DajProsjek()){
				return student1->DajProsjek() > student2->DajProsjek();
			}
			else{
				return student1->DajBrojIndeksa() < student2->DajBrojIndeksa();
			}
		});
		
		for(int i=0; i<novi.size(); i++) novi[i]->IspisiPodatke();
	}
};

int main ()
{
	Fakultet etf;
	etf.UpisiStudenta("Sulejman", "Velicanstveni", 1111);
	etf.UpisiStudenta("Mehmed-pasa", "Sokolovic", 2222, 1594);
	
	etf[1111].RegistrirajIspit(7); etf[1111].RegistrirajIspit(9); etf[1111].RegistrirajIspit(6);
	etf[2222].RegistrirajIspit(5); etf[2222].RegistrirajIspit(6); etf[2222].RegistrirajIspit(7);
	
	etf.IspisiSveStudente();
	
	std::cout << std::endl;
	
	etf[1111].RegistrirajIspit(7); etf[1111].RegistrirajIspit(5); etf[1111].RegistrirajIspit(6);
	
	etf.IspisiSveStudente();
	
	return 0;
}
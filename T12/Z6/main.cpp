#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>

template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica()
	{
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1, const Matrica<Tip2> &m2);
	template <typename Tip3>
	friend std::istream &operator >>(std::istream &tok, Matrica<Tip3> &mat);
	template <typename Tip4>
	friend std::ostream &operator <<(std::ostream &tok, const Matrica<Tip4> &mat);
	template <typename Tip5>
	friend Matrica<Tip5> operator -(const Matrica<Tip5> &m1, const Matrica<Tip5> &m2);
	template <typename Tip6>
	friend Matrica<Tip6> operator *(const Matrica<Tip6> &m1, const Matrica<Tip6> &m2);
	template <typename Tip7>
	friend Matrica<Tip7> operator *(const Matrica<Tip7> &m, int broj);
	template <typename Tip8>
	friend Matrica<Tip8> operator *(int broj, const Matrica<Tip8> &m);
	Matrica &operator +=(const Matrica &m);
	Matrica &operator -=(const Matrica &m);
	Matrica &operator *=(const Matrica &m);
	Matrica &operator *=(int broj);
	TipEl* &operator [](int indeks)
	{
		return (elementi[indeks]);
	}
	TipEl* operator [](int indeks) const
	{
		return elementi[indeks];
	}
	TipEl &operator ()(int i, int j)
	{
		if(i<1 || i>this->br_redova) throw std::range_error("Neispravan indeks");
		
		if(j<1 || j>this->br_kolona) throw std::range_error("Neispravan indeks");
		
		return elementi[i-1][j-1];
	}
	TipEl operator ()(int i, int j) const
	{
		if(i<1 || i>this->br_redova) throw std::range_error("Neispravan indeks");
		
		if(j<1 || j>this->br_kolona) throw std::range_error("Neispravan indeks");
		
		return elementi[i-1][j-1];
	}
	
	operator std::string() const
	{
		std::string matrica;
		matrica.push_back('{');
		
		for(int i=0; i<this->br_redova; i++){
			matrica.push_back('{');
			for(int j=0; j<this->br_kolona; j++){	
				auto trenutni=int(elementi[i][j]);
				std::string clan=std::to_string(trenutni);
				matrica+=clan;
				if(j!=((this->br_kolona)-1)){
					matrica.push_back(',');
				}
			}
			matrica.push_back('}');
			if(i!=((this->br_redova)-1)){
				matrica.push_back(',');
			}
		}
		
		matrica.push_back('}');
		
		return matrica;
	}
};

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi = new TipEl*[br_redova] {};
	try {
		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
	} catch(...) {
		DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
	br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
	
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
	m.br_redova = 0;
	m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
	if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
		TipEl **novi_prostor = AlocirajMemoriju(m.br_redova, m.br_kolona);
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	} else if(br_redova > m.br_redova)
		for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}

template <typename TipEl>
std::istream &operator >>(std::istream &tok, Matrica<TipEl> &mat)
{
	for(int i = 0; i < mat.br_redova; i++)
		for(int j = 0; j < mat.br_kolona; j++) {
			std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> mat.elementi[i][j];
		}
	
	return tok;
}

template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, const Matrica<TipEl> &mat)
{
	int sirina=tok.width();
	
	for(int i=0; i<mat.br_redova; i++){
		for(int j=0; j<mat.br_kolona; j++){
			tok << std::setw(sirina) << mat.elementi[i][j];
		}
		tok << std::endl;
	}
	
	return tok;
}

template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	
	for(int i=0; i<m1.br_redova; i++){
		for(int j=0; j<m1.br_kolona; j++){
			m3.elementi[i][j]=m1.elementi[i][j]+m2.elementi[i][j];
		}
	}
	
	return m3;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>:: operator +=(const Matrica<TipEl> &m)
{
	if(this->br_redova!=m.br_redova || this->br_kolona!=m.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	
	for(int i=0; i<m.br_redova; i++){
		for(int j=0; j<m.br_kolona; j++){
			this->elementi[i][j]+=m.elementi[i][j];
		}
	}
	
	return *this;
}

template <typename TipEl>
Matrica<TipEl> operator -(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_redova!=m2.br_redova || m1.br_kolona!=m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	
	for(int i=0; i<m1.br_redova; i++){
		for(int j=0; j<m1.br_kolona; j++){
			m3.elementi[i][j]=m1.elementi[i][j]-m2.elementi[i][j];
		}
	}
	
	return m3;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>:: operator -=(const Matrica &m)
{
	if(this->br_redova!=m.br_redova || this->br_kolona!=m.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	
	for(int i=0; i<m.br_redova; i++){
		for(int j=0; j<m.br_kolona; j++){
			this->elementi[i][j]-=m.elementi[i][j];
		}
	}
	
	return *this;
}

template <typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)
{
	if(m1.br_kolona!=m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m3(m1.br_redova, m2.br_kolona);
	
	for(int i=0; i<m1.br_redova; i++){
		for(int j=0; j<m2.br_kolona; j++){
			double sum=0;
			for(int k=0; k<m2.br_redova; k++){
				sum+=m1.elementi[i][k]*m2.elementi[k][j];
			}
			m3.elementi[i][j]=sum;
		}
	}
	
	return m3;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>:: operator *=(const Matrica<TipEl> &m)
{
	if(this->br_kolona!=m.br_redova) throw("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> m2(this->br_redova, m.br_kolona);
	
	for(int i=0; i<m2.br_redova; i++){
		for(int j=0; j<m2.br_kolona; j++){
			double sum=0;
			for(int k=0; k<m.br_redova; k++){
				sum+=this->elementi[i][k]*m.elementi[k][j];
			}
			m2.elementi[i][j]=sum;
		}
	}
	
	*this=m2;
	return *this;
}

template <typename TipEl>
Matrica<TipEl> operator *(const Matrica<TipEl> &m, int broj)
{
	Matrica<TipEl> m2(m.br_redova, m.br_kolona);
	for(int i=0; i<m2.br_redova; i++){
		for(int j=0; j<m2.br_kolona; j++){
			m2.elementi[i][j]=1;
		}
	}
	for(int i=0; i<m2.br_redova; i++){
		for(int j=0; j<m2.br_kolona; j++){
			m2.elementi[i][j]=m.elementi[i][j]*broj;
		}
	}
	
	return m2;
}

template <typename TipEl>
Matrica<TipEl> operator *(int broj, const Matrica<TipEl> &m)
{
	return m*broj;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>:: operator *=(int broj)
{
	for(int i=0; i<this->br_redova; i++){
		for(int j=0; j<this->br_kolona; j++){
			this->elementi[i][j]=this->elementi[i][j]*broj;
		}
	}
	return *this;
}

int main()
{
	
	return 0;
}

/* 
    TP 16/17 (Tutorijal 12, Zadatak 2)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

template <typename Tip>
std::set<Tip> operator +(std::set<Tip> set1, std::set<Tip> set2){
	std::set<Tip> unija;
	for(Tip x : set1){
		unija.insert(x);
	}
	for(Tip x : set2){
		unija.insert(x);
	}
	
	return unija;
}

template <typename Tip>
std::set<Tip> operator *(const std::set<Tip> &set1, const std::set<Tip> &set2){
	std::set<Tip> presjek;
	for(Tip x : set1){
		for(Tip y : set2){
			if(x==y){
				presjek.insert(x);
			}
		}
	}
	
	return presjek;
}

template <typename Tip>
std::set<Tip> operator +=(std::set<Tip> &set1, std::set<Tip> set2){
	for(auto &x : set2){
		set1.insert(x);
	}
	
	return set1;
}

template <typename Tip>
std::set<Tip> operator *=(std::set<Tip> &set1, const std::set<Tip> &set2){
	std::vector<Tip> nije_presjek;
	for(auto &x : set1){
		bool prisutan=false;
		for(auto &y : set2){
			if(x==y){
				prisutan=true;
			}
		}
		if(prisutan==false){
			nije_presjek.push_back(x);
		}
	}
	
	for(auto x : nije_presjek){
		set1.erase(x);
	}
	
	return set1;
}

template <typename Tip>
std::ostream &operator <<(std::ostream &tok, std::set<Tip> set1){
	if(set1.size()==0){
		tok << '{' << '}';
		return tok;
	}
	tok << '{';
	auto it=set1.begin();
	for(int i=0; i<set1.size(); i++){
		if(i==set1.size()-1){
			tok << *it << '}';
		}
		else{
			tok << *it << ',';
		}
		it++;
	}
	
	return tok;
}

template <typename Tip1, typename Tip2>
std::set<std::pair<Tip1, Tip2>> operator %(const std::set<Tip1> &skup1, const std::set<Tip2> &skup2){
	std::set<std::pair<Tip1, Tip2>> proizvod;
	
	for(auto x : skup1){
		for(auto y : skup2){
			proizvod.insert({x, y});
		}
	}
	
	return proizvod;
}

template <typename Tip1, typename Tip2>
std::ostream &operator <<(std::ostream &tok, std::pair<Tip1, Tip2> skup){
	return tok << "(" << skup.first << "," << skup.second << ")";
}

int main ()
{
	std::set<int> s1{3,5,1,2,8};
	std::set<int> s2{7,2,8,4};
	std::cout << s1 + s2 << std::endl;
	std::cout << s1 * s2 << std::endl;
	return 0;
}
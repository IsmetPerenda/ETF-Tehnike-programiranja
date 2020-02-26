//TP 2018/2019: Tutorijal 8, Zadatak 4
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::string ZamijeniPremaRjecniku(std::string s, std::map<std::string, std::string> rjecnik){
    std::string novi;
    
    for(int i=0; i<s.size(); i++){
        if(s[i]==' '){
            novi+=s[i];
        }
        else{
            std::string rijec;
            for(int j=i; s[j]!=' ' && j<s.size(); j++, i++){
                rijec+=s[j];
            }
            auto it=rjecnik.find(rijec);
            if(it!=rjecnik.end()){
                novi+=it->second;
            }
            else novi+=rijec;
            i--;
        }
    }
    
    return novi;
}

int main ()
{
    std::map<std::string, std::string> moj_rjecnik{{"jabuka", "apple"}, {"da", "yes"}, {"kako", "how"}, {"ne", "no"}, {"majmun", "monkey"}};
    std::cout << ZamijeniPremaRjecniku("kako da ne", moj_rjecnik);
	return 0;
}
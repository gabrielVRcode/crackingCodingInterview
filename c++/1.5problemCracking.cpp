#include <iostream>
#include <cstdlib>
using namespace std;

bool oneWay(string s1, string s2){
	int a = s1.length();
	int b = s2.length();
	
	if(abs(a-b)>1){
		return false;
	}else if(a==b){
		int cont=0;
		for(int i=0; i<a; i++){
			if(s1[i]!=s2[i]){
				cont++;
				if(cont==2){
					return false;
				}
			}
		}
		return true;
	}else{
		int i=0, i2=0, cont=0;
		if(a<b){
			string aux=s1;
			s2=s1;
			s1=aux;
		}
		while(i<b){
			if(s2[i]==s1[i2]){
				i++;
				i2++;
			}else{
				cont++;
				i2++;
				if(cont==2){ return false; }
			}
		}
		return true;
	}
	return true;
}

int main(){
	string s1, s2;
	cout << "Insert string1: ";
	getline(cin, s1);
	cout << "Insert string2: ";
	getline(cin, s2);
	bool result = oneWay(s1, s2);
	cout << result;
	return 0;
}

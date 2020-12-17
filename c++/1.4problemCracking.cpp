#include <iostream>
using namespace std;

bool palindrome(string text){
	int chars[128] = {0};
	int cont = 0;
	for(int i=0; i<text.length(); i++){
		if(text[i]!=32){
			chars[text[i]]+=1;
			cont++;
		}
	}
	if(cont%2==0){
		for(int i=0; i<text.length(); i++){
			if(text[i]!=32){
				int num = chars[text[i]];
				if(num%2!=0){
					return false;
				}
			}
		}
		return true;
	}else{
		int aux = 0;
		for(int i=0; i<text.length(); i++){
			if(text[i]!=32){
				int num = chars[text[i]];
				if(num%2!=0){
					aux++;
				}
			}
		}
		if(aux==1){
			return true;
		}else{
			return false;
		}
	}
	return false;
}

int main(){
	string text;
	cout << "Insert a string: ";
	getline(cin, text);
	cout << palindrome(text);
	return 0;
}
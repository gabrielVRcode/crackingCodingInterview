#include <iostream>
using namespace std;

string urlify(string phrase, int size){
	string result = "";
	for(int i=0; i<size; i++){
		if(phrase[i]!=32){
			result+=phrase[i];
		}else{
			result+="%20";
		}
	}
	return result;
} 

int main(){
	string phrase;
	int size;
	cout << "Insert a phrase: ";
	getline(cin, phrase);
	//cout << size;
	size = 15;
	string result = urlify(phrase, size);
	cout << result;
	return 0;
}
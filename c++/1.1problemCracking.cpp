#include <iostream>
#include <unordered_map>
using namespace std;

bool getUnique(string word){
	unordered_map<char, int> umap;
	for(int i = 0; i<word.length(); i++){
		umap[word[i]]=0;
	}
	for(int i = 0; i<word.length(); i++){
		umap[word[i]]+=1;
		if(umap[word[i]]>1){
			return false;
		}
	}
	return true;
}

int main(){
	string word;
	cout << "Insert a string: ";
	cin >> word;
	bool result = getUnique(word);
	cout << result;
	return 0;
}
#include <iostream>

using namespace std;

bool permutation(string word1, string word2){
	if(word1.length() != word2.length()){
		return false;
	}
	int chars[128] = {0};
	for(int i = 0; i<word1.length(); i++){
		chars[word1[i]]+=1;
	}
	for(int i = 0; i<word2.length(); i++){
		chars[word2[i]]-=1;
		if(chars[word2[i]]<0){
			return false;
		}
	}
	return true;
}

int main(){
	string word1, word2;
	cout << "Insert the first string: ";
	cin >> word1;
	cout << "Insert the second string: ";
	cin >> word2;
	bool result = permutation(word1, word2);
	cout << result;
}
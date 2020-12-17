#include <iostream>
using namespace std;

string compress(string S){
	int array[128]={0};
	string r = "";
	int i = 0;
	char compare = S[0];
	while(i<S.length()){
		char init = S[i];
		if(init==compare){
			array[init]+=1;
		}else{
			r = r+compare+to_string(array[compare]);
			array[compare] = 0;
			array[init]+=1;
			compare = init;
		}
		i++;
	}
	r = r+compare+to_string(array[compare]);
	if(r.length()<=S.length()){
		return r;
	}else{
		return S;
	}
}

int main(){
	string s;
	cout << "Insert a string: ";
	getline(cin, s);
	string result = compress(s);
	cout << result;
	return 0;
}
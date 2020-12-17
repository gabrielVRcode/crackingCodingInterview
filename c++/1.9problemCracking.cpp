#include <iostream>
#include <string>
using namespace std;

int indexof(std::string& text, std::string& pattern)
{
    // where appears the pattern in the text?
    std::string::size_type loc = text.find(pattern, 0);
    if(loc != std::string::npos)
    {
        return loc;
    }
    else
    {
        return -1;
    }
}

int main(){
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string temp = s2+s2;
	if(s1.length() == s2.length() && indexof(temp, s1)>-1){
		cout << "TRUE\n";
	}else{
		cout << "FALSE\n";
	}
	return 0;
}
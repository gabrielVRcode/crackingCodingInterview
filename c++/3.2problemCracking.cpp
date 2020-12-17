#include <iostream>
#include <stack>
#define inf 1000000
using namespace std;

int main(){
	stack<int> s;
	stack<int> smin;
	int a, min=inf;
	cout << "how many data:";
	cin >> a;
	while(a){
		int data;
		cin >> data;
		if(data<=min){ 
			smin.push(data); 
			min = data;
		}else{
			smin.push(min);
		}
		s.push(data);
		a--;
	}
	return 0;
}
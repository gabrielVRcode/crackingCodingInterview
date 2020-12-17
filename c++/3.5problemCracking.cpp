#include <iostream>
#include <stack>
#define MAX 1000
//#include <bits/stdc++.h>
using namespace std;

stack<int> s;

class myStack{
	int top;
	int* arr;
	public:
		myStack(){
			this->top = -1;
			this->arr = new int[MAX];
		}
		bool push(int data);
		int pop();
		int peek();
		bool isEmpty();
		//bool normalPush(int data);
};

/*bool myStack::normalPush(int data){
	if(top>=MAX){
		cout << "Stack overflow" << endl;
		return false;
	}
	arr[++top] = data;
	return true;
}*/

bool myStack::push(int data){
	if(top>=MAX){
		cout << "Stack overflow" << endl;
		return false;
	}
	if(top==-1){
		arr[++top]=data;
		return true;
	}
	//class myStack auxStack;
	while(data>arr[top]){
		s.push(arr[top]);
		top--;
		if(top==-1) break;
	}
	arr[++top]=data;
	while(!s.empty()){
		arr[++top]=s.top();
		s.pop();
	}
	return true;
}

int myStack::pop(){
	if(top<=-1){
		cout << "stack is Empty" << endl;
		return 0;
	}
	int res = arr[top];
	top--;
	return res;
}

int myStack::peek(){
	if(top<=-1){
		cout << "stack is Empty" << endl;
		return -1;
	}
	return arr[top];
}

bool myStack::isEmpty(){
	if(top<=-1){
		return true;
	}
	return false;
}

int main(){
	class myStack stack;
	stack.push(5);
	stack.push(2);
	stack.push(100);
	stack.push(4200);
	stack.push(1);
	cout << stack.pop() << endl;
	return 0;
}
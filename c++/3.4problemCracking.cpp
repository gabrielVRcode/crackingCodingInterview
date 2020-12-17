#include <iostream>

using namespace std;

class myStack{
	int top, capacity;
	int* arr;
	public:
		myStack(int capacity){
			this->capacity = capacity;
			this->arr = new int[capacity];
			this->top = -1;
		}
		bool push(int data);
		int pop();
		int myQueue();
		bool isEmpty();
};

bool myStack::push(int data){
	if(top>=capacity){
		cout << "Stack is full" << endl;
		return false;
	}
	arr[++top] = data;
	return true;
}

int myStack::pop(){
	if(top<=-1){
		cout << "Stack is empty" << endl;
		return 0;
	}
	int r = arr[top];
	top--;
	return r;
}

bool myStack::isEmpty(){
	if(top==-1){
		return true;
	}
	return false;
}

int myStack::myQueue(){
	if(top<=-1){
		cout << "Stack is empty" << endl;
		return 0;
	}
	if(top == 0){
		int r = arr[top];
		top--;
		return r; 
	}
	class myStack auxStack(capacity);
	while(top>0){
		auxStack.push(arr[top]);
		top--;
	}
	int res = arr[top];
	top--;
	while(!auxStack.isEmpty()){
		arr[++top] = auxStack.pop();
	}
	return res;
}

int main(){
	class myStack stack(5);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	//cout << stack.pop() << endl;
	cout << stack.myQueue() << endl;
	cout << stack.myQueue() << endl;
	return 0;
}
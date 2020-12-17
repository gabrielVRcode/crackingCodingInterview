#include <iostream>

using namespace std;

class Node{
	public:
		//int top;
		int* array;
		Node* next;
};

Node* pushList(Node* head, Node* insert){
	Node* node = head;
	if(head == NULL){
		head = insert;
		return head;
	}
	while(node->next!=NULL){
		node = node->next;
	}
	node->next = insert;
	return head;
}

Node* getLastNode(Node* node){
	while(node->next!=NULL){
		node = node->next;
	}
	Node* res = node;
	return res;
}

Node* popNode(Node* head, Node* popnode){
	Node* node = head;
	if(node == popnode){
		return NULL;
	}
	while(node->next!=popnode){
		node = node->next;
	}
	node->next = NULL;
	return head;
}

bool isEmpty(Node* head){
	if(head == NULL){
		return true;
	}
	return false;
}

class setOfStacks{
	int capacity;
	int index;
	int* arr;
	Node* head;
	public:
		setOfStacks(int capacity){
			this->capacity = capacity;
			this->index = -1;
			arr = new int[capacity];
			head = NULL;
		}
		bool push(int data);
		int pop();
		int popAt(int substack);
};

bool setOfStacks::push(int data){
	if(index>=capacity-1){
		Node* node = new Node();
		node->array = arr;
		node->next = NULL;
		head = pushList(head, node);
		arr = new int[capacity];
		index = -1;
		arr[++index]=data;
		cout << "Data pushed in new stack" << endl;
		return true;
	}
	arr[++index]=data;
	cout << "data pushed" << endl;
	return true;
}

int setOfStacks::pop(){
	if(index == -1){
		cout << "Stack is empty" << endl;
		return 0;
	}
	int res = arr[index];
	index--;
	if(!isEmpty(head) && index==-1){
		Node* node = getLastNode(head);
		arr = node->array;
		index = capacity-1;
		head = popNode(head, node);
	}
	return res;
}

int setOfStacks::popAt(int substack){

}

int main(){
	int capacity;
	cin >> capacity;
	class setOfStacks sot(capacity);
	sot.push(1);
	sot.push(2);
	sot.push(3);
	sot.push(4);
	sot.push(5);
	//cout << sot.pop() << endl;
	//cout << sot.pop() << endl;
	//cout << sot.pop() << endl;
	//cout << sot.pop() << endl;
	//cout << sot.pop() << endl;
	return 0;
}
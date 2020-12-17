#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

int kthtolast(int kth, Node* head){
	Node* n = head;
	int cont = 0;
	if(n==NULL) return 0; 
	while(n!=NULL){
		cont++;
		n = n->next;
	}
	n = head;
	while(n!=NULL){
		cont--;
		if(cont==kth){
			return n->data;
		}
		n = n->next;
	}
	return 0;
}

int kthtolastnewV(int kth, Node* head){
	Node* mainpoint = head;
	Node* secpoint = head;
	int cont = -1;
	while(cont!=kth){
		secpoint = secpoint->next;
		cont++;
	}
	while(secpoint!=NULL){
		mainpoint = mainpoint->next;
		secpoint = secpoint->next;
	}
	return mainpoint->data;
}

int main(){
	Node* head=NULL;
	Node* first=NULL;
	Node* second=NULL;
	Node* third=NULL;
	Node* fourth=NULL;
	head = new Node();
	first = new Node();
	second = new Node();
	third = new Node();
	fourth = new Node();
	head->data = 1;
	head->next = first;
	first->data = 2;
	first->next = second;
	second->data = 3;
	second->next = third;
	third->data = 4;
	third->next = fourth;
	fourth->data = 5;
	fourth->next = NULL;
	int kth = 4;
	//int result = kthtolast(kth, head);
	int result = kthtolastnewV(kth, head);
	cout << result;
	return 0;
}
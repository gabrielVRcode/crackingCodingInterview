#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};


void printList(Node* node){
	while(node!=NULL){
		cout << node->data << '\n';
		node = node->next;
	}
}

void partitionList(int value, Node* head){
	Node* node = head;
	Node* newHeadL;
	Node* newHeadR;
	Node* leftside = NULL;
	Node* rightside = NULL;
	while(node!=NULL){
		if(node->data<value){
			Node* n = new Node();
			n->data = node->data;
			n->next = NULL;
			if(leftside == NULL){
				leftside = n;
				newHeadL = leftside;
			}else{
				leftside->next = n;
				leftside = leftside->next;
			}
		}else{
			Node* n = new Node();
			n->data = node->data;
			n->next = NULL;
			if(rightside == NULL){
				rightside = n;
				newHeadR = rightside;
			}else{
				rightside->next = n;
				rightside = rightside->next;
			}
		}
		node = node->next;
	}
	leftside->next = newHeadR;
	printList(newHeadL);
}

int main(){
	Node* head = new Node();
	Node* first = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* fourth = new Node();
	Node* fifth = new Node();
	head->data = 1;
	head->next = first;
	first->data = 4;
	first->next = second;
	second->data = 3;
	second->next = third;
	third->data = 2;
	third->next = fourth;
	fourth->data = 5;
	fourth->next = fifth;
	fifth->data = 2;
	fifth->next = NULL;
	int value;
	cin >> value;
	partitionList(value, head);
}
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

/*void deleteExactMiddle(Node* head){
	Node* mid = head;
	Node* runner = head;
	Node* link = head;
	while(runner!=NULL && runner->next!=NULL){
		mid = mid->next;
		runner = runner->next->next;
	}
	while(link->next!=mid){
		link = link->next;
	}
	link->next = mid->next;
	printList(head);
}*/

void deleteMiddle(Node* node){
	Node* nextNode = node->next;
	while(nextNode->next!=NULL){
		node->data = nextNode->data;
		node = node->next;
		nextNode = nextNode->next; 
	}
	node->data = nextNode->data;
	node->next = NULL;
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
	deleteMiddle(fourth);
	printList(head);
	return 0;
}
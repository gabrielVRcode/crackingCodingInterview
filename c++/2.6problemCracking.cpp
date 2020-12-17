#include <iostream>

using namespace std;

class Node{
	public:
		char data;
		Node* next;
};

bool palindrome(Node* node){
	Node* head = node;
	Node* nextNode = NULL;
	while(node!=NULL){
		Node* newNode = new Node();
		newNode->data = node->data;
		newNode->next = nextNode;
		nextNode = newNode;
		node = node->next;
	}
	while(nextNode!=NULL && head!=NULL){
		if(nextNode->data != head->data){
			return false;
		}
		nextNode = nextNode->next;
		head = head->next;
	}
	return true;
}

void printList(Node* node){
	while(node!=NULL){
		cout << node->data << '\n';
		node = node->next;
	}
}

int main(){
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	head->data = 'o';
	head->next = second;
	second->data = 's';
	second->next = third;
	third->data = 'o';
	third->next = NULL;
	bool result = palindrome(head);
	cout << result << '\n';
	return 0;
}
#include <iostream>
#include <unordered_map>
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

void getUnique(Node* head){
	Node* node1 = head;
	Node* node2 = head->next;
	unordered_map<int, bool> umap;
	umap[node1->data] = true;
	while(node2!=NULL){
		if(umap.find(node2->data) == umap.end()){
			umap[node2->data] = true;
			node1 = node1->next;
		}else{
			node1->next = node2->next;
		}
		node2 = node2->next;
	}
	printList(head);
}

int main(){
	//cout << "hello world linked list! \n";
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;
	Node* fourth = NULL;
	head = new Node();
	second = new Node();
	third = new Node();
	fourth = new Node();
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = fourth;
	fourth->data = 4;
	fourth->next = NULL;
	//printList(head);
	getUnique(head);
	return 0;
}

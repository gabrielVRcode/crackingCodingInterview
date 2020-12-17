#include <iostream>
#include <unordered_map>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* intersection(Node* head1, Node* head2){
	Node* firstlist = head2;
	Node* secondlist = head1;
	unordered_map<Node*, bool> umap;
	while(firstlist!=NULL){
		umap[firstlist]=true;
		firstlist = firstlist->next;
	}
	while(secondlist!=NULL){
		if(umap.find(secondlist) != umap.end()){
			return secondlist;
		}
		secondlist = secondlist->next;
	}
	return NULL;
}

int main(){
	Node* head1 = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* fourth = new Node();
	
	head1->data = 1;
	head1->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = fourth;
	fourth->data = 4;
	fourth->next = NULL;

	Node* head2 = new Node();
	Node* sech = new Node();
	head2->data = 1;
	head2->next = sech;
	sech->data = 2;
	sech->next = third;

	Node* result = intersection(head1, head2);
	cout << result << endl;
	cout << result->data << endl; 
	return 0;
}
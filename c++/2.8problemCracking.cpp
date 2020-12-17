#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
	public:
		char data;
		Node* next;
};

Node* detectLoopList(Node* node){
	Node* onerun = node;
	Node* fastrun = node;
	while((fastrun!=NULL || fastrun->next!=NULL)){
		onerun = onerun->next;
		fastrun = fastrun->next->next;
		if(onerun == fastrun){
			return fastrun;
		}
	}
	return NULL;
}

Node* loopList(Node* node){
	unordered_map<Node*, bool> umap;
	while(node!=NULL){
		if(umap.find(node) == umap.end()){
			umap[node] = true;
		}else{
			return node;
		}
		node = node->next;
	}
	return NULL;
}

int main(){
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* fourth = new Node();
	Node* fifth = new Node();
	head->data = 'a';
	head->next = second;
	second->data = 'b';
	second->next = third;
	third->data = 'c';
	third->next = fourth;
	fourth->data = 'd';
	fourth->next = fifth;
	fifth->data = 'e';
	fifth->next = fourth;
	Node* result = loopList(head);
	cout << result->data << endl;
	return 0;
}
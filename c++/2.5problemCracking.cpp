#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

int getLength(Node* node){
	int cont=0;
	while(node!=NULL){
		cont++;
		node = node->next;
	}
	return cont;
}

void printList(Node* node){
	while(node!=NULL){
		cout << node->data << '\n';
		node = node->next;
	}
}

void sum(Node* head1, Node* head2){
	Node* list1 = head1;
	Node* list2 = head2;
	Node* resultList=NULL;
	Node* newHead;
	int cocient=0;
	while(list1!=NULL || list2!=NULL){
		int a, b;
		if(list1==NULL){ a = 0; }else{ a = list1->data; }
		if(list2==NULL){ b = 0; }else{ b = list2->data; }
		int res = a+b+cocient;
		if(res>=10){
			cocient = 1;
		}else{
			cocient = 0;
		}
		Node* n = new Node();
		n->data = res%10;
		n->next = NULL;
		if(resultList==NULL){
			resultList = n;
			newHead = resultList;
		}else{
			resultList->next = n;
			resultList = resultList->next; 
		}
		if(list1!=NULL) list1=list1->next;
		if(list2!=NULL) list2=list2->next;
	}
	if(cocient==1){
		Node* n = new Node();
		n->data = 1;
		n->next = NULL;
		resultList->next = n;
	}
	printList(newHead);
}

Node* zerosList(Node* node, int lenzeros){
	int i = 0;
	while(i<lenzeros){
		Node* n = new Node();
		n->data = 0;
		n->next = node;
		node = n;
		i++;
	}
	return node;
}

void sumFollowUp(Node* head1, Node* head2){
	Node* list1 = head1;
	Node* list2 = head2;
	int lenlist1 = getLength(list1);
	int lenlist2 = getLength(list2);
	if(lenlist1<lenlist2){
		list1 = zerosList(list1, lenlist2-lenlist1);
	}else if(lenlist2<lenlist1){
		list2 = zerosList(list2, lenlist1-lenlist2);
	}
	Node* resultList=NULL;
	Node* newHead;
	int cocient=0;
	while(list1!=NULL || list2!=NULL){
		int a, b;
		if(list1==NULL){ a = 0; }else{ a = list1->data; }
		if(list2==NULL){ b = 0; }else{ b = list2->data; }
		int res = a+b;
		Node* n = new Node();
		n->next = NULL;
		if(resultList==NULL){
			if(res>=10){
				Node* n1 = new Node();
				Node* n2 = new Node();
				n1->data = 1;
				n1->next = n2;
				n2->data = res%10;
				n2->next = NULL;
				resultList = n2;
				newHead = n1;
			}else{
				n->data = res;
				resultList = n;
				newHead = resultList;
			}
		}else{
			if(res>=10){
				cocient = 1;
			}else{
				cocient = 0;
			}
			n->data = res%10;
			resultList->data = resultList->data+cocient;
			resultList->next = n;
			resultList = resultList->next; 
		}
		if(list1!=NULL) list1=list1->next;
		if(list2!=NULL) list2=list2->next;
	}
	printList(newHead);
}

int main(){
	Node* head1 = new Node();
	Node* h1a = new Node();
	Node* h1b = new Node();
	Node* head2 = new Node();
	Node* h2a = new Node();
	Node* h2b = new Node();
	Node* h2c = new Node();

	head1->data = 9;
	head1->next = h1a;
	h1a->data = 9;
	h1a->next = h1b;
	h1b->data = 9;
	h1b->next = NULL;

	head2->data = 1;
	head2->next = NULL;
	h2a->data = 3;
	h2a->next = h2b;
	h2b->data = 6;
	h2b->next = h2c;
	h2c->data = 7;
	h2c->next = NULL;
	//sum(head1, head2); 
	sumFollowUp(head1, head2);
	return 0;
}
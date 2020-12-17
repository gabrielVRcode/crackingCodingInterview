#include <iostream>

using namespace std;

class Node{
	public:
		char animal;
		Node* next;
};

class shelter{
	Node* head;
	public:
		shelter(){
			this->head=NULL;
		}
		bool queue(char animal);
		char dequeueAny();
		char dequeueCat();
		char dequeueDog();
};

bool shelter::queue(char animal){
	Node* node = new Node();
	node->animal = animal;
	node->next = NULL;
	if(head == NULL){
		head = node;
		return true;
	}
	Node* lastnode = head;
	while(lastnode->next!=NULL){
		lastnode = lastnode->next;
	}
	lastnode->next = node;
	return true;
}

char shelter::dequeueAny(){
	if(head==NULL){
		cout << "Queue is empty ";
		return '0';
	}
	char result = (head)->animal;
	(head) = (head)->next;
	return result;
}

char shelter::dequeueCat(){
	char cat = 'c';
	Node* previous = NULL;
	Node* node = head;
	if(head->animal == cat){
		int result = head->animal;
		head = head->next;
		return result;
	}
	while(node->animal!=cat){
		previous = node;
		node = node->next;
		if(node == NULL){
			cout << "No more cats in the shelter" << endl;
			return '0';
		}
	}
	int result = node->animal;
	previous->next = node->next;
	return result;
}

char shelter::dequeueDog(){
	char dog = 'd';
	Node* previous = NULL;
	Node* node = head;
	if(head->animal == dog){
		int result = head->animal;
		head = head->next;
		return result;
	}
	while(node->animal!=dog){
		previous = node;
		node = node->next;
		if(node == NULL){
			cout << "No more dogs in the shelter" << endl;
			return '0';
		}
	}
	int result = node->animal;
	previous->next = node->next;
	return result;
}

int main(){
	class shelter shel;
	shel.queue('d');
	shel.queue('d');
	shel.queue('c');
	shel.queue('c');
	shel.queue('d');
	shel.queue('d');
	shel.queue('c');
	cout << shel.dequeueDog() << endl;
	cout << shel.dequeueDog() << endl;
	cout << shel.dequeueAny() << endl;
	return 0;
}
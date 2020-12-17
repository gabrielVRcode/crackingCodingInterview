#include <iostream>
#include <stack>
#include <queue>

#define MAX 6
using namespace std;

/*int main(){
	stack<int> s;
	s.push(5);
	//s.push(20);
	//s.pop();
	cout << s.top() << endl;
	cout << s.size() << endl;
	cout << s.empty() << endl;

	cout << "Queues c++" << endl;

	queue<int> q;
	q.push(1);
	q.push(20);
	//q.pop();

	cout << q.size() << endl;
	cout << q.front() << endl;
	cout << q.back() << endl;

	return 0;
}*/

class arrStack{
	const int firstStack = 0;
	const int secondStack = MAX/3;
	const int thirdStack = (MAX/3)*2;

	int index1 = firstStack-1;
	int index2 = secondStack-1;
	int index3 = thirdStack-1;
	public:
		int arr[MAX];
		bool push(int data, int numStack);
		int pop(int numStack);
		bool isEmpty(int numStack);
		int peek(int numStack);
};

bool arrStack::push(int data, int numStack){
	switch(numStack){
		case 1:
			if(index1>=secondStack-1){
				cout << "Stack overflow" << endl;
				return false;
			}
			arr[++index1] = data;
			cout << "pushed data" << endl;
			return true;
		break;
		case 2:
			if(index2>=thirdStack-1){
				cout << "Stack overflow" << endl;
				return false;
			}
			arr[++index2] = data;
			cout << "pushed data" << endl;
			return true;
		break;
		case 3:
			if(index3>=(MAX-1)){
				cout << "Stack overflow" << endl;
				return false;
			}
			arr[++index3] = data;
			cout << "pushed data" << endl;
			return true;
		break;
	}
	return false;
}

int arrStack::pop(int numStack){
	int res;
	switch(numStack){
		case 1:
			if(index1<firstStack){
				cout << "Stack1 is empty" << endl;
				return 0;
			}
			res = arr[index1];
			index1--;
			return res;
		break;
		case 2:
			if(index2<secondStack){
				cout << "Stack2 is empty" << endl;
				return 0;
			}
			res = arr[index2];
			index2--;
			return res;
		break;
		case 3:
			if(index3<thirdStack){
				cout << "Stack3 is empty" << endl;
				return 0;
			}
			res = arr[index3];
			index3--;
			return res;
		break;
	}
	return 0;
}

bool arrStack::isEmpty(int numStack){
	switch(numStack){
		case 1:
			if(index1<firstStack){
				cout << "Stack1 is empty" << endl;
				return true;
			}
			return false;
		break;
		case 2:
			if(index2<secondStack){
				cout << "Stack2 is empty" << endl;
				return true;
			}
			return false;
		break;
		case 3:
			if(index3<thirdStack){
				cout << "Stack3 is empty" << endl;
				return true;
			}
			return false;
		break;
	}
	return false;
}

int arrStack::peek(int numStack){
	switch(numStack){
		case 1:
			if(index1<firstStack){
				return 0;
			}
			return arr[index1];
		break;
		case 2:
			if(index2<secondStack){
				return 0;
			}
			return arr[index2];
		break;
		case 3:
			if(index3<thirdStack){
				return 0;
			}
			return arr[index3];
		break;
	}
	return 0;
}

int main(){
	class arrStack as;
	as.push(1, 1);
	as.push(2, 1);
	as.push(3, 2);
	as.push(4, 2);
	/*cout << as.pop(2) << endl;
	cout << as.pop(2) << endl;
	cout << as.pop(1) << endl;
	cout << as.pop(1) << endl;*/
	as.push(5, 3);
	as.push(6, 3);
	as.push(8, 3);
	cout << as.pop(3) << endl;

	return 0;
}
#include<iostream>
#include<stack>
using namespace std;

class Node {
public:
	int data;
	Node* next ;
	Node* prev ;
	Node(int d = 0) {
		data = d;
		next = 0;
		prev = 0;
		cout << "Const" << endl;
	}
	~Node() {
		cout << "Dest" << endl;
	}
};
int main() {

	Node* start = 0;
	Node* t = 0;
	Node* next;
	Node* prev;

	int datas[] = { 100,200,300 };
	for (int i = 0; i < sizeof(datas) / sizeof(int); i++) {
		int a = (i - 1);
		if (!start) {
			start = new Node(datas[i]);
			t= start;
		}
		else {
			t->next = new Node(datas[i]);
			t->prev = new Node(datas[a]);
			t = t->next;
		}
	}
	Node* n = start;
	while (n) {
		cout << n->data << endl;
		n = n->next;
	}
	cout << "====================" << endl;
	Node* p = t;
	while (p) {
		cout << p->data << endl;
		p = p->prev;
	}

}
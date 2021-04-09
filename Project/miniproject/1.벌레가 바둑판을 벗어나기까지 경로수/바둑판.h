//#include <iostream>
//using namespace std;
//
//struct point {
//	int x;
//	int y;
//};
//typedef struct point POINT;
//
//class Node {
//public:
//
//	POINT pt;
//	Node* next;
//	Node* prev;
//	Node(POINT p) {
//		pt = p;
//		next = 0;
//		prev = 0;
//		cout << "Constructor" << endl;
//	}
//	~Node() { cout << "destructor" << endl; }
//};
//class Stack {
//public:
//	Node* head = 0;
//	Node* tail = 0;
//	Stack() {
//		cout << "Cons" << endl;
//	}
//	~Stack() {
//		cout << "Dest" << endl;
//	}
//public:
//	void Push(POINT pt);
//	int Pop();
//};

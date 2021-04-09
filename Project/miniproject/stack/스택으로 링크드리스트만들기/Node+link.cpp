//#include<iostream>
//#include<stack>
//using namespace std;
//
//class Node {
//public:
//	int data;
//	Node* next = 0;
//	Node* prev = 0;
//	Node(int d = 0) {
//		data = d;
//		cout << "Const" << endl;
//	}
//	~Node(){
//		cout << "Dest" << endl;
//	}
//};
//int main() {
//	
//	Node* start=0;
//	Node* tail = 0;
//
//	int datas[] = {100,200,300};
//	for (int i = 0; i<sizeof(datas) / sizeof(int); i++) {
//		if (!start) {
//			start = new Node(datas[i]);
//			tail = start;
//		}
//		/*else if (i > 0) {
//			t->prev = new Node(datas[i - 1]);
//		}*/
//		else { 
//			Node* n = new Node(datas[i]);
//			tail->next = n;
//			n->prev = tail;
//			tail = n;
//		}
//	}
//	Node* n = start;
//		while (n) {
//			cout << n->data << endl;
//			n = n->next;
//	}
//		cout << "====================" << endl;
//	Node* p = tail;
//	while (p) {
//		cout << p->data << endl;
//		p = p->prev;
//	}
//		
//}
#include<stack>
#include<iostream>
using namespace std;
class A {
public:
	virtual void Print() {
		cout << "A" << endl;;
	}
};
class B : public A {
public:
	void Print() {
		cout << "B" << endl;;//Ŭ���� �ν��Ͻ� ���� ���,Ŭ���� A�� �ν��Ͻ��� �����
	}
};
class C : public B {
public:
	void Print() {
		cout << "C" << endl;;
	}
};
void main() {
	stack<A*>s;
	s.push(new A);
	s.push(new B);
	s.push(new C);
	s.push(new A);

	cout << "size: " << s.size() << endl;
	while (s.size() != 0) {
		A* t = s.top();
		t->Print();
		s.pop();
		delete t;
	}
}


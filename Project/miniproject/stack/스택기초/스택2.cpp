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
		cout << "B" << endl;;//클래스 인스턴스 저장 출력,클래스 A의 인스턴스를 만들고
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


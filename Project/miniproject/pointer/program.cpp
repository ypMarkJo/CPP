#include<iostream>
using namespace std;

class A {
public:
	int data;
	virtual ~A() {
		cout << "destructor.a\n" << endl;
	}
	virtual void Display() { cout << "classA:Display()\n"; }
	void Print() { cout << "class A:Print()\n"; }
	virtual void Show() {};
};
class B :public A {
public:
	int data;
	~B() {
		cout << "destructor.b\n" << endl;
	}
	void Display() { cout << "class B:Display()\n"; }
	void Show() { cout << "class B: Show()\n"; }
};
class C :public B {
public:
	~C() {
		cout << "destructor.c\n" << endl;
	}
	void Show() { cout << "class C: Show()\n"; }
};
int main() {
	A* a = new A;
	A* b = new B;
	A* c = new C;
	

	//A* t = a;
	a = b; 
	b = c; 
	//c = t;
	
		a->Display();
		a->Print();
		a->Show();
	
		b->Display();
		b->Print();
		b->Show();
	
		c->Display();
		c->Print();
		c->Show();
		
		delete a;
		delete b;
		 //delete c;
		
}
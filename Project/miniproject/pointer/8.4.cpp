#include<iostream>
using namespace std;

class A {

	int a1=0;
public:
	A(){}
	virtual void Dynamic()
	{
		cout << "Dynamic A" << endl;
	}
	
	virtual void Static()
	{
		cout << "Static A" << endl;
	}
	
	virtual void Print() {
		cout << a1 << endl;
	}
};

class B :public A {
	int b1;
public:
	B() {};
	virtual void Dynamic()
	{
		cout << "Dynamic B" << endl;
	}
	void Static()
	{
		cout << "Static B" << endl;
	}
};

class C: public B{
	int c1;
public:
	C() {};
	virtual void Dynamic()
	{
		cout << "Dynamic C" << endl;
	}
	void Static()
	{
		cout << "Static C" << endl;
	}
};
void runprint(A*x) {
	x->Dynamic();
	x->Static();
}
int main() {
	A* a; A* b; A* c;
	B d; C e;
	a = new A;
	b = new B;
	c = new C;


	


	e.Print();
	
	a->Dynamic(); a->Static();
	b->Dynamic(); b->Static();
	a = b;
	a->Dynamic(); a->Static();
	c->Dynamic(); c->Static();
	A* mixed[5]; mixed[0] = a; mixed[1] = b; mixed[2] = c;
	for (int I = 0; I < 3; I++)
	{
		runprint(mixed[I]) ;
	}
	delete a;
	delete c;
	return 0;
}

//#include<stack>
//#include<iostream>
//using namespace std;
//class A {
//public:
//	virtual void Print() {
//		cout << "A" << endl;;
//	}
//};
//class B : public A{
//public:
//	void Print() {
//		cout << "B" << endl;;//Ŭ���� �ν��Ͻ� ���� ���,Ŭ���� A�� �ν��Ͻ��� �����
//	}
//};
//class C : public B {
//public:
//	void Print() {
//		cout << "C" << endl;;
//	}
//};
//void main() {
//	
//	stack<A*> s;//A�� �ּҰ��� ���� ������ ���� ���� �θ�� ����
//	s.push(new A);//int t=100+a.push(t)=a.push(100)//����Ǵ°� Ŭ������ �ν��Ͻ��� �ּҰ�
//	s.push(new B);
//	s.push(new C);
//	cout << "size: " << s.size() << endl;//size�� ���ÿ� ���� �� Ȯ��.
//
//	A* t = s.top();
//	t->Print();
//	s.pop();//pop�� ���ÿ� ���� ������ ������
//	delete t;//�޸� �Ҵ� ����
//
//	t = s.top();
//	t->Print();
//	s.pop();
//	delete t;
//
//	t = s.top();
//	t->Print();
//	s.pop();
//	delete t;
//
//}

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
//		cout << "B" << endl;;//클래스 인스턴스 저장 출력,클래스 A의 인스턴스를 만들고
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
//	stack<A*> s;//A의 주소값을 쓰는 이유는 가장 높은 부모기 때문
//	s.push(new A);//int t=100+a.push(t)=a.push(100)//저장되는건 클래스의 인스턴스의 주소값
//	s.push(new B);
//	s.push(new C);
//	cout << "size: " << s.size() << endl;//size는 스택에 쌓인 양 확인.
//
//	A* t = s.top();
//	t->Print();
//	s.pop();//pop은 스택에 쌓인 데이터 꺼내기
//	delete t;//메모리 할당 해제
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

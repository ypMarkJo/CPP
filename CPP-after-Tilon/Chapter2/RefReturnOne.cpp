#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref)
{//1.만약, int RefRetFuncOne(int &ref)면 상수가 반환되므로
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int& num2 = RefRetFuncOne(num1);//2.참조자 선언이 될 수 없다
									//(참조자 선언은 항상 lvalue(not 상수)로
//함수를 빠져나오면서 참조형을 반환했으므로 이후부터는 num1과 num2는 같아진다.
//일어난 상황 정리
//(1) int num1=1;
//(2) int &ref=num1;<-파라미터 전달과정에서 일어난 일.
//(3) int &num2=ref;<-함수의 반환과 반환 값의 저장에서 일어난 일.
	
	num1++;
	num2++;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}

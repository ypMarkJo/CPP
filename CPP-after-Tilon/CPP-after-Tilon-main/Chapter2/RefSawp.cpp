#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int &ref2) {//2.함수 정의부에서 파라미터를 참조자로 받아
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;//3.참조자로 변수의 값을 조작.
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;

	SwapByRef2(val1, val2);//1.변수를 파라미터로 주고

	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;

	return 0;
}

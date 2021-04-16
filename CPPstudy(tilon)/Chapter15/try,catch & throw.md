### 예시

```C++
try{
//예외발생 예상지역
  throw
}catch(처리할 예외의 종류 명시){
//예외처리 코드의 삽입.
}
```
**▲ throw에 의해 던져진 '예외 데이터'는,'예외 데이터'를 감싸는 try블록에 의해서 감지가 되어 이어서 등장하는 catch블록에 의해 처리된다.**
> try와 catch는 항상 같이 오며 중간에 다른 코드가 들어가면 안된다.
```C++
try{
//예외발생 예상지역
}
cout<<"Simple Msg"<<endl;// 컴파일 에러
catch(처리할 예외의 종류 명시){
//예외처리 코드의 삽입.
}
```
**예제 코드**
```C++
#include <iostream>
using namespace std;

int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
			throw num2;//<--1. 예외를 던지고

		cout << "나눗셈의 몫: " << num1 / num2 << endl;//3. 예외가 발생하면 이 부분은 건너뛴다.
		cout << "나눗셈의 나머지: " << num1 % num2 << endl;
	}
	catch (int expn)//<--2. 튀어나온 예외를 캐치해서 다음 코드를 출력시킨다.
	{
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}
	cout << "end of main" << endl;
	return 0;
}
```
> try에서 예외가 발생하면 예외 발생 이후의 try영역은 건너뛴다.

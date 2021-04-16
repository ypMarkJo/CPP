### 모든 예외를 다 받는 ...
```C++
try
{
}
catch(...)//<---...은 모든 예외를 다 받아주겠다는 선언.
{
}
```

### catch에서 throw를 통해 예외를 다시 던질 수도 있다.
> 그러나 예외처리는 간결할수록 좋으므로 rethrow는 지양해야 한다.
>
**예제**
```C++
#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
			throw 0;
		cout << "몫: " << num1 / num2 << endl;
		cout << "나머지: " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "first catch" << endl;
		throw;//함수 정의부에서 예외를 한번 처리하고 다시 호출부로 던진다.
	}
}

int main(void)
{
	try
	{
		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int expn)//호출부에서는 다시 예외를 처리한다.
	{
		cout << "second catch" << endl;// 총 2번의 예외처리가 일어났다.
	}
	return 0;
}

```

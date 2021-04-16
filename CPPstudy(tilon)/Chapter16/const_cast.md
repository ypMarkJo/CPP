> **const는 데이터를 고정시키는 의미를 갖는데 const_cast는 이 의미를 반감시킨다. 따라서 제한적으로만 사용되어야 한다.**

**예제**
```C++
#include <iostream>
using namespace std;

void ShowString(char* str)
{
	cout << str << endl;
}

void ShowAddResult(int& n1, int& n2)//두 메서드 모두(~const 타입)
{
	cout << n1 + n2 << endl;
}

int main(void)
{
	const char* name = "Lee Sung Ju";
	ShowString(const_cast<char*>(name));//<--const_cast를 통해 const를 떼준다.

	const int& num1 = 100;
	const int& num2 = 200;
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));
	return 0;
}
```

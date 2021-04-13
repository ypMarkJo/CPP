### 배열보다 나은 배열 클래스

> int operator[](int idx){...};//임의로 int로 지정.
>
> **arrObject[2]; 다음과 같이 해석가능하다.**
> 
> ```C++
>  arrObject.operator[](2)
> ``` 

### 배열 깊은 복사? Vs. 얕은 복사?

```C++
int main()
{
  BoundCheckIntArray arr(5);
  for(int i=0;i<5;i++) arr[i]=(i+1)*11;
  BoundCheckIntArray cpy1(5) 
  cpy1=arr;//<- 안전하지 않은 코드
  BoundCheckIntArray copy=arr;//<- 역시, 안전하지 않은 코드
}
```
> 위와 같은 코드는 저장소의 일종인 배열의 유일성을 침범한다. 깊은 복사든 얕은 복사든
> 
> 전자의 경우 **불필요하게 동일 데이터 저장소를 복사해 메모리 공간을 차지하는 것이 문제**고
> 
> **얕은 복사는 원본 데이터를 훼손할 우려가 있다.**
> 
> 따라서 아래와 같이 **복사 생성자와 대입 연산자를 private**으로 둠으로써 복사와 대입을 원천적으로 막는 것이 좋다.

```C++
class BoundCheckIntArray
{
private:
  int *arr;
  int arrlen;
  BoundCheckIntArray(const BoundCheckIntArray &arr){};
  BoundCheckIntArray &operator=(const BoundCheckIntArray &arr){};
}
```
### const 함수를 이용한 오버로딩의 활용.
```C++
#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray& arr) { }
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) { }

public:
	BoundCheckIntArray(int len) :arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[] (int idx)//<---------------------------3. const 참조자로는 이 함수를 호출 불가.
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}
	int& operator[] (int idx) const//<-----------------------4. 따라서 const타입 함수를 오버로딩.
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
	
};

void ShowAllData(const BoundCheckIntArray& ref)//<----1.const 타입 참조자 호출
{
	int len = ref.GetArrLen();

	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;//<-----------------------2.참조자의 ref.operator[](idx) 호출
}

int main(void)
{
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;

	ShowAllData(arr);
	return 0;
}

```
> 위와 같이 const의 선언 유무만으로도 오버로딩이 가능. (호출 객체가 const인지의 여부에 구애받지 않음)

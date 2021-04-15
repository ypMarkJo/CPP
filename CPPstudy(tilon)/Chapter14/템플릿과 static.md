## 함수 템플릿과 static 지역변수
> 딱 한번 초기화된 상태에서 그 값을 유지하는 static변수.
> 
![image](https://user-images.githubusercontent.com/80379900/114831319-35888b00-9e08-11eb-8976-888be7970971.png)

> 위와 같이 선언되면 함수 템플릿을 기반으로 컴파일러가 다음과 같은 템플릿 함수를 만들어 낸다.
```C++
void ShowStaticValue<int>(void)
{
  static int num=0;
  num+=1;
  cout<<num<<" ";
}

void ShowStaticValue<long>(void)
{
  static long num=0;
  num+=1;
  cout<<num<<" ";
}
```

>따라서 static 지역변수도 템플릿 함수 별로 각각 존재하게 된다.

**▼ 예제**
```C++
#include <iostream>
using namespace std;

template <typename T>
void ShowStaticValue(void)
{
	static T num=0;
	num+=1;
	cout<<num<<" ";
}

int main(void)
{
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	cout<<endl;

	ShowStaticValue<long>();
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	cout<<endl;

	ShowStaticValue<double>();
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	return 0;
}

```
![image](https://user-images.githubusercontent.com/80379900/114832034-fe66a980-9e08-11eb-8a52-a63ed7ff019d.png)

> 즉, num은 타입별로 누적되며 int 타입의 num과 long타입의 num은 별개의 static변수가 된다.
> 

## 클래스 템플릿과 static 멤버변수

> 마찬가지로 멤버변수에서도 원리는 동일하다.
> 
```C++
#include <iostream>
using namespace std;

template <typename T>
class SimpleStaticMem
{
private:
	static T mem;

public:
	void AddMem(int num) { mem += num; }
	void ShowMem() { cout << mem << endl; }
};

template <typename T>
T SimpleStaticMem<T>::mem = 0;

/*
template<>
long SimpleStaticMem<long>::mem=5;
*/

int main(void)
{
	SimpleStaticMem<int> obj1;
	SimpleStaticMem<int> obj2;
	obj1.AddMem(2);//mem==2
	obj2.AddMem(3);//mem==5<--- 객체가 달라도 동일 자료형의 클래스를 공유하면 static도 공유
	obj1.ShowMem();

	SimpleStaticMem<long> obj3;
	SimpleStaticMem<long> obj4;
	obj3.AddMem(100);//타입이 바꼈기 때문에 mem은 105가 아니라 다시 100이 된다.
	obj4.ShowMem();
	return 0;
}


```

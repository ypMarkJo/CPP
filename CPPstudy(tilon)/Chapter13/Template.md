## 템플릿을 사용하지 않을 때
> 다양한 타입의 매개변수를 받으려면
>
> 아래와 같이 코딩한다.
```C++
#include<iostream>
#include<string>

void Print(int value)
{
	std::cout << value << std::endl;
}
void Print(float value)
{
	std::cout << value << std::endl;
}
void Print(std::string value)
{
	std::cout << value << std::endl;
}
int main() {
	Print(5);
	Print("Hello");
	Print(5.5f);

}
```

## 템플릿을 사용하면
> 아래와 같이 간소화할 수 있다.
```C++
#include<iostream>
#include<string>

template<typename T>//보편적으로 T이나 어떤것이든 가능.
void Print(T value)
{
	std::cout << value << std::endl;
}

int main() {
	Print(5);
	Print("Hello");
	Print(5.5f);

	//템플릿을 쓰면 자료형을 매개변수의 타입에 따라 가변적으로 받지만
	//아래와 같이 자료형을 명시할 수도 있다.

	Print<std::string>("Dog");//<---꺽쇠 <>를 통해 특정하는 **특수화**

}
```

## 템플릿에 클래스를 이용하면

```C++
#include<iostream>
#include<string>

template<typename T,int N>
class Array
{
private:
	T m_Array[N];
public:
	int GetSize()const { return N; }
};
int main() {
	Array<std::string,50>array;
	std::cout << array.GetSize() << std::endl;
}  
```

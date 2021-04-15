### "템플릿 관련 정의에는 template`<typename T>`또는 template<>와 같은 선언을 둬서,템플릿의 일부 또는 전부를 정의하고 있다는 사실을 컴파일러에게 알려야 한다."

- ### template`<typename T>`와 template<>

> 템플릿 클래스의 정의 부분에 T가 존재하면 T에 대한 설명을 위해서 `<typename T>`와 같이 덧붙이고
> 
> T가 존재하지 않으면 <>의 형태로 간단하게 선언하면 된다.

**예시**
```C++
template<typename T>
class SoSimple
{
public:
  T SimpleFunc(T num){....}
}

template<>
class SoSimple<int>
{
public:
  int SimpleFunc(int num){....}
}
```

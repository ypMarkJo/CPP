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

## 템플릿 static 멤버변수 초기화의 특수화

> 기본적으로는 ![image](https://user-images.githubusercontent.com/80379900/114836834-01b06400-9e0e-11eb-82ac-9a4349ef133a.png)와 같이 초기화한다.

> 그러나 <long> 타입의 템플릿 변수에는 다른 초기화값을 넣어주고 싶다면 특수화를 통해 초기화하면 된다.
![image](https://user-images.githubusercontent.com/80379900/114836990-2dcbe500-9e0e-11eb-8afb-3e8fd3b27e0a.png)


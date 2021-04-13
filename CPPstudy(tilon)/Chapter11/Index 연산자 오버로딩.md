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

## 문제의 코드

![image](https://user-images.githubusercontent.com/80379900/115488573-b676d500-a295-11eb-9716-8e92244aabcd.png)

### for문은 범위 지정 반복문( : )을 제외하고 for( ; ; ) 세가지 선언이 필요하다.
- 기초적으로는 for(int i=0[시작점];i<10[조건문 이내에서만 반복];i++[다음 반복문을 돌 때 조건])으로 구성된다.
- 그러나 다른 방식으로는 for(시작점;제한조건;반복조건)으로 이해할 수 있다.<br>


**이해를 돕는 예시코드 ▼**
```C++
#include <iostream>
#include <list>
int main() {
	std::list<int>a;
	a.push_back(5);//현재 헤드의 뒤로 하나씩 삽입
	a.push_back(6);
	a.push_back(7);
	a.push_back(8);
	a.push_back(11);
  //  들어있는 데이터와 순서 5,6,7,8,11
	std::list<int>::iterator iter;//<---반복문을 불러내는 iterator
	for (iter = a.begin(); iter != a.end(); iter++) {
		std::cout << *iter << " ";
	}
}
```
> 이제 코드를 다시보면
> ![image](https://user-images.githubusercontent.com/80379900/115488573-b676d500-a295-11eb-9716-8e92244aabcd.png)
- 첫 시작점은 pLogGroup에 pLogger->ToElement()->FirstChild()을 넣는 것에서 시작해서 pLogGroup안에서만 도는 것으로 제한되며<br>
반복을 거듭할수록 pLogGroup헤더를 다음인자(NextSibling())로 이동시킨다. 다음 인자로 이동하다가 끝에 다다르거나 <br>
pLogGroup을 벗어나는 위치로 헤더가 가면 반복문을 종료한다.

## 추가적으로 범위반복문 설명
![image](https://user-images.githubusercontent.com/80379900/115489682-90523480-a297-11eb-96f4-fd8a909082bb.png)

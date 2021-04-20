![image](https://user-images.githubusercontent.com/80379900/115366708-84fffa00-a200-11eb-8d07-e72ed8be93cb.png)
> #include <stdarg.h>



## 1. va_list
  - 가변 인수들에 대한 정보를 홀드하기 위한 타입이다. 

## 2. va_start
  - va_list를 초기화하는 역할을 하므로 va_list 인스턴스 이후에 등장해야 한다.
  - va_list의 앞부분은 고정인수이므로 va_list의 주소에 고정인수 크기를 더한 위치로 초기화 해야<br>
    진짜 가변인자의 시작점을 알 수 있다. 다음 그림과 같다.
    ![image](https://user-images.githubusercontent.com/80379900/115385613-49226000-a213-11eb-9828-38500a153916.png)
## 3. va_end
 ![image](https://user-images.githubusercontent.com/80379900/115386604-918e4d80-a214-11eb-85be-179ab7c31ac5.png)
 - va_list 인스턴스를 null로 초기화한다. 즉 가변인자 가공을 끝낸다는 뜻.

# vsprintf(윈도우타입) & vsnprintf(리눅스타입)
> 별로 대단한 건 아니고 고정인수를 통한 sprintf를 가변인수를 받는 방식이다.
> 코드상에 snprintf는 위의 함수를 래핑(활용할 수 있는 정의를 추가해 메서드를 저장)을 통해 라이브러리로 만들었다.

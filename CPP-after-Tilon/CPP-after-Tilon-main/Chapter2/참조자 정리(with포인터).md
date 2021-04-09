## 포인터,참조자,그리고 주소값
![image](https://user-images.githubusercontent.com/80379900/113556142-00757f00-9637-11eb-98da-fa783c7916bb.png)

**&ptr을 제외한 다른 것들은 원변수 value의 주소값을 가르치지만 &은 포인터라는 변수의 고유한 주소값을 가르킨다.**

## 참조자의 선언
![image](https://user-images.githubusercontent.com/80379900/113556517-93161e00-9637-11eb-8483-fdde0c942d96.png)

**&연산자는 두가지 기능이 있는데 하나는 이미 선언된 변수나 상수앞에서 그 주소값을 불러오는 연산자이고,
다른 하나는 선언부에 타입과 변수이름 사이에 쓰이며 참조자를 지정할 때 사용된다. 참조자를 지정할 때는 반드시 값을 초기화해야 한다.
단,초기화 값에 상수는 들어올 수 없다.상수는 메모리에 주소를 가질 수 없기 때문이다.**

>lvalue Vs. rvalue
>
>int a(left-value)=100;(right-value)

## const로 선언할 경우
![image](https://user-images.githubusercontent.com/80379900/113557400-ea68be00-9638-11eb-8abd-b0fec79d195c.png)

**참조하려는 값이 const로 선언된 경우, 참조자의 활용에 의해 값이 변경될 수 있으므로 참조 자체를 허용하지 않는다.**

## 함수 Parameter로 값 변경하기
![image](https://user-images.githubusercontent.com/80379900/113562598-5a7b4200-9641-11eb-9aec-76719f458ca3.png)
![image](https://user-images.githubusercontent.com/80379900/113562663-7848a700-9641-11eb-9bd2-bf4bd354e946.png)
>참조자와 포인터가 비슷한 특성을 보이는 이유는 참조자도 내부적으로는 포인터로 코딩되어 있기 때문이다.

## 참조자로 함수 Parameter에 배열 받기.
![image](https://user-images.githubusercontent.com/80379900/113563477-babeb380-9642-11eb-896d-464cf0019644.png)

## 원하는 변수로 접근하기 위해서 구조체를 거치는 등 많은 타이핑이 필요할 때 참조변수를 지정해 간략화 가능.
![image](https://user-images.githubusercontent.com/80379900/113563864-67993080-9643-11eb-8c4c-175746663f76.png)

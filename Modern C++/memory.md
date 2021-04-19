## 메모리가 쌓이는 방식.
![image](https://user-images.githubusercontent.com/80379900/115171839-e9d32b80-a0fe-11eb-9709-9f3faaaf2e26.png)![image](https://user-images.githubusercontent.com/80379900/115171730-ac6e9e00-a0fe-11eb-9851-1074d9897943.png)

>주소가 먼저 선언된 것 위로 쌓이면서 메모리를 차지한다.
>
## 변수 타입 in 메모리
![image](https://user-images.githubusercontent.com/80379900/115172244-d2487280-a0ff-11eb-976e-864d1e920f2b.png)
>일반적으로 우리는 int는 4바이트,long은 8바이트,실수를 표현하기 위해 float과 double이 각각 4와 8바이트를 차지한다고 알고있다.
>
>그러나 컴파일러에 따라 다른 경우도 있는데 우리는 이 차이를 막기위해 static_assert라는 장치를 쓸 수 있다.
>
>원하는 조건을 명시하고 컴파일하면 조건이 충족되지 않을 때 메시지를 띄우며 컴파일에 에러를 만든다.

## 정확한 메모리 레이아웃이 필요한 경우
![image](https://user-images.githubusercontent.com/80379900/115172790-f3f62980-a100-11eb-98ee-2dd78c65f449.png)
>int8_t,int32_t,uint_32t와 같이 정확한 바이트 단위를 이용하는 인트 타입을 이용해 메모리를 관리한다.

## 배열을 통한 메모리 사이즈 확인
![image](https://user-images.githubusercontent.com/80379900/115173383-26545680-a102-11eb-964d-2cc2f2ef5a6f.png)
![image](https://user-images.githubusercontent.com/80379900/115174474-42f18e00-a104-11eb-91e0-6454458130b2.png)

## 구조체를 통한 메모리 사이즈 확인
![image](https://user-images.githubusercontent.com/80379900/115175059-4f2a1b00-a105-11eb-943c-9eec3f7b14ad.png)
> 14가 되어야 하지만 컴파일러가 메모리를 관리해주는 모습이다.


## const를 사용할 때는 상수화하는 것이기 때문에 반드시 초기화를 해줘야한다.
--------------------------------------------------------------------------


## case1 : 변수를 상수화 할 때
![image](https://user-images.githubusercontent.com/80379900/113550056-66f59f80-962d-11eb-96ec-0d07d731491b.png)

**원 변수 value를 const를 이용해서 상수화하면 변수였던 상수의 주소 뿐만 아니라 값도 변경이 불가.**

## case2: 포인터만 상수화 할 때
![image](https://user-images.githubusercontent.com/80379900/113550549-319d8180-962e-11eb-9fe0-13314b89e83d.png)

## case3: 변수가 두가지인 경우
![image](https://user-images.githubusercontent.com/80379900/113550934-d61fc380-962e-11eb-9978-043f45c3aabf.png)

**역참조를 통해 원변수 주소의 값을 변경하는 것은 불가능하지만 주소값 자체를 바꾸는 건 가능하다는 의미.**

## case4: int* const pointer 형식으로 포인터 자체의 주소값을 고정시키는 경우
![image](https://user-images.githubusercontent.com/80379900/113551531-c654af00-962f-11eb-8658-088cc66cb09e.png)

**단, 주소값만 고정이고 주소값의 값은 변경이 가능하다.**

## case5: const int* const pointer 형식
![image](https://user-images.githubusercontent.com/80379900/113554234-f736e300-9633-11eb-8bae-2cba96517ef8.png)

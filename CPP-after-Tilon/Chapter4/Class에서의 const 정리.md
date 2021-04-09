## const 함수
>int GetX() const
>
>void Show() const

**"이 함수 내에서는  멤버변수에 저장된 값을 변경하지 않겠다."**
- 매개변수도 지역변수도 아닌 멤버변수의 값을 고정하는 선언이다.

![image](https://user-images.githubusercontent.com/80379900/113796926-3c215d80-978b-11eb-8596-9e3b54ed211b.png)

**▲ const 함수 내에서는 const가 아닌 함수의 호출이 제한된다.**

![image](https://user-images.githubusercontent.com/80379900/113797633-9a027500-978c-11eb-83ff-bf296f843b64.png)

**▲ const 참조자는 const함수만 호출이 가능하다. 아니면 값을 변경할 여지가 생기기 때문이다.(실제로 바뀌는지 여부 X)**

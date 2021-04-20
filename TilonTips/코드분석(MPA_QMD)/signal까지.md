## 리눅스에서 경로 복사.
![image](https://user-images.githubusercontent.com/80379900/115230833-d56b4f00-a14f-11eb-82f7-3be05142a44e.png)

## int main(void) --> int main(int argc,char*argv[])로의 변화
![image](https://user-images.githubusercontent.com/80379900/115231145-2f6c1480-a150-11eb-9f91-d73bcc09c570.png)

## STL_Map에서 find() -> end()

```C++
if( g_mapOpt.find( "--help" ) != g_mapOpt.end() )
	{
		_help();
	}//<-----------키 값중 "--help"를 찾는다면 map.find(아무개) ==map.end(): 아무개 키를 못찾았다.
```

## fork()를 통한 자식 프로세스 생성.
>똑같은 프로세스가 두개가 만들어진다.
>
>따라서, 부모 프로세스와 자식프로세스 상에서 다른 작업을 수행하게 할 수 있다.
>
>그러나 현재의 프로세스 복제모델의 한계는 부모와 자식이 동일한 코드를 가지게 되므로 수행하지 않을 작업의 코드까지 가지고 있어야 한다는 한계가 있다.
```C++
int main(){
pid=fork()//<---부모프로세스에서 fork()를 통해 return값을 pid에 전달하면 자식 프로세스 ID(pid)가 입력된다.
          // 자식프로세스의 경우 fork()를 통해 0을 pid에 넣게된다.
if(pid!=0) exit(0);
else if(pid!=0) exit(0);
 
return 0;
}
```
![image](https://user-images.githubusercontent.com/80379900/115319515-f1580a80-a1ba-11eb-878b-241d4ab9e259.png)

## Signal

> ### 정의: 프로세스에 뭔가 발생했음을 알리는 간단한 메시지를 비동기적으로 보내는 것.
> 이 메시지는 미리 정의된 상수를 통해 시그널의 종류를 구분한다.

### 시그널이 발생하는 경우
![image](https://user-images.githubusercontent.com/80379900/115355672-da82d980-a1f5-11eb-92fd-2f9cb0c54143.png)

### 시그널의 처리
- 대부분의 시그널에 대한 기본 동작은 프로세스를 종료하는 것이나 추가적으로 <br>시그널을 무시하거나 일시정지,재시작 등의 동작을 수행하기도 한다.<br>
- 프로세스는 시그널의 처리를 위해 미리 함수를 지정해놓고 시그널을 받으면 해당 함수를 호출해 처리한다.<br> 
- 시그널 처리를 위해 지정하는 함수를 ***시그널 핸들러*** 라고 한다. 시그널을 받으면 기존 처리 작업을 중지한 후<br> 시그널 핸들러를 호출하며,시그널 핸들러의 동작이 완료되면 기존 처리 작업을 계속 수행한다.
- 프로세스는 특정 부분이 실행되는 동안 시그널이 발생하지 않도록 블록할 수 있다.<br>블록된 시그널은 큐에 쌓여 있다가 시그널 블록이 해제되면 전달된다.

![image](https://user-images.githubusercontent.com/80379900/115358695-e15f1b80-a1f8-11eb-91cf-f0077c5a2aaa.png)
![image](https://user-images.githubusercontent.com/80379900/115358797-fd62bd00-a1f8-11eb-9d34-d6ac384017bb.png)
![image](https://user-images.githubusercontent.com/80379900/115359931-1b7ced00-a1fa-11eb-9852-5d9689ff42ed.png)
![image](https://user-images.githubusercontent.com/80379900/115360702-d7d6b300-a1fa-11eb-910f-f49554e3161c.png)
![image](https://user-images.githubusercontent.com/80379900/115360868-fe94e980-a1fa-11eb-8c5e-dc828dd6870d.png)
![image](https://user-images.githubusercontent.com/80379900/115363466-7532e680-a1fd-11eb-9643-130d011f2c73.png)
![image](https://user-images.githubusercontent.com/80379900/115364971-e626ce00-a1fe-11eb-9b11-5cc4289c06af.png)
> signal(시그널 상수신호,핸들러 함수 포인터) -> 핸들러 구현시 void func(int 상수신호) 로 구현해야함.<-signal 함수의 정의.

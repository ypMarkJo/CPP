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

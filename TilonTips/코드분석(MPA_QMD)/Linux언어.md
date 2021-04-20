## echo: 시스템의 환경 변수 또는 입력 내용을 화면에 출력한다.<br> system(): 시스템에 명령을 전달하는 함수.
```C++
snprintf_safe( szShutdown, 512, "echo 'kill -SIGUSR1 %d' > %s/shutdown.sh", g_PID, g_strModulePath.c_str() );
	system( szShutdown );
```
```C++
snprintf_safe( szShutdown, 512, "chmod +x %s/shutdown.sh", g_strModulePath.c_str() );
       system( szShutdown );
```

## 권한 임계 설정.
+x 는 실행권한을 준다.(r은 읽기, w는 쓰기)<br>
순서는 사용자-그룹-다른 모든이
rwx(읽기,쓰기,실행)-> 바이너리로 111-> 7
rx->101->5
r->100->4<br>
- 예시:<br> 
    777-> 모든 사용자,그룹,타인 들이 전부 읽기 쓰기 실행이 가능하다.(111-111-111)<br>  
    711-> 사용자만 전부 가능하고 나머지 그룹과 타인은 실행만 가능하다(111-001-001)

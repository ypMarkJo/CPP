![image](https://user-images.githubusercontent.com/80379900/118059619-ed8b6280-b3cb-11eb-8507-6d6f3e38d96b.png)<br>
![image](https://user-images.githubusercontent.com/80379900/118059635-f54b0700-b3cb-11eb-8c9f-bbf002453d87.png)<br>
<br>
>**위의 두 코드는 항상 CURL작업을 시작하기 전과 후에 같이 나와야 한다. 밑의 클린업을 해주지 않으면 리소스 문제가 발생할 수 있다.<br>
또한 easy init에 앞서 curl_global_init()을 수동적으로 해주지 않으면 curl_easy_init()이 등장할 때 마다** <br>
![image](https://user-images.githubusercontent.com/80379900/118060188-21b35300-b3cd-11eb-814f-1e753c3ab940.png)

>**자동적으로 전자의 함수를 실행시키는데 이는 어디까지가 cleanup이 되는지 추적할 수 없으므로<br> 리소스 문제가 발생하며 반드시 수동적으로 위의 두 함수에 앞서 curl_global_init()을
실행해줘야 한다.**

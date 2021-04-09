![image](https://user-images.githubusercontent.com/80379900/113981150-48d4ad00-9882-11eb-999c-3dfb2b712131.png)
> 상속 시에는 private은 멤버로 직접 가져올 수 없고 private상속에는 기초클래스의 public,protected를 private으로 가져오고
>
> protecte상속에는 public을 protected로 가져온다 즉, **public > protected > private** 순서로 좁아지는데 좁은 기준으로 가져온다.
> 
> 만약, protected상속을 했는데 유도클래스에서 **가장 넓은 범위멤버가 private이면 private으로** 상속.
> 
> ### 그러나 이걸 다 생각하기는 어려우므로 가장 많이 쓰이는 경우인 public상속만 기억해두자.

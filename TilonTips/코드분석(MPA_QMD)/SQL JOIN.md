## 모든 테이블은 하나의 주제만 가져야 한다.
> 주제만 가지는 테이블들이 관계형 DB로 구성하는데 필요한 것이 바로 JOIN이다.
> ![image](https://user-images.githubusercontent.com/80379900/116193044-b11ffb80-a769-11eb-8ca6-2adc969092d1.png)
### 한 군데 모은 TABLE
> 위의 topic과 같이 데이터를 모아서 한테이블로 만들면 쓰기(수정)을 위해서는 모두 바꿔야하는데 읽기가 빨라진다.<br>
### 주제별로 분리한 TABLE
> 밑의 topic과 같이 데이터를 주제별 테이블로 분리하면 예를 들어 author의 데이터가 1억라고 할 때 topic테이블에서<br>
> author_id로 데이터를 조회할 때마다 1억건을 돌아야 하므로 읽기가 느려지지만 쓰기(수정)이 간편하다. <br>

**-> 이러한 두 형태의 테이블 가지는 장점을 모두 활용하고 단점을 상쇄하는 방법이 바로 JOIN이다.**<br><br>

## 1.LEFT JOIN( or RIGHT JOIN): RIGHT는 설명 반대로
> A LEFT JOIN B ON (조건) : A와 B에서 공통으로 조건을 만족하는 정보+A에만 있는 정보로 테이블 구성.<br>
![image](https://user-images.githubusercontent.com/80379900/116198248-afa60180-a770-11eb-9cba-a87cdfb22025.png)

## 2.INNER JOIN
> A INNER JOIN B on (조건): A와 B에서 공통으로 조건을 만족하는 정보로 테이블 구성.<br>
![image](https://user-images.githubusercontent.com/80379900/116198215-a74dc680-a770-11eb-87b8-bc9e34aedcaa.png)

## 3.FULL OUTER JOIN (잘 안씀)
> 대부분의 DB시스템이 FULL OUTER JOIN을 지원하지 않는다.<br>
> 그러나 아래와 같이 UNION이라는 집합명령어를 이용해 구현할 수 있다.<br>(DISTINCT는 중복제거-> 생략하고 UNION만 적으면 default로 포함)

![image](https://user-images.githubusercontent.com/80379900/116201956-07466c00-a775-11eb-9174-0c0f73c1d871.png)
![image](https://user-images.githubusercontent.com/80379900/116202100-2e9d3900-a775-11eb-9d4d-49a2ce26cf52.png)


**기초클래스의 객체라도 유도클래스의 포인터,참조자 기능을 수행하도록 억지로 선언한다.(컴파일 오류를 띄우지 않는다.)**

```C++
#include <iostream>
using namespace std;

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{  }
	void ShowCarState()
	{
		cout << "잔여 연료량: " << fuelGauge << endl;
	}
};

class Truck : public Car
{
private:
	int freightWeight;

public:
	Truck(int fuel, int weight)
		: Car(fuel), freightWeight(weight)
	{  }
	void ShowTruckState()
	{
		ShowCarState();
		cout << "화물의 무게: " << freightWeight << endl;
	}
};

int main(void)
{
	Car* pcar1 = new Truck(80, 200);
	Truck* ptruck1 = static_cast<Truck*>(pcar1);     // 컴파일 OK!-> 실제 담고있는 데이터가 트럭객체라 문제없다.
	ptruck1->ShowTruckState();
	cout << endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2);     // 컴파일 OK! 그러나! 카의 객체는 트럭이 될 수 없다.
	ptruck2->ShowTruckState();
	return 0;
}
```

> **static_cast 연산자는 dynamic_cast 연산자와 달리, 보다 많은 형 변환을 허용합니다. 하지만 그에 따른 책임도 개발자가 져야 하기 때문에 신중하게 선택해야 합니다.**

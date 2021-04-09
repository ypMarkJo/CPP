//5장-2.DATE1.CPP
//새로운 함수를 가진 class Date에 대한 test program
#include<iostream>
#include"Header.h"

int main() {
	//객체 newYearDay를 정의하고 객체에 대한 다른 연산을 수행
	Date newYearsDay(1, 1, 2017); //데이터는 선언된 범위 안에서만 의미가 있다.
		 // ^ 오브젝트,인스턴스,객체,main함수를 벗어나면 사라지는 데이터.
	newYearsDay.PrintDate();
	//변수가 가리키는 객체의 내부 데이터가 변경됨
	newYearsDay.IncreaseDate();
	newYearsDay.PrintDate();
	newYearsDay.PrintLeap();
	//Date class의 객체 d를 생성하고 다른 연산을 수행
	Date d(5, 15, 2016);
	d.IncreaseDate();
	d.PrintDate();
	d.PrintLeap();
	//주어진 날짜부터 증가시켜 print한다

	for (Date dd(2, 25, 2017); dd.Day() < 3 || dd.Day() > 10; dd.IncreaseDate())
		dd.PrintDate();
	system("pause");
}

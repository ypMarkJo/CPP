
#include<iostream>
using namespace std;
class Date {
public:
	//private data: 
	int month;
	int day;
	int year;

public://->누구나 불러올 수 있다.만약 private또는 no선언이면 돼있으면 접근 불가
	//선언할 때마다 스위칭이 됨. 공개할 부분은 public:, 비공개는 private:
	Date(int m, int d, int y);
	~Date();
	int Month();
	int Day();
	int Year();

	int LeapYear();

	int DaysInMonth();
	void IncreaseDate();

	void PrintDate();
	void PrintLeap();

};

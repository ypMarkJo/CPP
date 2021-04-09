
//5장 -1. DATE1.H
//class Date의 두번째 정의
//새로운 함수가 포함됨.
#include"Hell.h"



Date::Date(int m, int d, int y) :month(m), day(d), year(y) {
		if (month == 2 && day == 29) cout << "incorrect date" << endl;
		cout << "Construct" << endl;
	}
Date::~Date() {
		cout << "Destruct" << endl;
	}
	int Date::Month() {
		return month;
	}
	int Date::Day() {
		return day;
	}
	int Date::Year() {
		return year;
	}
	//윤년인 경우에 1(TRUE)을 return
	//윤년이 아닌 경우에는 0(FALSE)을 return
	//int Bool을 나타냄
	int Date::LeapYear() {
		if (year % 4 != 0)return 0;
		else {
			if (year % 100 != 0)return 1;
			else if (year % 400 != 0)return 0;
			else return 1;
		}
	};
	//실제 월의 날짜 수를 return한다
	int Date::DaysInMonth() {
		switch (month) {
		case 2:
			if (LeapYear())return 29;
			else return 28;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		default:
			return 31;
		}
	}
	//날짜를 하루 증가시킨다.
	void Date::IncreaseDate() {
		if (day < DaysInMonth())day++;
		else {
			day = 1;
			if (month != 12)month++;
			else {
				month = 1;
				year++;
			}
		}
	}
	//날짜를 출력한다
	void Date::PrintDate() {
		cout << endl << "Date:" << month << "/" << day
			<< "/" << year << endl;
	}
	//연도가 윤년인지 아닌지를 가리키는 문구를 출력한다.
	void Date::PrintLeap() {
		cout << endl << "The year" << year;
		if (LeapYear()) cout << "is a leap-year";
		else cout << "is not a leap-year";
	}
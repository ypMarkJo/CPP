
//5�� -1. DATE1.H
//class Date�� �ι�° ����
//���ο� �Լ��� ���Ե�.
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
	//������ ��쿡 1(TRUE)�� return
	//������ �ƴ� ��쿡�� 0(FALSE)�� return
	//int Bool�� ��Ÿ��
	int Date::LeapYear() {
		if (year % 4 != 0)return 0;
		else {
			if (year % 100 != 0)return 1;
			else if (year % 400 != 0)return 0;
			else return 1;
		}
	};
	//���� ���� ��¥ ���� return�Ѵ�
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
	//��¥�� �Ϸ� ������Ų��.
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
	//��¥�� ����Ѵ�
	void Date::PrintDate() {
		cout << endl << "Date:" << month << "/" << day
			<< "/" << year << endl;
	}
	//������ �������� �ƴ����� ����Ű�� ������ ����Ѵ�.
	void Date::PrintLeap() {
		cout << endl << "The year" << year;
		if (LeapYear()) cout << "is a leap-year";
		else cout << "is not a leap-year";
	}

#include<iostream>
using namespace std;
class Date {
public:
	//private data: 
	int month;
	int day;
	int year;

public://->������ �ҷ��� �� �ִ�.���� private�Ǵ� no�����̸� �������� ���� �Ұ�
	//������ ������ ����Ī�� ��. ������ �κ��� public:, ������� private:
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

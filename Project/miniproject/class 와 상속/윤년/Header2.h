//5��-2.DATE1.CPP
//���ο� �Լ��� ���� class Date�� ���� test program
#include<iostream>
#include"Header.h"

int main() {
	//��ü newYearDay�� �����ϰ� ��ü�� ���� �ٸ� ������ ����
	Date newYearsDay(1, 1, 2017); //�����ʹ� ����� ���� �ȿ����� �ǹ̰� �ִ�.
		 // ^ ������Ʈ,�ν��Ͻ�,��ü,main�Լ��� ����� ������� ������.
	newYearsDay.PrintDate();
	//������ ����Ű�� ��ü�� ���� �����Ͱ� �����
	newYearsDay.IncreaseDate();
	newYearsDay.PrintDate();
	newYearsDay.PrintLeap();
	//Date class�� ��ü d�� �����ϰ� �ٸ� ������ ����
	Date d(5, 15, 2016);
	d.IncreaseDate();
	d.PrintDate();
	d.PrintLeap();
	//�־��� ��¥���� �������� print�Ѵ�

	for (Date dd(2, 25, 2017); dd.Day() < 3 || dd.Day() > 10; dd.IncreaseDate())
		dd.PrintDate();
	system("pause");
}

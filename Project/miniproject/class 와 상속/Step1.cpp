#include "Student.h"
#include <iostream>
using namespace std;
student::student(string _name,int _ID, int _grade)
{
	setData(_name,_ID,_grade);
	major = "";
	sex = "";
	 birth=0;
}
void student::setData(string _name, int _ID, int _grade)
{
	name = _name;
	ID = _ID;
	grade = _grade;
}
string student::getName()
{
	return name;
}
string student::getmajor()
{
	return major;
}
string student::getsex()
{
	return sex;
}
int student::getID()
{
	return ID;
}
int student::getbirth()
{
	return birth;
}
int student::getgrade()
{
	return grade;
}
void student::show()
{
	cout << "-----------------------------" << endl;
	cout << "�̸�: " << getName() << endl;
	//cout << "����: " << getmajor() << endl;
	//cout << "����: " << getsex() << endl;
	cout << "�й�: " << getID() << endl;
	//cout << "����: " << getbirth() << endl;
	cout << "����: " << getgrade() << endl;
	cout<<"-----------------------------"<<endl;
}

//int main() {
//	
//	student* s = new student("ȫ�浿", "�濵�а�", "����", 202020020, 19940720, 4);
//	s->show();
//	delete s;
//	student* s2 = new student;
//	s2->setData("������", "����ö�а�", "����", 200451142, 19870404, 1);
//	s2->show();
//	delete s2;
//	
//}
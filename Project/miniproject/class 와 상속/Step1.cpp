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
	cout << "이름: " << getName() << endl;
	//cout << "전공: " << getmajor() << endl;
	//cout << "성별: " << getsex() << endl;
	cout << "학번: " << getID() << endl;
	//cout << "생년: " << getbirth() << endl;
	cout << "점수: " << getgrade() << endl;
	cout<<"-----------------------------"<<endl;
}

//int main() {
//	
//	student* s = new student("홍길동", "경영학과", "남자", 202020020, 19940720, 4);
//	s->show();
//	delete s;
//	student* s2 = new student;
//	s2->setData("김팔출", "동양철학과", "여자", 200451142, 19870404, 1);
//	s2->show();
//	delete s2;
//	
//}
#include"st.h"

student::student(string n, int i, string m, int s)
{
	cout << "Construct" << endl;
	this->name = n;
	//this->studentID = studentID;
	this->major = m;
	this->semester = s;
	studentID = new int;//heap에 메모리 강제 할당
	*studentID = i;
}
student::~student()
{
	delete studentID;//메모리 해제:안해주면 메모리가 가득 차게 됨.(new->delete)(malloc->free)(fopen->fclose)
	cout << "Destruct" << endl;
}
void student::Setname(string n)
{
	name = n;
}
void student::SetID(int i)
{
	*studentID = i;
}
void student::Setmajor(string m)
{
	major = m;
}
void student::Setsemester(int s)
{
	semester = s;
}
void student::Print()
{
	cout << "===============PNU=================" << endl;
	cout << "이름:" << name << endl;
	cout << "학번:" << *studentID << endl;
	cout << "전공:" << major << endl;
	cout << "학기:" << semester << endl;
	cout << "===================================" << endl;
}

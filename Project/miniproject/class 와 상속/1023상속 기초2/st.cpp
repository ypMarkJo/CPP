#include"st.h"

student::student(string n, int i, string m, int s)
{
	cout << "Construct" << endl;
	this->name = n;
	//this->studentID = studentID;
	this->major = m;
	this->semester = s;
	studentID = new int;//heap�� �޸� ���� �Ҵ�
	*studentID = i;
}
student::~student()
{
	delete studentID;//�޸� ����:�����ָ� �޸𸮰� ���� ���� ��.(new->delete)(malloc->free)(fopen->fclose)
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
	cout << "�̸�:" << name << endl;
	cout << "�й�:" << *studentID << endl;
	cout << "����:" << major << endl;
	cout << "�б�:" << semester << endl;
	cout << "===================================" << endl;
}

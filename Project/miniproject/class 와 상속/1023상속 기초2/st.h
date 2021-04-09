#include<iostream>
#include<string>

using namespace std;
class student
{
	//name 이름
	//studentID 학번
	//major 전공
	//semester 몇학기
	string name;
	int *studentID;
	string major;
	int semester;
public:
	student(string name = "", int studentID = 0, string major = "", int semester = 0);
	~student();

	void Setname(string n);
	void SetID(int i);
	void Setmajor(string m);
	void Setsemester(int s);
	void Print();
};

#include <iostream>
using namespace std;

class student
{
private:
	string name, major, sex;
	int ID, birth, grade;
public:

	student(string _name = "", string _major = "", string _sex = "", int _ID = 0, int _birth = 0, int _grade = 0)
	{
		name = _name;
		major = _major;
		sex = _sex;
		ID = _ID;
		birth = _birth;
		grade = _grade;
		cout << "cons" << endl;
	}
	student(string _name, int _ID, int _grade) ;
	~student() { /*cout << "des" << endl; */}

	void setData(string _name, int _ID, int _grade);
	string getName();
	string getmajor();
	string getsex();
	int getID();
	int getbirth();
	int getgrade();
	void show();
};

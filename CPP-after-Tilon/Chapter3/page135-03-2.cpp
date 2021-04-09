#include<iostream>
using namespace std;

class Printer {
	char str[30];
public:
	Printer() {};
	~Printer() {};
	void SetString(const char str[]) {
		strcpy(this->str, str);
	}
	void ShowString() {
		cout << str << endl;
	}
};
void main() {
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();
	pnt.SetString("I can do C++");
	pnt.ShowString();

}

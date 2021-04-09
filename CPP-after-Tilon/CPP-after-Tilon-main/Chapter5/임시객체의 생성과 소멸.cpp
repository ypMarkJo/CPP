#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);//참조값이 반환된다.(임시객체의 참조값)
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);
	// 임시객체의 규칙
	// 1.임시객체는 다음행으로 넘어가면 사라진다.
	// 2.참조자를 선언하여 임시객체를 참조해주면 바로 소멸하지 않는다.
	//   (main함수가 return으로 빠져나오면 소멸)
	cout << "********** end of main!" << endl << endl;
	return 0;
}

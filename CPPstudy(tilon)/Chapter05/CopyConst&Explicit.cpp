#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{
		// empty
	}

	explicit SoSimple(SoSimple& copy)//1.일반적으로 디폴트 값으로 복사생성자를 가지기 때문에 '='연산자만으로 복사 생성이 가능하다.
                                   //  그러나 explicit(명시)를 통해 복사생성자를 만들어주면 더이상 '='대입으로는 불가하다.
		: num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(SoSimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2(sim1);// 2.명시가 된 경우에는 이 형태만이 복사가 가능하다. 이외에는 SoSimple sim2=sim1(묵시적 변환);으로 가능.
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();
	return 0;
}

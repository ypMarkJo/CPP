#include <iostream>
using namespace std;

void Counter()
{
	static int cnt;//cnt는 전역변수로 선언되어 초기값은 0이 되고,
	//				 단 한번만 선언된다. 즉, Counter()를 들어올 때마다 새로 선언되는 게 아니다.
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		Counter();
	return 0;
}

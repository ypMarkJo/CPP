// Friend 선언은 private 멤버의 접근을 허용한다.
// Friend 선언은 객체지향의 장점인 정보은닉과 상충한다.
// 따라서 최소한의 선에서 사용해야한다.

#include <iostream>
#include <cstring>
using namespace std;

class Girl;// 1.함수 선언부 처럼 미리 클래스라는 걸 선언
//4.friend선언은 클래스 선언의 역할도 하므로 위 코드는 생략이 가능하다.
class Boy
{
private:
	int height;
	friend class Girl;//3.friend선언은 private,public어디에나 가능.
public:
	Boy(int len) : height(len)
	{ }
	void ShowYourFriendInfo(Girl& frn);// 2.정의되지 않았어도 선언했기에 Girl사용가능.
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn)
{
	cout << "His height: " << frn.height << endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}

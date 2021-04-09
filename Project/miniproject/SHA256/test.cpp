#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SHA256.h"

using namespace std;

int main()
{
	const char* data = "Jo Youngpyeong";
	char s[32] = "";
	int nounce = 0;
	while (1)
	{
		sprintf(s, "%s%d", data, nounce);
		//data를 sha256 알고리즘으로 해싱한다.
		string str = sha256(s);
		//해싱한 데이터를 화면에 출력
		printf("%10d: %s\r", nounce, str.c_str());
		//해싱한 코드에서 앞 4글자가 '0000'인지 확인
		string t = str.substr(0, 6);
		if (t== "000000") break;
		nounce++;
		
	}
	return 1;
}
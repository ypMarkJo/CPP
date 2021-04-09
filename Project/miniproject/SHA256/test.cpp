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
		//data�� sha256 �˰������� �ؽ��Ѵ�.
		string str = sha256(s);
		//�ؽ��� �����͸� ȭ�鿡 ���
		printf("%10d: %s\r", nounce, str.c_str());
		//�ؽ��� �ڵ忡�� �� 4���ڰ� '0000'���� Ȯ��
		string t = str.substr(0, 6);
		if (t== "000000") break;
		nounce++;
		
	}
	return 1;
}
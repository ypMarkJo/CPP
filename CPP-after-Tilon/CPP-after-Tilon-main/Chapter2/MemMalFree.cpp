#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char* MakeStrAdr(int len)
{
	char* str = (char*)malloc(sizeof(char) * len);
 // str이라는 char타입의 포인터를 선언. 선언과 동시에 
 // 파라미터 전달받은 만큼의 (길이)곱하기(char사이즈)의 메모리 할당.
	return str;//메모리 공간을 확보한 char 포인터 변수를 리턴
}

int main(void)
{
	char* str = MakeStrAdr(20);
	//이제 str에는 20 자 만큼의 string을 저장할 수 있음.
	strcpy(str, "I am so happy~");
	//str에 strcpy를 이용해 입력.
	cout << str << endl;
	free(str);//메모리 해제.<-반드시 해줘야 힙영역의 메모리가 해제됨.
	return 0;
}

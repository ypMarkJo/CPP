#include <iostream>
#include <string.h>
using namespace std;

char* MakeStrAdr(int len)
{
	char* str = new char[len];
	//new로 len길이만큼 char배열 메모리 할당.
	return str;
}

int main(void)
{
	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;
	// free(str);
	delete[]str;
	//str배열 삭제.
	return 0;
}

#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
	char str[256]="hello world!";
	int a = 16;
	int b=15;
	int c[5] = { 1,2,3,4,5 };
	FILE* wp;

	errno_t err = fopen_s(&wp, "test.bin", "wb");
	if (err != 0)
	{
		printf("Fail to create file\n");
		return 1;
	}
	fwrite(&a, sizeof(int), 1, wp);
	fwrite(&b, sizeof(int), 1, wp);

	//���ڿ� ���̳ʸ� ����
	size_t len = strlen(str);
	str[len] = '\0';
	fwrite(&len, sizeof(int), 1, wp);//���ʿ��ϰ� �޸� ������ �����Ǵ� �� ����. ���ڰ� �ִ� ��ŭ�� �޸� �Ҵ�.
	fwrite(str, len, 1, wp);

	//�迭 ���̳ʸ� ����
	fwrite(c, sizeof(int), 5, wp);
	fclose(wp);

	err = fopen_s(&wp, "test.bin", "rb");
	
	
	fread(&a, sizeof(int), 1, wp);
	fread(&b, sizeof(int), 1, wp);
	fread(&len, sizeof(int), 1, wp);
	fread(str,len,1,wp);
	fread(&c, sizeof(int), 5, wp);

	printf("%d %d %s %d %d %d %d %d\n",a,b,str,c[0],c[1],c[2],c[3],c[4]);	
	

	fclose(wp);

}
#include <iostream>

using namespace std;

int main()
{
	FILE* wp;
	errno_t err = fopen_s(&wp, "test.txt", "wt");
	if (err != 0)
	{
		printf("Fail to create file\n");
		return 1;
	}
	char a = "Hello world!" ;
	fprintf(wp, "%s\n", a);


	fclose(wp);

}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include "mysql.h"
#include "head.h"

using namespace std;
/*
int main()
{
	MYSQL mysql;
	if (mysql_init(&mysql) == NULL)
	{
		printf("this is init error\n");
		return 0;
	}
	if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, 0, 0) == NULL)
	{
		printf("%s\n", mysql_error(&mysql));
		return 0;
	}

	vector<World*>vec;
	char filename[256];//파일 이름 배열
	string query[2] = {
		"select continent,region,name,population,gnp from country order by gnp ASC","1"
	};

	FILE* fp;
	sprintf_s(filename, "./world/result%s.bin", query[1].c_str());
	errno_t err = fopen_s(&fp, filename, "rb");//파일만들고 입력하는"wb", 파일이름 입력
	if (err != 0)
	{
		printf("Fail to create file\n");
		return 1;
	}
	mysql_query(&mysql, "set names euckr");//글자 안 깨지게 만듬
	//sprintf_s(sqlstr, "select %s from %s","Continent","Country");//쿼리 전달-> 데이터 받아오기
	if (mysql_query(&mysql, query[0].c_str()) != 0)
		{
			printf("%s\n", mysql_error(&mysql));
			mysql_close(&mysql);
			return 0;
		}
		MYSQL_RES* res = mysql_store_result(&mysql);
		if (!res)
		{
			printf("%s\n", mysql_error(&mysql));
			mysql_close(&mysql);
			return 0;
		}
		int fieldCount = mysql_num_fields(res);
		MYSQL_ROW row;
		while (row = mysql_fetch_row(res))
		{
			World* wd = new World;
			wd->read(row, fieldCount, fp);
			vec.push_back(wd);
			printf("\n=================================================================\n");
		}
		mysql_free_result(res);
		for (auto wd : vec) { delete wd; }
		fclose(fp);
		vec.clear();
		mysql_close(&mysql);
}
*/

int main()
{
	FILE* fp;
	const char* filename = "./world/result5.bin";
	errno_t err = fopen_s(&fp, filename, "rb");//파일만들고 입력하는"wb", 파일이름 입력
	if (err != 0)
	{
		printf("Fail to read file\n");
		return 1;
	}

	size_t len, fieldCount;
	string str;

	while (fread(&fieldCount, sizeof(size_t), 1, fp))
	{
		for (int i = 0; i < fieldCount; i++)
		{
			fread(&len, sizeof(size_t), 1, fp);
			str.resize(len);
			fread((void*)str.c_str(), len, 1, fp);
			printf("%s,", str.c_str());
		}
		printf("\n");
	}

	fclose(fp);
}

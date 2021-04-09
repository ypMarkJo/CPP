#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include "mysql.h"
#include "biworld.h"

using namespace std;

string fields[3] =
{
	 "ID, Name, CountryCode, District, Population",
	"Code, Name, Continent, Region,LocalName, GovernmentForm, HeadOfState, Code2,SurfaceArea, LifeExpectancy, GNP, GNPOld,IndepYear, Population, Capital",
	"CountryCode, Language, IsOfficial, Percentage"
};
string tables[3] =
{
	"City","Country","CountryLanguage"
};
int main()
{
	MYSQL mysql;//서버 열고
	if (mysql_init(&mysql) == NULL)
	{
		printf("this is init error\n");
		return 0;
	}
	if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, 0, 0) == NULL)//데이터베이스 선택 &mysql/주소/아이디/비번/데이터베이스/0,0,0
	{
		printf("%s\n", mysql_error(&mysql));
		return 0;
	}
	CreateDirectory("world", NULL);//폴더만들고 "world"
	vector<World*>vec;
	char filename[256];//파일 이름 배열
	char sqlstr[256];//쿼리 배열
	for (int i = 0; i < 3; i++)//테이블 수만큼 돈다
	{
		FILE* fp = NULL;
		sprintf_s(filename, "./world/%s.bin", tables[i].c_str());//테이블 별로 넣어준다
		errno_t err = fopen_s(&fp, filename, "wb");//파일만들고 입력하는"wb", 파일이름 입력
		if (err != 0)
		{
			printf("Fail to create file\n");
			return 1;
		}
		mysql_query(&mysql, "set names euckr");//글자 안 깨지게 만듬
		sprintf_s(sqlstr, "select %s from %s", fields[i].c_str(), tables[i].c_str());//쿼리 전달-> 데이터 받아오기
		if (mysql_query(&mysql, sqlstr) != 0)
		{
			printf("%s\n", mysql_error(&mysql));
			mysql_close(&mysql);
			return 0;
		}
		MYSQL_RES* res = mysql_store_result(&mysql);//데이터를 res로 받아옴
		if (!res)
		{
			printf("%s\n", mysql_error(&mysql));
			mysql_close(&mysql);
			return 0;
		}
		int fieldCount = mysql_num_fields(res);// 받아온 결과의 필드 수를 세주는 함수
		MYSQL_ROW row;//필드의 ROW별로 받아오는 데이터를 row라 선언
		while (row = mysql_fetch_row(res))
		{
			World* wd = new World;//world클래스 포인터를 메모리 할당
			wd->write(row, fieldCount, fp);//받아오는 row값을 bin파일에 입력.
			vec.push_back(wd);
		}
		mysql_free_result(res);
		for (auto wd : vec) { delete wd; }
		fclose(fp);
		vec.clear();
	}
	mysql_close(&mysql);
}
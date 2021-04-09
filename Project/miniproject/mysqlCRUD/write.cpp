#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include "mysql.h"
#include "head.h"

using namespace std;

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
	string query[2] = {
		"select continent,region,name,population,gnp from country order by gnp ASC","5"
	};

	FILE* fp;
	sprintf_s(filename, "./world/result%s.bin", query[1].c_str());
	errno_t err = fopen_s(&fp,filename, "wb");//파일만들고 입력하는"wb", 파일이름 입력
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
	MYSQL_RES* res = mysql_store_result(&mysql);//데이터를 res로 받아옴
	if (!res)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 0;
	}
	int fieldCount = mysql_num_fields(res);// 받아온 결과의 필드 수를 세주는 함수
	int rowCount = mysql_num_rows(res);
	
	MYSQL_ROW row;//필드의 ROW별로 받아오는 데이터를 row라 선언
	int i = 1;
	while (row = mysql_fetch_row(res))
	{
		World* wd = new World;//world클래스 포인터를 메모리 할당
		
		wd->write(row,fieldCount,rowCount,fp);
		vec.push_back(wd);
		fwrite("\n", 1, 1, fp);
	
	}
	mysql_free_result(res);
	for (auto wd : vec) { delete wd; }
	fclose(fp);
	vec.clear();
	mysql_close(&mysql);
}

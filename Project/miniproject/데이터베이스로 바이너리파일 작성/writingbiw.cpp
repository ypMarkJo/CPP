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
	MYSQL mysql;//���� ����
	if (mysql_init(&mysql) == NULL)
	{
		printf("this is init error\n");
		return 0;
	}
	if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, 0, 0) == NULL)//�����ͺ��̽� ���� &mysql/�ּ�/���̵�/���/�����ͺ��̽�/0,0,0
	{
		printf("%s\n", mysql_error(&mysql));
		return 0;
	}
	CreateDirectory("world", NULL);//��������� "world"
	vector<World*>vec;
	char filename[256];//���� �̸� �迭
	char sqlstr[256];//���� �迭
	for (int i = 0; i < 3; i++)//���̺� ����ŭ ����
	{
		FILE* fp = NULL;
		sprintf_s(filename, "./world/%s.bin", tables[i].c_str());//���̺� ���� �־��ش�
		errno_t err = fopen_s(&fp, filename, "wb");//���ϸ���� �Է��ϴ�"wb", �����̸� �Է�
		if (err != 0)
		{
			printf("Fail to create file\n");
			return 1;
		}
		mysql_query(&mysql, "set names euckr");//���� �� ������ ����
		sprintf_s(sqlstr, "select %s from %s", fields[i].c_str(), tables[i].c_str());//���� ����-> ������ �޾ƿ���
		if (mysql_query(&mysql, sqlstr) != 0)
		{
			printf("%s\n", mysql_error(&mysql));
			mysql_close(&mysql);
			return 0;
		}
		MYSQL_RES* res = mysql_store_result(&mysql);//�����͸� res�� �޾ƿ�
		if (!res)
		{
			printf("%s\n", mysql_error(&mysql));
			mysql_close(&mysql);
			return 0;
		}
		int fieldCount = mysql_num_fields(res);// �޾ƿ� ����� �ʵ� ���� ���ִ� �Լ�
		MYSQL_ROW row;//�ʵ��� ROW���� �޾ƿ��� �����͸� row�� ����
		while (row = mysql_fetch_row(res))
		{
			World* wd = new World;//worldŬ���� �����͸� �޸� �Ҵ�
			wd->write(row, fieldCount, fp);//�޾ƿ��� row���� bin���Ͽ� �Է�.
			vec.push_back(wd);
		}
		mysql_free_result(res);
		for (auto wd : vec) { delete wd; }
		fclose(fp);
		vec.clear();
	}
	mysql_close(&mysql);
}
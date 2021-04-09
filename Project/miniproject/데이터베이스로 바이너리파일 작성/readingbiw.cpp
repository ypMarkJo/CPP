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
	CreateDirectory("world", NULL);
	vector<World*>vec;
	char filename[256];
	char sqlstr[256];
	for (int i = 0; i < 3; i++)
	{
		FILE* fp = NULL;
		sprintf_s(filename, "./world/%s.bin", tables[i].c_str());
		errno_t err = fopen_s(&fp, filename, "rb");
		if (err != 0)
		{
			printf("Fail to create file\n");
			return 1;
		}
		mysql_query(&mysql, "set names euckr");
		sprintf_s(sqlstr, "select %s from %s", fields[i].c_str(), tables[i].c_str());
		if (mysql_query(&mysql, sqlstr) != 0)
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
	}
	mysql_close(&mysql);
}

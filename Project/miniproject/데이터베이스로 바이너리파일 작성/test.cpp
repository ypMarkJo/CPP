#include <iostream>
#include <vector>

#include "mysql.h"
#include "world.h"

using namespace std;

#define FIELDS_COUNTRY "Code,Name,Continent,Region,SurfaceArea,IndepYear,Population,LifeExpectancy,GNP,GNPOld,LocalName,GovernmentForm,HeadOfState,Capital,Code2"
#define FIELDS_CITY "ID,Name,CountryCode,District,Population"
#define FIELDS_CONLANG  "CountryCode,Language,IsOfficial,Percentage"
void printData(const vector<World*>& vec)
{
	for (auto pc : vec)
	{
		pc->print();
		printf("=========================================\n");
	}
}
int main(int argc, char* argv[])
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

	char sqlstr[256];
	mysql_query(&mysql, "set names euckr");
	sprintf_s(sqlstr, "select Code,Name,Continent,Region,SurfaceArea,IndepYear,Population,LifeExpectancy,GNP,GNPOld,LocalName,GovernmentForm,HeadOfState,Capital,Code2  from Country  group by Region order by Population ;");
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
		Country* pc = new Country;
		int idx = 0;
		pc->save(row);
		vec.push_back(pc);
	}
	mysql_free_result(res);
	mysql_close(&mysql);
	printData(vec);
	for (auto pc : vec)
		delete pc;
	vec.clear();
}
// dbstudy.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

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
	// mysql db�� ����ϱ� ���� ���� ����
	MYSQL mysql;

	// ���� �ʱ�ȭ
	if (mysql_init(&mysql) == NULL)
	{
		printf("Fail to initialize mysql\n");
		return 0;
	}

	// �����ͺ��̽� ����
	if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, 0, 0) == NULL)
	{
		printf("%s\n", mysql_error(&mysql));
		return 0;
	}

	vector<World*> vec;

	// ���� ����
	char sqlstr[1024];
	mysql_query(&mysql, "set names euckr");

	//==================================================================
	//
	// Country
	//
	//==================================================================
	sprintf_s(sqlstr, "select %s from country", FIELDS_COUNTRY);
	if (mysql_query(&mysql, sqlstr) != 0)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 1;
	}

	// ���� ��� ����
	MYSQL_RES* res = mysql_store_result(&mysql);
	if (!res)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 1;
	}

	// ���� ��� �ʵ� ��
	int fieldCount = mysql_num_fields(res);

	// ���� ������� ���ڵ�(row)���� �ϳ��� ���� ����
	MYSQL_ROW row;
	// ��� ���ڵ带 �� ���� ������ �ݺ� ����
	while (row = mysql_fetch_row(res))
	{
		Country* pc = new Country;
		int idx = 0;

		/*if (row[idx]) pc->Code=row[idx]; idx++;
		if (row[idx]) pc-> Name= row[idx]; idx++;
		if (row[idx]) pc->Continent = row[idx]; idx++;
		if (row[idx]) pc->Region = row[idx]; idx++;
		if (row[idx]) pc->SurfaceArea = row[idx]; idx++;
		if (row[idx]) pc->IndepYear = row[idx]; idx++;
		if (row[idx]) pc->Population= row[idx]; idx++;
		if (row[idx]) pc->LifeExpectancy = row[idx]; idx++;
		if (row[idx]) pc->GNP = row[idx]; idx++;
		if (row[idx]) pc->GNPOld = row[idx]; idx++;
		if (row[idx]) pc->LocalName = row[idx]; idx++;
		if (row[idx]) pc->GovernmentForm = row[idx]; idx++;
		if (row[idx]) pc->HeadOfState = row[idx]; idx++;
		if (row[idx]) pc->Capital = row[idx]; idx++;
		if (row[idx]) pc->Code2 = row[idx]; idx++;*/
		pc->save(row);
		vec.push_back(pc);
	}
	// ���� ��� �޸� ����
	mysql_free_result(res);
	//==================================================================
	//
	// City
	//
	//==================================================================
	sprintf_s(sqlstr, "select %s from city", FIELDS_CITY);
	if (mysql_query(&mysql, sqlstr) != 0)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 1;
	}

	// ���� ��� ����
	res = mysql_store_result(&mysql);
	if (!res)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 1;
	}

	// ���� ��� �ʵ� ��
	fieldCount = mysql_num_fields(res);

	// ��� ���ڵ带 �� ���� ������ �ݺ� ����
	while (row = mysql_fetch_row(res))
	{
		City* pc = new City;
		int idx = 0;
		pc->save(row);
		/*   if (row[idx]) pc->ID = row[idx]; idx++;
		   if (row[idx]) pc->Name = row[idx]; idx++;
		   if (row[idx]) pc->CountryCode= row[idx]; idx++;
		   if (row[idx]) pc->District = row[idx]; idx++;
		   if (row[idx]) pc->Population = row[idx]; idx++;*/
		vec.push_back(pc);
	}
	// ���� ��� �޸� ����
	mysql_free_result(res);
	//==================================================================
	//
	// CountryLanguage
	//
	//==================================================================
	sprintf_s(sqlstr, "select %s from CountryLanguage", FIELDS_CONLANG);
	if (mysql_query(&mysql, sqlstr) != 0)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 1;
	}

	// ���� ��� ����
	res = mysql_store_result(&mysql);
	if (!res)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 1;
	}

	// ���� ��� �ʵ� ��
	fieldCount = mysql_num_fields(res);

	// ��� ���ڵ带 �� ���� ������ �ݺ� ����
	while (row = mysql_fetch_row(res))
	{
		CountryLanguage* pc = new CountryLanguage;
		int idx = 0;
		pc->save(row);
		/*     if (row[idx]) pc->CountryCode= row[idx]; idx++;
			 if (row[idx]) pc->Language = row[idx]; idx++;
			 if (row[idx]) pc->IsOfficial = row[idx]; idx++;
			 if (row[idx]) pc->Percentage = row[idx]; idx++;*/
		vec.push_back(pc);
	}

	// ���� ��� �޸� ����
	mysql_free_result(res);

	// �����ͺ��̽� �ݱ�
	mysql_close(&mysql);

	// ��ü ��ü�� ����Ѵ�.
	printData(vec);

	// ��ü ��ü���� �޸𸮿��� �����Ѵ�.
	for (auto pc : vec)
		delete pc;

	vec.clear();
}
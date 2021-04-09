// dbstudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
	// mysql db를 사용하기 위한 변수 선언
	MYSQL mysql;

	// 변수 초기화
	if (mysql_init(&mysql) == NULL)
	{
		printf("Fail to initialize mysql\n");
		return 0;
	}

	// 데이터베이스 연결
	if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, 0, 0) == NULL)
	{
		printf("%s\n", mysql_error(&mysql));
		return 0;
	}

	vector<World*> vec;

	// 질의 전달
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

	// 질의 결과 저장
	MYSQL_RES* res = mysql_store_result(&mysql);
	if (!res)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 1;
	}

	// 질의 결과 필드 수
	int fieldCount = mysql_num_fields(res);

	// 질의 결과에서 레코드(row)별로 하나씩 담을 변수
	MYSQL_ROW row;
	// 모든 레코드를 다 읽을 때까지 반복 수행
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
	// 질의 결과 메모리 해제
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

	// 질의 결과 저장
	res = mysql_store_result(&mysql);
	if (!res)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 1;
	}

	// 질의 결과 필드 수
	fieldCount = mysql_num_fields(res);

	// 모든 레코드를 다 읽을 때까지 반복 수행
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
	// 질의 결과 메모리 해제
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

	// 질의 결과 저장
	res = mysql_store_result(&mysql);
	if (!res)
	{
		printf("%s\n", mysql_error(&mysql));
		mysql_close(&mysql);
		return 1;
	}

	// 질의 결과 필드 수
	fieldCount = mysql_num_fields(res);

	// 모든 레코드를 다 읽을 때까지 반복 수행
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

	// 질의 결과 메모리 해제
	mysql_free_result(res);

	// 데이터베이스 닫기
	mysql_close(&mysql);

	// 전체 객체를 출력한다.
	printData(vec);

	// 전체 객체들을 메모리에서 제거한다.
	for (auto pc : vec)
		delete pc;

	vec.clear();
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include "mysql.h"
#include "bisakila.h"

using namespace std;

string fields[16] = {
	"actor_id,first_name,last_name,last_update",
	"address_id,address,address2,district,city_id,postal_code,phone,location,last_update",
"category_id,name,last_update",
"city_id,city,country_id,last_update",
"country_id,country,last_update",
"customer_id,store_id,first_name,last_name,email,address_id,active,create_date,last_update",
"film_id,title,description,release_year,language_id,original_language_id,rental_duration,rental_rate,length,replacement_cost,rating,special_features,last_update",
"actor_id,film_id,last_update",
"film_id,category_id,last_update",
"film_id,title,description",
"inventory_id,film_id,store_id,last_update",
"language_id,name,last_update",
"payment_id,customer_id,staff_id,rental_id,amount,payment_date,last_update",
"rental_id,rental_date,inventory_id,customer_id,return_date,staff_id,last_update",
"staff_id,first_name,last_name,address_id,email,store_id,active,username,password,last_update",
"store_id,manager_staff_id,address_id,last_update"
};
string tables[16] = {
	"actor","address","category","city","country","customer","film","film_actor","film_category","film_text","inventory","language","payment","rental","staff","store"
};
//void printData(const vector<Sakila*>& vec)//sakila을 사용할 경우
//void printData(const vector<Sakila1*>& vec)//sakila1을 사용할 경우
//{
//
//
//	for (auto sk : vec)
//	{
//		sk->print();
//		printf("=======================================\n");
//	}
//}
int main(int argc, char* argv[])
{


	MYSQL mysql;
	if (mysql_init(&mysql) == NULL)
	{
		printf("this is init error\n");
		return 0;
	}
	if (mysql_real_connect(&mysql, "localhost", "scott", "tiger", "sakila", 0, 0, 0) == NULL)
	{
		printf("%s\n", mysql_error(&mysql));
		return 0;
	}
	//CreateDirectory("sakila", NULL);
	vector<Sakila1*>vec;//sakila1을 사용할 경우
	//vector<Sakila*>vec;//sakila을 사용할 경우
	char filename[256];
	char sqlstr[256];
	for (int i = 0; i < 16; i++)
	{

		FILE* fp = NULL;
		sprintf_s(filename, "./sakila/%s.bin", tables[i].c_str());
		errno_t err = fopen_s(&fp, filename, "rb");
		if (err != 0)
		{
			printf("Fail to create file\n");
			return 1;
		}
		mysql_query(&mysql, "set names euckr");
		sprintf_s(sqlstr, "select %s from %s", fields[i].c_str(), tables[i].c_str());//받아올 쿼리 입력

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
			Sakila1* sk = new Sakila1;
			sk->read(row, fieldCount, fp);//sakila1을 사용할 경우
			printf("\n==============================================\n");
		}
		mysql_free_result(res);
		for (auto sk : vec)
			delete sk;
		vec.clear();
		fclose(fp);

	}
	mysql_close(&mysql);
}

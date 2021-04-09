#pragma once
#include <string>
#include <vector>
#include "mysql.h"
using namespace std;

//class Sakila
//{
//public:
//	Sakila() {}
//	~Sakila() {}
//	virtual void print() = 0;
//	virtual void save(MYSQL_ROW& row) = 0;
//};
//
//
class Sakila1
{
public:
	vector<string> values;
public:
	Sakila1() {}
	~Sakila1() {}
	void print()
	{
		for (size_t i = 0; i < values.size(); i++)
		{

			printf("%s\n", values[i].c_str());
		}
	}
	void save(MYSQL_ROW& row, int fieldCount, FILE* fp)
	{
		for (int i = 0; i < fieldCount; i++)
		{
			if (row[i])
			{
				fprintf_s(fp, "%s |", row[i]);
				//size_t len = strlen(row[i])+1;
				//fwrite(row[i], len, 1,fp);//binary write
				values.push_back(row[i]);
			}
			else  values.push_back("");
		}

	}
	/*void read(MYSQL_ROW& row, int fieldCount, FILE* fp)
	{
		for (int i = 0; i < fieldCount; i++)
		{
			if (row[i])
			{
				size_t len = strlen(row[i]) + 1;
				fread(row[i], len, 1, fp);
				printf("%s |", row[i]);
			}
			else  printf("");
		}
	}*/
}; //교수님 코드 클래스 하나로 다하는 방법.
//
//class Actor: public Sakila
//{
//public:
//	string F[4];
//public:
//	Actor()
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Actor() {}
//	void print()
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Address: public Sakila
//{
//public:
//	string F[9];
//public:
//	Address()
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Address() {}
//	void print()
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Catagory : public Sakila
//{
//public:
//	string F[3] ;
//public:
//	Catagory()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Catagory() {}
//	void print()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class City : public Sakila
//{
//public:
//	
//	string F[4];
//public:
//	City()
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~City() {}
//	void print()
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Country : public Sakila
//{
//public:
//	string F[3] ;
//public:
//	Country()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Country() {}
//	void print()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Customer : public Sakila
//{
//public:
//	string F[9];
//public:
//	Customer()
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Customer() {}
//	void print()
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Film : public Sakila
//{
//public:
//	string F[13];
//public:
//	Film()
//	{
//		for (int i = 0; i < 13; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Film() {}
//	void print()
//	{
//		for (int i = 0; i < 13; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 13; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Film_actor : public Sakila
//{
//public:
//	string F[3] = { "category_id","name","last_update" };
//public:
//	Film_actor()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Film_actor() {}
//	void print()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Film_category : public Sakila
//{
//public:
//	string F[3] = { "category_id","name","last_update" };
//public:
//	Film_category()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Film_category() {}
//	void print()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Film_text : public Sakila
//{
//public:
//	string F[3] ;
//public:
//	Film_text()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Film_text() {}
//	void print()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Inventory : public Sakila
//{
//public:
//	string F[4];
//public:
//	Inventory()
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Inventory() {}
//	void print()
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Language : public Sakila
//{
//public:
//	string F[3];
//public:
//	Language()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Language() {}
//	void print()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Payment : public Sakila
//{
//public:
//	string F[7] ;
//public:
//	Payment()
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Payment() {}
//	void print()
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Rental : public Sakila
//{
//public:
//	string F[7];
//public:
//	Rental()
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Rental() {}
//	void print()
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 7; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Staff : public Sakila
//{
//public:
//	string F[10];
//public:
//	Staff()
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Staff() {}
//	void print()
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};
//class Store : public Sakila
//{
//public:
//	string F[4];
//public:
//	Store()
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			F[i] = "";
//		}
//	}
//	~Store() {}
//	void print()
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			printf("%s\n", F[i].c_str());
//		}
//	}
//	void save(MYSQL_ROW& row)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			if (row[i]) F[i] = row[i];
//		}
//	}
//};

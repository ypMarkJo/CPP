#pragma once
#include <string>
#include <vector>
#include "mysql.h"
using namespace std;

//class Sakila
//{
//public:
//   Sakila() {}
//   ~Sakila() {}
//   virtual void print() = 0;
//   virtual void save(MYSQL_ROW& row) = 0;
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
                size_t len = strlen(row[i]) + 1;
                fwrite(&len, sizeof(size_t), 1, fp);//길이만큼 메모리 확보
                fwrite(row[i], len, 1, fp);//확보된 길이에 같은 길이의 데이터를 넘겨주는거
                values.push_back(row[i]);
            }
            else  values.push_back("");
        }

    }

    void read(MYSQL_ROW& row, int fieldCount, FILE* fp)
    {
        for (int i = 0; i < fieldCount; i++)
        {
            if (row[i])
            {
                size_t len = strlen(row[i]) + 1;
                char pc[256];
                fread(&len, sizeof(size_t), 1, fp);
                fread(pc, len, 1, fp);
                printf("%s |", row[i]);
            }
            else printf("");
          

        }

    }
};
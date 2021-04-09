#pragma once
//클래스 name,~name
#include <string>
#include <vector>
#include "mysql.h"
using namespace std;

class World
{
public:
    vector<string> values;

public:
    World() {}
    ~World() {}

    void write(MYSQL_ROW& row, int fieldCount, FILE* fp)//쓰기파일.
    {
        for (int i = 0; i < fieldCount; i++)
        {
            if (row[i])
            {
                size_t len = strlen(row[i]);//row 길이 크기  측정
                fwrite(&len, sizeof(size_t), 1, fp);//길이만큼 공간확보
                fwrite(row[i], len, 1, fp);//데이터투입
                values.push_back(row[i]);//벡터 한번에 삭제하려고 
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
                size_t len = strlen(row[i]);
                char pp[256];//데이터 받아올 배열 선언
                pp[len] = '\0';
                fread(&len, sizeof(size_t), 1, fp);//공간 먼저 받고
                fread(pp, len, 1, fp);//데이터 받아오고
                printf("%s | ", pp);
            }
            else printf("");
           
        }
    }
};

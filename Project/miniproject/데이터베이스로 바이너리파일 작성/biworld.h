#pragma once
//Ŭ���� name,~name
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

    void write(MYSQL_ROW& row, int fieldCount, FILE* fp)//��������.
    {
        for (int i = 0; i < fieldCount; i++)
        {
            if (row[i])
            {
                size_t len = strlen(row[i]);//row ���� ũ��  ����
                fwrite(&len, sizeof(size_t), 1, fp);//���̸�ŭ ����Ȯ��
                fwrite(row[i], len, 1, fp);//����������
                values.push_back(row[i]);//���� �ѹ��� �����Ϸ��� 
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
                char pp[256];//������ �޾ƿ� �迭 ����
                pp[len] = '\0';
                fread(&len, sizeof(size_t), 1, fp);//���� ���� �ް�
                fread(pp, len, 1, fp);//������ �޾ƿ���
                printf("%s | ", pp);
            }
            else printf("");
           
        }
    }
};

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"stack.h"
using namespace std;

int main()
{
    FILE* fp; 
   TYPE ch;
    Stack intStack;
   fp= fopen("OPEN.cpp", "r");
   if (fp == NULL)
   {
       cout << "������ ������ �ʾҽ��ϴ�.\n" << endl;
       return 1;
   }
   while ((ch = fgetc(fp)) != EOF)
   {
       if (ch == '{'||ch=='(') {
           intStack.Push(ch);
       }
       else if (ch == '}'||ch==')') {
           if (intStack.Empty()) {
               cout << "���� ��ȣ�� ���ڶ��ϴ�." << endl;
               break;
           }
           intStack.Pop();
       }
   }
   if (!intStack.Empty())
   {
       cout << " �ݴ� ��ȣ�� ���ڶ��ϴ�." << endl;
   }
   fclose(fp);
}
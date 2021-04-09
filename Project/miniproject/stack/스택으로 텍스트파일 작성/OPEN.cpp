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
       cout << "파일이 열리지 않았습니다.\n" << endl;
       return 1;
   }
   while ((ch = fgetc(fp)) != EOF)
   {
       if (ch == '{'||ch=='(') {
           intStack.Push(ch);
       }
       else if (ch == '}'||ch==')') {
           if (intStack.Empty()) {
               cout << "여는 괄호가 모자랍니다." << endl;
               break;
           }
           intStack.Pop();
       }
   }
   if (!intStack.Empty())
   {
       cout << " 닫는 괄호가 모자랍니다." << endl;
   }
   fclose(fp);
}
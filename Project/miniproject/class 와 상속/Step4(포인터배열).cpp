#include "student1.h"
#include <iostream>
#include<time.h>
#include<vector>
using namespace std;

int findMin(Student* s[], int subj)
{
	int ret=0;
	for (int i = 1; i < 10; i++)
		if (s[ret]->getGrades(subj) > s[i]->getGrades(subj))	ret = i;
	return ret;
}
int findMax(Student* s[], int subj)
{
	int ret = 0;
	for (int i = 1; i < 10; i++)
		if (s[ret]->getGrades(subj) < s[i]->getGrades(subj))	ret = i;
	return ret;
}
int main()
{
	srand((unsigned int)time(NULL));
	Student* s[10] = { 0, };
	string  name[10] = { "조영평","서여진","남청우","김현우","정진영","조용운","김재민","주나현","이인재","이진욱" };
	for (int i = 0; i < 10; i++)
	{
		s[i] = new Student;
		s[i]->setName(name[i]);
		s[i]->initStudent();
	}
	//int sub = GEO;//조회를 원하는 과목을 지정.
	for (int i = 0; i < 5; i++)
	{
		int t = findMin(s, i);
		printf("[%s] 최저득점 학생 \n", subjTitles[i].c_str());
		s[t]->show();
		cout << "평균: [ " << s[t]->getAvg() << " ] 점\n" << endl;
		t = findMax(s, i);
		printf("[%s] 최고득점 학생 \n", subjTitles[i].c_str());
		s[t]->show();
		cout << "평균: [ " << s[t]->getAvg() << " ] 점\n" << endl;
	}
	for (auto t:s)	delete t;
}
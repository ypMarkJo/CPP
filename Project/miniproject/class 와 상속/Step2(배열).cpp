#include "student1.h"
#include <iostream>
#include<time.h>

using namespace std;

int findMax(Student s[], int subj)
{
	int ret=0;
		for (int i = 1; i < 10; i++)
			if (s[ret].getGrades(subj) <s[i].getGrades(subj)) ret = i;
	return ret;
}
int findMin(Student s[], int subj)
{
	int ret=0;
	for (int i = 1; i < 10; i++)
		if (s[ret].getGrades(subj) > s[i].getGrades(subj)) ret = i;
	return ret;
}
int main()
{
	srand((unsigned int)time(NULL));
	Student s[10];
	string  name[10] = { "조영평","서여진","남청우","김현우","정진영","조용운","김재민","주나현","이인재","이진욱" };
	for (int i = 0; i < 10; i++)
	{
		s[i].setName(name[i]);
		s[i].initStudent();
	}
	int t = findMin(s, SCI);
	printf("과학 최저득점 학생: \n");
	s[t].show();
	cout << "평균: " << s[t].getAvg() << " 점\n" << endl;
	t = findMax(s, SCI);
	printf("과학 최고득점 학생: \n");
	s[t].show();
	cout << "평균: " << s[t].getAvg() << " 점\n" << endl;
}
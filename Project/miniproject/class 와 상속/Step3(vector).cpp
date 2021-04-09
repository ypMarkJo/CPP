#include "student1.h"
#include <iostream>
#include<time.h>
#include<vector>
using namespace std;

Student* findAvgmin(vector<Student*>vec)
{
	float Avgmin = 100;
	Student* ret=NULL;
		for (auto t : vec)
		{
			if (Avgmin > t->getAvg())
			{
				Avgmin = t->getAvg();
				ret = t;
			}
		}
		return ret;
	}
Student* findAvgmax(vector<Student*>vec)
{
	float Avgmax =0;
	Student* ret = NULL;
	for (auto t : vec)
	{
		if (Avgmax < t->getAvg())
		{
			Avgmax = t->getAvg();
			ret = t;
		}
	}
	return ret;
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<Student*>vec;
	Student*s1=new Student("홍길동");
	s1->initStudent();
	s1->show();
	vec.push_back(s1);

	Student* s2 = new Student("장발장");
	s2->initStudent();
	s2->show();
	vec.push_back(s2);

	Student* s3 = new Student("곽두팔");
	s3->initStudent();
	s3->show();
	vec.push_back(s3);
	
	Student* pn = findAvgmin(vec);
	cout << "평점이 제일 낮은 사람은 [" << pn->getName() << "] 입니다." << endl;
	cout << "평점은 [" << pn->getAvg() << "점] 입니다." << endl;
	Student* px = findAvgmax(vec);
	cout << "평점이 제일 높은 사람은 [" << px->getName() << "] 입니다." << endl;
	cout << "평점은 [" << px->getAvg() << "점] 입니다." << endl;

	for (auto t: vec) delete t;
	vec.clear();
}
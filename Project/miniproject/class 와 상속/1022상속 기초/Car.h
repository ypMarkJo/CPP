#include<iostream>
#include<string>
using namespace std;
class Car
{public:
	string brand;//ȸ��
	string model;//�𵨸�
	int cc;//��ⷮ
	string type;//SUV,����,����,����

public:
	Car();
	Car(string b, string m, int c, string t);
	~Car();

	void Setbrand(string b);
	string Getbrand();
	void Setmodel(string m);
	string Getmodel();
	void Setcc(int c);
	int Getcc();
	void Settype(string t);
	string Gettype();
};
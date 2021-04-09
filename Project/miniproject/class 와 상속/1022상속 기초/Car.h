#include<iostream>
#include<string>
using namespace std;
class Car
{public:
	string brand;//회사
	string model;//모델명
	int cc;//배기량
	string type;//SUV,중형,대형,소형

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
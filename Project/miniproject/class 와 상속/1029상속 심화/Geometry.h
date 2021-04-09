#include<iostream>
#include<string>
using namespace std;
typedef struct point {
	double x;
	double y;
} POINT;
class Geometry {
public:
	POINT pt;
	Geometry(double x, double y) {
		pt.x = x;
		pt.y = y;
		}
	void Print() {
		cout <<"좌표는 ("<< pt.x << "," << pt.y <<")"<< endl;
	}
};
class Point : public Geometry {
public:
	string Name;
	Point(double x,double y,string n=""):Geometry(x,y) {
		Name = n;
	}
	void Print() {
		Geometry::Print();
		cout << Name << endl;
	}
};
class Circle :public Geometry {
public:
	double R;
	Circle(double x, double y, double r = 0) :Geometry(x,y) {
		R = r;
	}
	void Print() {
		Geometry::Print();
		cout <<"반지름은 "<< R << endl;
		}
	void Paint() {
		for (double x = -2 * R; x <= 2 * R; x += 2) {
			for (double y = -R; y <= R; y++) {
				if((x*x+y*y)>=R*R-R/1.3&&(x*x+y*y)<=R*R+R/1.3)
					printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
};
class Line :public Geometry {
public:
	POINT* ppt;

};

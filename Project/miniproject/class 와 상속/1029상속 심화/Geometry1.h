#include<iostream>
#include<string>
#include<math.h>

using namespace std;
typedef struct point {
	double x;
	double y;
} POINT;
class Geometry {
public:
	POINT* pt;//pt�� �ּҷ� ����
	Geometry(double x=0, double y=0, int count = 0) {
		if (count == 0) {//line�� ������� �ʾƵ� �ٸ� �Լ����� �� �� �־���ϴϱ� 
			pt = new POINT[1];
			pt->x = x;
			pt->y = y;
		}
		else
		{
			pt = new POINT[count];
		}
	}
	~Geometry()
	{
		delete  []pt;
	}
	void Print() {
		cout << "��ǥ�� (" << pt->x << "," << pt->y << ")" << endl;
	}
};
class Point : public Geometry {
public:
	string Name;
	Point(double x, double y, string n = "") :Geometry(x, y) {
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
	Circle(double x, double y, double r = 0) :Geometry(x, y) {
		R = r;
	}
	void Print() {
		Geometry::Print();
		cout << "�������� " << R << endl;
	}
	void Paint() {
		for (double x = -2 * R; x <= 2 * R; x += 2) {
			for (double y = -R; y <= R; y++) {
				if ((x * x + y * y) >= R * R - R / 1.3 && (x * x + y * y) <= R * R + R / 1.3)
					printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
};
class Line :public Geometry {
public:
	int count;
	Line(int count) : Geometry (0, 0, count) {
		this->count = count;
	}
	void setPoint(int idx, double x, double y)
	{
		pt[idx].x = x;
		pt[idx].y = y;
	}
	double getLength() {
		double len = 0.0;
		for (int i = 0; i < count-1; i++)
		{
			len += sqrt(pow((pt[i + 1].x - pt[i].x), 2) + pow((pt[i + 1].y - pt[i].y), 2));
		}
		return len;
	}
	void print()
	{
		for (int i = 0; i < count; i++)
		{
			cout << "\t(" << pt[i].x << "," << pt[i].y << ")" << endl;
		}
		double len = getLength();
		cout << "Total Length:" << len << endl;
	}
};

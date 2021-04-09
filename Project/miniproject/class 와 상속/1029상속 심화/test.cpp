#include "Geometry1.h"
int main() {
	//Geometry g(10, 20);
	//g.Print();
	//Point pt(10, 20,"¿ø½É");
	//pt.Print();
	//Circle c(10, 20, 20);
	//c.Print();
	//c.Paint();
	
	Line m(5);
	m.setPoint(0, 10, 10);
	m.setPoint(1, 11, 30);
	m.setPoint(2, 12, 40);
	m.setPoint(3, 13, 50);
	m.setPoint(4, 14, 60);
	m.print();

	return 1;
}
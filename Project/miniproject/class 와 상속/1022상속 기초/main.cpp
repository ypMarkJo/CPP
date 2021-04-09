#include<iostream>
#include"Car.h"

int main() {
	
	Car Mycar;
	Mycar.Setbrand("Ford");
	cout << Mycar.Getbrand() << endl;
	Car Mymodel;
	Mymodel.Setmodel("Mustang");
	cout << Mymodel.Getmodel() << endl;
	Car Myvolume;
	Myvolume.Setcc(4951);
	cout << Myvolume.Getcc() << endl;
	Car Mytype;
	Mytype.Settype("Sports car");
	cout << Mytype.Gettype() << endl;


	return 1;
}
#include "Car.h"

Car::Car()
{
	brand = model =  type = "car";
	cc = 0;
}
Car::Car(string b, string m, int c, string t)
{
	brand = b;
	model = m;
	cc = c;
	type = t;

	cout << "Construct" << endl;

}
Car::~Car()
{
	cout << "Destruct" << endl;
}
void Car::Setbrand(string b)
{
	brand = b;
}
string Car::Getbrand() {
	return brand;
}
void Car::Setmodel(string m) {
	model = m;
}
string Car::Getmodel() {
	return model;
}
void Car::Setcc(int c) {
	cc = c;
}
int Car::Getcc() {
	return cc;
}
void Car::Settype(string t) {
	type = t;
}
string Car::Gettype() {
	return type;
}

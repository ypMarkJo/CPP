#include<iostream>
#define TYPE char

class Stack {
public:
	TYPE data[50];
	int nElements;
	Stack() :nElements(0) {}
	void Push(TYPE item);
	TYPE Pop();
	int Number();
	int Empty();
};
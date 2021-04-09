#include"stack.h"
void Stack::Push(TYPE item) {
	data[nElements] = item;
	nElements++;
}
TYPE Stack::Pop() {
	nElements--;
	return data[nElements];
}
int Stack::Number() {
	return nElements;
}
int Stack::Empty() {
	return(nElements == 0);
}
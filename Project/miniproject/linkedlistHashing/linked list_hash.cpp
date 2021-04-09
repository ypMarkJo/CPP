#include <iostream>
#include <string.h>
#include "linked list_hash.h"

using namespace std;

int main()
{
	const char* keys[] = { "bill", "ibll", "lee", "pauline", "alan", "julie",
						 "mike", "elizabeth", "mark", "ashley", "peter",
						 "joan", "john", "charles", "mary", "emily" };

	const int numkeys = 16;
	myHash h;
 	for (int i = 0; i < numkeys; i++)
	{
		int hk = h.Hash(keys[i]);
		int hc = hk % 10;
		printf("%10s%10d%5d\n", keys[i], hk, hc);

		h.add(keys[i]);
	}
	printf("=================================================\n");

	h.print();

	printf("=================================================\n");
	//Node* t = h.search("john");
	//printf("Search result:[%s]\n", t->key);

	return 1;
}

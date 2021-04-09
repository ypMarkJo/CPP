#ifndef HASH_H
#define HASH_H
#include <string.h>
using namespace std;

class Node
{
public:
	const char* key;
	Node* next;

	Node(const char* k) : key(k) {
		next = NULL;
	}
};

class myHash
{
	int code;

	// 해시버켓용 Node 포인터 배열
	Node* bucket[10] = { NULL, };

public:
	myHash(int c = 0) :code(c)
	{
	}
	~myHash()
	{
		for (int i = 0; i <= 9; i++)
		{
			while (bucket[i])
			{
				Node* t = bucket[i]->next;
				delete bucket[i];
				bucket[i] = t;
			}
			
		}
		// 3. 버켓에 할당된 Node 리스트를 해제하는 코드 작성

	}

	int Hash(const char* key)
	{
		int sum = 0;
		int len = strlen(key);
		for (int i = 0; i < len; i += 2)
			sum += (key[i] * (i + 1));
		return sum;
	}

	void add(const char* key)
	{
		int hk = Hash(key) % 10;
		Node* node = new Node(key);
		if (bucket[hk] == NULL)
			bucket[hk] = node;
		else
		{
			node->next=bucket[hk];
			bucket[hk] = node;
		}// 1. key를 이용해서 Node 객체를 만든뒤 버켓에 추가하는 코드 작성

	}

	void print()
	{
		for (int i = 0; i <= 9; i++)
		{   
			Node* t = bucket[i];
;			while(t)
			{  
				printf("bucket[%2d]: %s\n",i, *t);
				t = t->next;
			}
           printf("------------------------------------");

		}
		// 2. 버켓을 순회하면서 입력된 모든 데이터를 화면에 출력하는 코드 작성
	}

	Node* search(const char* key)
	{
		if (strcmp(key, bucket[]) == 0)
			
	
		// 4. key값을 가진 Node를 리턴하는 코드 작성
	}
};

#endif

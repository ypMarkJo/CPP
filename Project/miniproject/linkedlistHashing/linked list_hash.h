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

	// �ؽù��Ͽ� Node ������ �迭
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
		// 3. ���Ͽ� �Ҵ�� Node ����Ʈ�� �����ϴ� �ڵ� �ۼ�

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
		}// 1. key�� �̿��ؼ� Node ��ü�� ����� ���Ͽ� �߰��ϴ� �ڵ� �ۼ�

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
		// 2. ������ ��ȸ�ϸ鼭 �Էµ� ��� �����͸� ȭ�鿡 ����ϴ� �ڵ� �ۼ�
	}

	Node* search(const char* key)
	{
		if (strcmp(key, bucket[]) == 0)
			
	
		// 4. key���� ���� Node�� �����ϴ� �ڵ� �ۼ�
	}
};

#endif

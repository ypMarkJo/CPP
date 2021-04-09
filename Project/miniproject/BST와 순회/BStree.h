#include<iostream>
#include<stack>
//#include<iterator>
#include <vector>

using namespace std;

//이진 탐색 트리

class Node {
public:
	Node(int k) :key(k)
	{
		left = NULL;//왼쪽 자식 포인터
		right = NULL;//오른쪽 자식 포인터
	}
	int key;
	Node* left;//왼쪽 자식 포인터
	Node* right;//오른쪽 자식 포인터
};
class BSearchTree
{
	int nodeVisitCount;//노드를 방문하는 횟수를 저장.
	Node* root;
	//노드들을 삭제하기 위해 DFS로 노드를 수집한다.
	void appendStack(stack<Node*>& st, Node* node)
	{
		st.push(node); 
		if (node->left != NULL)appendStack(st, node->left);
		if (node->right != NULL)appendStack(st, node->right);
	}
	void appendStack(vector<Node*>& st, Node* node)
	{
		st.push_back(node);
		if (node->left != NULL)appendStack(st, node->left);
		if (node->right != NULL)appendStack(st, node->right);
	}

	//노드 삽입
	Node* insertdata(Node* node, int key)
	{
		if (node == NULL)return new Node(key);//트리가 비었다면 새로 노드를 만듦
		if (key < node->key)
			node->left = insertdata(node->left, key);//찾는 키<노드키 이면 왼쪽.
		else if(key>node->key)
			node->right = insertdata(node->right, key);//찾는 키>노드키 이면 오른쪽.
		return node;// 노드 포인터 반환

	}
	//key값 검색
	Node* searchdata(Node* node, int key)
	{
		nodeVisitCount++;
		if (node == NULL)return NULL;
		if (key > node->key)
			node->right=searchdata(node->right, key);//key가 node의 key보다 크면 오른쪽 트리로 재귀호출
		if (key < node->key)
			node->left = searchdata(node->left, key);//key가 node의 key보다 작으면 왼쪽 트리로 재귀호출
		if (key = node->key)
			return node;//key가 node의 key가 같으면 노드를 리턴

	}
	//전위순회 지왼오
	void preorder(Node* node)
	{
		if (node == NULL) return;
		printf("%d \n", node->key);
		preorder(node->left);
		preorder(node->right);
	}
	//중위순회 왼지오
	void inorder(Node* node)
	{
		if (node == NULL) return;
		inorder(node->left);
		printf("%d \n", node->key);
		inorder(node->right);
	}
	//후위순회 왼오지
	void postorder(Node* node)
	{
		if (node == NULL)return;
		postorder(node->left);
		postorder(node->right);
		printf("%d \n", node->key);
	}
public:
	BSearchTree()
	{
		root = NULL;
		nodeVisitCount = 0;
	}
	~BSearchTree()
	{
		//stack<Node*>st;
		vector<Node*> st;
		//st.push(root);
		st.push_back(root);
		//if (root->left != NULL)appendStack(st, root->left);
		//if (root->right != NULL)appendStack(st, root->right);
		if (root->left != NULL)appendStack(st, root->left);
		if (root->right != NULL)appendStack(st, root->right);

		cout << "delete: ";
		//while (0 < st.size())
		//{
		//	Node* node = st.top();
		//	cout << node->key << ",";
		//	delete node;
		//	st.pop();
		//}
		for (int i = 0; i < st.size() ;i++)
		{
			cout << st[i]->key << ",";
			delete st[i];
		}

		cout << "\n";
	}
	int getVisitCount()
	{
		return nodeVisitCount;
	}
	//노드 삽입
	Node* insertdata(int key)
	{
		if(!root)
		{
			root = new Node(key);
			return root;
		}
		return insertdata(root, key);
	}
	//key값 검색
	Node* searchdata(int key)
	{
		nodeVisitCount = 0;
		return searchdata(root, key);
	}
	//전위순회로 출력
	void preorder() { preorder(root); }
	//중위순회로 출력
	void inorder() { inorder(root); }
	//후위순회로 출력
	void postorder() { postorder(root); }
};
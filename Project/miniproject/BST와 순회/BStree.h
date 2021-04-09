#include<iostream>
#include<stack>
//#include<iterator>
#include <vector>

using namespace std;

//���� Ž�� Ʈ��

class Node {
public:
	Node(int k) :key(k)
	{
		left = NULL;//���� �ڽ� ������
		right = NULL;//������ �ڽ� ������
	}
	int key;
	Node* left;//���� �ڽ� ������
	Node* right;//������ �ڽ� ������
};
class BSearchTree
{
	int nodeVisitCount;//��带 �湮�ϴ� Ƚ���� ����.
	Node* root;
	//������ �����ϱ� ���� DFS�� ��带 �����Ѵ�.
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

	//��� ����
	Node* insertdata(Node* node, int key)
	{
		if (node == NULL)return new Node(key);//Ʈ���� ����ٸ� ���� ��带 ����
		if (key < node->key)
			node->left = insertdata(node->left, key);//ã�� Ű<���Ű �̸� ����.
		else if(key>node->key)
			node->right = insertdata(node->right, key);//ã�� Ű>���Ű �̸� ������.
		return node;// ��� ������ ��ȯ

	}
	//key�� �˻�
	Node* searchdata(Node* node, int key)
	{
		nodeVisitCount++;
		if (node == NULL)return NULL;
		if (key > node->key)
			node->right=searchdata(node->right, key);//key�� node�� key���� ũ�� ������ Ʈ���� ���ȣ��
		if (key < node->key)
			node->left = searchdata(node->left, key);//key�� node�� key���� ������ ���� Ʈ���� ���ȣ��
		if (key = node->key)
			return node;//key�� node�� key�� ������ ��带 ����

	}
	//������ȸ ���޿�
	void preorder(Node* node)
	{
		if (node == NULL) return;
		printf("%d \n", node->key);
		preorder(node->left);
		preorder(node->right);
	}
	//������ȸ ������
	void inorder(Node* node)
	{
		if (node == NULL) return;
		inorder(node->left);
		printf("%d \n", node->key);
		inorder(node->right);
	}
	//������ȸ �޿���
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
	//��� ����
	Node* insertdata(int key)
	{
		if(!root)
		{
			root = new Node(key);
			return root;
		}
		return insertdata(root, key);
	}
	//key�� �˻�
	Node* searchdata(int key)
	{
		nodeVisitCount = 0;
		return searchdata(root, key);
	}
	//������ȸ�� ���
	void preorder() { preorder(root); }
	//������ȸ�� ���
	void inorder() { inorder(root); }
	//������ȸ�� ���
	void postorder() { postorder(root); }
};
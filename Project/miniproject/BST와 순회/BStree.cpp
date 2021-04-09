#include"BStree.h"
//이진탐색트리
int main()
{
	BSearchTree bstree;
	bstree.insertdata(50);
	bstree.insertdata(30);
	bstree.insertdata(40);
	bstree.insertdata(20);
	bstree.insertdata(25);
	bstree.insertdata(60);
	bstree.insertdata(70);
	bstree.insertdata(58);
	bstree.insertdata(65);
	bstree.insertdata(68);
	bstree.insertdata(80);

	Node*node=bstree.searchdata(68);
	printf("찾는 데 몇 번 순회?: %d \n",bstree.getVisitCount());

	cout << "========================================\n";
	cout << "bstree.preorder(): \n";
	bstree.preorder();//출력
	cout << "========================================\n";
	cout << "bstree.inorder(): \n";
	bstree.inorder();//출력
	cout << "========================================\n";
	cout << "bstree.postorder(): \n";
	bstree.postorder();//출력

	return 0;
}
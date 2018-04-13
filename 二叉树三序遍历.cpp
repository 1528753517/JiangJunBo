#include<iostream>
using namespace std;
class TreeNode
{
public:
	char data;
	TreeNode* lchild;
	TreeNode* rchild;
};
class BinaryTree
{
private:
	TreeNode* T; 
public:
	void create(); //�������ݶ������ĳ�ʼ��
	TreeNode * createBiTree(); //�����������
	void traverse(); //ѡ������������ķ�ʽ
	TreeNode* preorderTraverse(); //�������
	TreeNode* inorderTraverse(); //�������
	TreeNode* lastorderTraverse(); //�������
};
void BinaryTree::create()
{
	cout << "Input data : ";
	T = createBiTree();
	return;
}
TreeNode* BinaryTree::createBiTree() 
{
	char c;
	TreeNode* p; //
	cin >> c;
	if (c == '#') //���롰#����ʾ��ҶΪ��
		p = NULL;
	else
	{
		p = new TreeNode;
		p->data = c;
		p->lchild = createBiTree();
		p->rchild = createBiTree();
	}
	return p;
}
void BinaryTree::traverse()
{
	int s;
	cout << "\tSelect a way to traverese :" << endl;
	cout << "\t1.Preorder\t2.Inorder\t3.Lastorder\t[ ]\b\b";
	cin >> s;
	switch (s)
	{
	case 1:
		preorderTraverse();
		break;
	case 2:
		inorderTraverse();
		break;
	case 3:
		lastorderTraverse();
		break;
	}
	return;
}
TreeNode* BinaryTree::preorderTraverse()
{
	if (T)
	{
		cout << T->data << ends;
		T->lchild = preorderTraverse();
		T->rchild = preorderTraverse();
	}
	return T;
}
TreeNode* BinaryTree::inorderTraverse()
{
	if (T)
	{
		T->lchild = inorderTraverse();
		cout << T->data << ends;
		T->rchild = inorderTraverse();
	}
	return T;
}
TreeNode* BinaryTree::lastorderTraverse()
{
	if (T)
	{
		T->lchild = inorderTraverse();
		T->rchild = inorderTraverse();
		cout << T->data << ends;
	}
	return T;
}
int main()
{
	BinaryTree T;
	T.create();
	T.traverse();
	return 0;
}
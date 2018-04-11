#include<iostream>
using namespace std;

typedef struct BTNode
{
	char data;
	BTNode *pLchild;
	BTNode *pRchild;
}BTNode, *BTree;

class asdasd
{
public:
	BTree create_tree();
	void pre_traverse(BTree);
	void in_traverse(BTree);
	void beh_traverse(BTree);
};

BTree asdasd::create_tree()//创建二叉树
{
	BTree pA = new BTNode;
	BTree pB = new BTNode;
	BTree pD = new BTNode;
	BTree pE = new BTNode;
	BTree pC = new BTNode;
	BTree pF = new BTNode;

	pA->data = 'A';
	pB->data = 'B';
	pD->data = 'D';
	pE->data = 'E';
	pC->data = 'C';
	pF->data = 'F';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pD;
	pB->pRchild = pE;
	pD->pLchild = pD->pRchild = NULL;
	pE->pLchild = pE->pRchild = NULL;
	pC->pLchild = pF;
	pC->pRchild = NULL;
	pF->pLchild = pF->pRchild = NULL;

	return pA;
}

void asdasd::pre_traverse(BTree pTree)//前序遍历(根左右)
{
	if (pTree)
	{
		cout << pTree->data << ends;
		if (pTree->pLchild)
			pre_traverse(pTree->pLchild);
		if (pTree->pRchild)
			pre_traverse(pTree->pRchild);
	}
}

void asdasd::in_traverse(BTree pTree)//中序遍历（左根右）
{
	if (pTree)
	{
		if (pTree->pLchild)
			in_traverse(pTree->pLchild);
		cout << pTree->data << ends;
		if (pTree->pRchild)
			in_traverse(pTree->pRchild);
	}
}

void asdasd::beh_traverse(BTree pTree)//后序遍历（左右根）
{
	if (pTree)
	{
		if (pTree->pLchild)
			beh_traverse(pTree->pLchild);
		if (pTree->pRchild)
			beh_traverse(pTree->pRchild);
		cout << pTree->data << ends;
	}
}

int main()
{
	asdasd a;
	BTree pTree = a.create_tree();
	cout << "递归实现前序遍历结果：";
	a.pre_traverse(pTree);
	cout << endl;
	cout << "递归实现中序遍历结果：";
	a.in_traverse(pTree);
	cout << endl;
	cout << "递归实现后序遍历结果：";
	a.beh_traverse(pTree);
	cout << endl;

	return 0;
}
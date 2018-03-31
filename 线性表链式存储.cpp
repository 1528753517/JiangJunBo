#include<iostream>
using namespace std;
typedef struct node //链式存储所需要用到的结点
{
	int data;
	node* next;
}Node,*PNode;
class List //类：线性表
{
protected:
	int elem; //数据元素
};
class Sqstore :virtual public List //类：顺序存储的线性表（是线性表的派生类）
{
};
class Linkstore :virtual public List //类：链式存储的线性表（是线性表的派生类）
{
public: //均为纯虚函数的声明
	virtual void init() = 0; //初始化
	virtual void add() = 0; //增加
	virtual void delet() = 0; //删除
	virtual void traverse() = 0; //遍历
	virtual void insert()
	{
		//插入（单链表所特有）
		return;
	}
};
class Link :virtual public Linkstore //类：单链表（是链式存储的线性表的派生类）
{
private:
	PNode head; //头节点
	PNode phead; //头指针
public:
	void init(); //单链表的初始化
	void add(); //尾插法实现创建单链表
	void delet(); //在单链表中删除特定值的结点
	void insert(); //在单链表中插入特定位置的结点
	void traverse(); //遍历单链表并打印
};
void Link::init()
{
	phead = head = new node; //头指针指向头节点，通过头指针间接对单链表进行操作
	phead->next = NULL;
	return;
}
void Link::add()
{
	int len;
	cout << "Please input the length of link-list : "; //定义单链表的长度
	cin >> len;
	cout << "List-1 : ";
	for (int i = 0; i < len; i++) //每创造一个新的结点，头指针指向新节点
	{
		PNode p = new node;
		cin >> p->data;
		phead->next = p;
		phead = p;
		phead->next = NULL;
	}
	return;
}
void Link::delet()
{
	int n;
	PNode L = new node; //用于遍历单链表
	PNode p = new node; //用于删除结点后的连接
	PNode q = new node; //用于删除结点的指针
	cout << "Please input the data you want to delete : ";
	cin >> n;
	for (L = head->next; L && L->data != n; L = L->next)
		p = L;
	q = L;
	p->next = L->next;
	delete q;
	return;
}
void Link::insert()
{
	int i, n;
	PNode p = new node; //待插入的结点
	PNode q = new node; //用于遍历单链表
	PNode L = new node; //用于插入后的连接
	cout << "Please input the data you want to insert : ";
	cin >> p->data;
	p->next = NULL;
	cout << "Please input the location that you want to insert : ";
	cin >> i;
	for (q = head->next, n = 1; n < i&& q; q = q->next, n++)
		L = q;
	p->next = q;
	L->next = p;
	return;
}
void Link::traverse()
{
	PNode p;
	cout << "List-1 elements : ";
	for (p = head; p->next != NULL; p = p->next)
		cout << p->next->data << ends;
	cout << endl;
	return;
}
class Stack :virtual public Linkstore //类：链栈（是链式存储的线性表的派生类）
{
private:
	PNode top; //栈顶指针
	PNode base; //栈底指针
public:
	void init(); //创建一个空的栈
	void add(); //入栈操作
	void delet(); //出栈操作
	void traverse(); //从栈顶开始遍历并打印
};
void Stack::init()
{
	base = new node;
	base->next = NULL; //固定栈底
	top = base; //栈顶指针指向栈底，链栈为空
	return;
}
void Stack::add()
{
	int num;
	cout << "Please input the number of elements you want to add : ";
	cin >> num;
	for (int i = 0; i < num;)
	{
		cout << "Element " << ++i << " :";
		PNode p = new node; //创建一个结点
		cin >> p->data;
		p->next = top; //令该结点的next成为栈顶的前驱
		top = p; //栈顶指针指向p，p成为新的栈顶
	}
	return;
}
void Stack::delet()
{
	int num;
	cout << "Please input the number of elements you want to delete : ";
	cin >> num;
	for (int i = 0; i < num;i++)
	{
		PNode p = new node;
		p = top; //把栈顶地址赋给p
		top = top->next; //栈顶指针指向栈顶的前一个结点
		delete p; //释放删除的结点所占的内存空间
	}
	return;
}
void Stack::traverse()
{
	PNode p; //申请指针可以在栈内移动 
	cout << "List-2 elements : ";
	for (p = top; p->next != NULL; p = p->next)
		cout << p->data << ends;
	cout << endl;
	return;
}
class Queue :virtual public Linkstore //类：链队列（是链式存储的线性表的派生类）
{
private:
	PNode front; //队头指针
	PNode rear; //队尾指针
public:
	void init(); //创建一个空的队列
	void add(); //添加新的元素在队尾
	void delet(); //在队头删除元素
	void traverse(); //从队头开始遍历队列并打印
};
void Queue::init()
{
	front = rear = new node;
	front->next = NULL; //固定队头指针
	return;
}
void Queue::add()
{
	int num;
	cout << "Please input the number of elements you want to add : ";
	cin >> num;
	for (int i = 0; i < num;)
	{
		cout << "Element " << ++i << " : ";
		PNode p = new node;
		cin>>p->data;
		p->next = NULL;
		rear->next = p; //在队尾连接新节点
		rear = p; //队尾指针指向结点p,p成为新的队尾
	}
	return;
}
void Queue::delet()
{
	int num;
	cout << "Please input the number of elements you want to delete : ";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		PNode p = new node;
		p = front; //把队头地址赋给p
		front = p->next; //确定新的队头
		delete p;
	}
	return;
}
void Queue::traverse()
{
	PNode p; //申请指针可以在队列内移动 
	cout << "List-3 elements : ";
	for (p = front->next; p != rear->next; p = p->next)
		cout << p->data << ends;
	cout << endl;
	return;
}
int main()
{
	Linkstore * p;
	Link list1;
	Stack list2;
	Queue list3;
	p = &list1; //对单链表进行操作
	p->init();
	p->add();
	p->traverse();
	p->delet();
	p->traverse();
	p->insert();
	p->traverse();
	p = &list2; //对栈进行操作
	p->init();
	p->add();
	p->traverse();
	p->delet();
	p->traverse();
	p = &list3; //对队列进行操作
	p->init();
	p->add();
	p->traverse();
	p->delet();
	p->traverse();
	return 0;
}
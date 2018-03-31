#include<iostream>
using namespace std;
struct node                  //队列节点  
{
	int data;				 //数据域  
	node *next;              //指针域  
};

class asdasd				//基类
{
public:
	virtual int print() = 0;
};

class initStack :public asdasd	  //链栈
{
public:
	initStack(){ top = NULL; }	  //初始化链栈调用构造函数
	int Push(int data);			  //入栈
	int Pop();					  //出栈 
	int print();				  //打印链栈内元素
	~initStack();				  //析构,销毁
	node *top;					  //栈顶指针
};

initStack::~initStack()
{
	node *p = NULL;
	while (top)					  //循环释放节点
	{
		p = top->next;
		delete top;
		top = p;
	}
}

int initStack::Push(int data)	  //进栈
{
	node *snew = new node;        //创建新节点
	snew->data = data;            //新节点赋值
	snew->next = top;             //新栈顶指向旧栈顶
	top = snew;					  //top指向新栈顶
	return 1;
}

int initStack::Pop()			 //出栈操作Pop
{
	node *p;
	while (top)                  //循环释放节点
	{
		p = top;
		top = top->next;
		delete p;
	}
	return 1;
}

int initStack::print()			//打印链栈中元素
{
	node *p = top;
	while (p)					//栈不为空
	{
		cout << p->data << ends ;   //遍历打印栈中数据
		p = p->next;
	}
	return 1;
}

class initqueue :public asdasd		//链队列
{
public:
	initqueue();                    //构造函数  
	void push(int var);				//入队  
	void pop();						//出队  
	int front();					//取对头元素,对头不变化  
	int isEmpty();					//判空.head=tail=NULL时队列为空  
	int print();				    //打印链队列内元素
	~initqueue();                   //析构函数  

private:
	node * head;				    //对头指针  
	node *tail;						//队尾指针  
};

initqueue::initqueue()
{
	head = NULL;					//head=tail=NULL时队列为空  
	tail = NULL;
}

initqueue::~initqueue()
{
	node *ptr = NULL;
	while (head != NULL)
	{
		ptr = head->next;
		delete head;
		head = ptr;
	}
}

void initqueue::push(int var)
{
	node *ptr = new node;
	ptr->data = var;
	ptr->next = NULL;
	if (tail != NULL)
		tail->next = ptr;       //不是入队的第一个节点  
	else
		head = ptr;             //如果是入队的第一个节点  
	tail = ptr;
}

void initqueue::pop()
{
	node *ptr = head->next;
	delete head;
	head = ptr;
	if (head == NULL)         //head时要将tail也赋为NULL  
		tail = NULL;
}

int initqueue::front()
{
	return head->data;
}

int initqueue::isEmpty()
{
	return head == NULL && tail == NULL;
}

int initqueue::print()			//打印链队列中元素
{
	node *p = head;
	while (p)					//队列不为空
	{
		cout << p->data << ends;   //遍历打印队列中数据
		p = p->next;
	}
	return 1;
}

class LinkList :public asdasd		//链表
{
public:
	LinkList() { head = NULL; }
	int Length();
	int Insert(int i, int e);
	int print();				   //打印链表列内元素
	~LinkList();
private:
	node * head;
};

LinkList::~LinkList()				//析构函数
{
	node *p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}

int LinkList::Length()				//获取链表长度
{
	node *p = head;
	int len = 0;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

int LinkList::Insert(int i, int e)
{
	node *p = head, *s;
	int j = 0;
	if (i == 0)				//头插法
	{
		s = new node;
		s->data = e;
		s->next = p;
		head = s;
		return 0;
	}
	while (p&&j < i - 1)			//从中间插入元素
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;				//到队尾了
	s = new node;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 0;
}

int LinkList::print()			//打印链表中元素
{
	node *p = head;
	while (p)					//链表不为空
	{
		cout << p->data << ends;   //遍历打印链表中数据
		p = p->next;
	}
	return 1;
}

int main()
{
	initStack ls;				//定义链栈变量
	initqueue exp;				//定义链队列
	LinkList li;				//定义链表

	int i;		
	for (i = 5; i >=0; i--)		//入栈
		ls.Push(i);
	ls.print();					//链栈输出
	ls.Pop();
	cout << endl;

	for (i = 0; i<5; i++)
		exp.push(i);
	exp.print();				//链队列输出
	for (i = 0; i<5; i++)
		if (!exp.isEmpty())
			exp.pop();
	cout << endl;
	
	li.Insert(0, 5);
	li.Insert(1, 4);
	li.Insert(2, 12);
	li.Insert(3, 5);
	li.Insert(3, 6);
	li.Insert(1, 7);
	cout << "链表长度" << li.Length() << endl;
	li.print();					//链表输出
	cout << endl;

	return 0;
}
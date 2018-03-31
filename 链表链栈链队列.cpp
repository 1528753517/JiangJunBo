#include<iostream>
using namespace std;
struct node                  //���нڵ�  
{
	int data;				 //������  
	node *next;              //ָ����  
};

class asdasd				//����
{
public:
	virtual int print() = 0;
};

class initStack :public asdasd	  //��ջ
{
public:
	initStack(){ top = NULL; }	  //��ʼ����ջ���ù��캯��
	int Push(int data);			  //��ջ
	int Pop();					  //��ջ 
	int print();				  //��ӡ��ջ��Ԫ��
	~initStack();				  //����,����
	node *top;					  //ջ��ָ��
};

initStack::~initStack()
{
	node *p = NULL;
	while (top)					  //ѭ���ͷŽڵ�
	{
		p = top->next;
		delete top;
		top = p;
	}
}

int initStack::Push(int data)	  //��ջ
{
	node *snew = new node;        //�����½ڵ�
	snew->data = data;            //�½ڵ㸳ֵ
	snew->next = top;             //��ջ��ָ���ջ��
	top = snew;					  //topָ����ջ��
	return 1;
}

int initStack::Pop()			 //��ջ����Pop
{
	node *p;
	while (top)                  //ѭ���ͷŽڵ�
	{
		p = top;
		top = top->next;
		delete p;
	}
	return 1;
}

int initStack::print()			//��ӡ��ջ��Ԫ��
{
	node *p = top;
	while (p)					//ջ��Ϊ��
	{
		cout << p->data << ends ;   //������ӡջ������
		p = p->next;
	}
	return 1;
}

class initqueue :public asdasd		//������
{
public:
	initqueue();                    //���캯��  
	void push(int var);				//���  
	void pop();						//����  
	int front();					//ȡ��ͷԪ��,��ͷ���仯  
	int isEmpty();					//�п�.head=tail=NULLʱ����Ϊ��  
	int print();				    //��ӡ��������Ԫ��
	~initqueue();                   //��������  

private:
	node * head;				    //��ͷָ��  
	node *tail;						//��βָ��  
};

initqueue::initqueue()
{
	head = NULL;					//head=tail=NULLʱ����Ϊ��  
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
		tail->next = ptr;       //������ӵĵ�һ���ڵ�  
	else
		head = ptr;             //�������ӵĵ�һ���ڵ�  
	tail = ptr;
}

void initqueue::pop()
{
	node *ptr = head->next;
	delete head;
	head = ptr;
	if (head == NULL)         //headʱҪ��tailҲ��ΪNULL  
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

int initqueue::print()			//��ӡ��������Ԫ��
{
	node *p = head;
	while (p)					//���в�Ϊ��
	{
		cout << p->data << ends;   //������ӡ����������
		p = p->next;
	}
	return 1;
}

class LinkList :public asdasd		//����
{
public:
	LinkList() { head = NULL; }
	int Length();
	int Insert(int i, int e);
	int print();				   //��ӡ��������Ԫ��
	~LinkList();
private:
	node * head;
};

LinkList::~LinkList()				//��������
{
	node *p = head;
	while (head)
	{
		p = head;
		head = head->next;
		delete(p);
	}
}

int LinkList::Length()				//��ȡ������
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
	if (i == 0)				//ͷ�巨
	{
		s = new node;
		s->data = e;
		s->next = p;
		head = s;
		return 0;
	}
	while (p&&j < i - 1)			//���м����Ԫ��
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;				//����β��
	s = new node;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 0;
}

int LinkList::print()			//��ӡ������Ԫ��
{
	node *p = head;
	while (p)					//����Ϊ��
	{
		cout << p->data << ends;   //������ӡ����������
		p = p->next;
	}
	return 1;
}

int main()
{
	initStack ls;				//������ջ����
	initqueue exp;				//����������
	LinkList li;				//��������

	int i;		
	for (i = 5; i >=0; i--)		//��ջ
		ls.Push(i);
	ls.print();					//��ջ���
	ls.Pop();
	cout << endl;

	for (i = 0; i<5; i++)
		exp.push(i);
	exp.print();				//���������
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
	cout << "������" << li.Length() << endl;
	li.print();					//�������
	cout << endl;

	return 0;
}
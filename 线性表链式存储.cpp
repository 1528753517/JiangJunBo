#include<iostream>
using namespace std;
typedef struct node //��ʽ�洢����Ҫ�õ��Ľ��
{
	int data;
	node* next;
}Node,*PNode;
class List //�ࣺ���Ա�
{
protected:
	int elem; //����Ԫ��
};
class Sqstore :virtual public List //�ࣺ˳��洢�����Ա������Ա�������ࣩ
{
};
class Linkstore :virtual public List //�ࣺ��ʽ�洢�����Ա������Ա�������ࣩ
{
public: //��Ϊ���麯��������
	virtual void init() = 0; //��ʼ��
	virtual void add() = 0; //����
	virtual void delet() = 0; //ɾ��
	virtual void traverse() = 0; //����
	virtual void insert()
	{
		//���루�����������У�
		return;
	}
};
class Link :virtual public Linkstore //�ࣺ����������ʽ�洢�����Ա�������ࣩ
{
private:
	PNode head; //ͷ�ڵ�
	PNode phead; //ͷָ��
public:
	void init(); //������ĳ�ʼ��
	void add(); //β�巨ʵ�ִ���������
	void delet(); //�ڵ�������ɾ���ض�ֵ�Ľ��
	void insert(); //�ڵ������в����ض�λ�õĽ��
	void traverse(); //������������ӡ
};
void Link::init()
{
	phead = head = new node; //ͷָ��ָ��ͷ�ڵ㣬ͨ��ͷָ���ӶԵ�������в���
	phead->next = NULL;
	return;
}
void Link::add()
{
	int len;
	cout << "Please input the length of link-list : "; //���嵥����ĳ���
	cin >> len;
	cout << "List-1 : ";
	for (int i = 0; i < len; i++) //ÿ����һ���µĽ�㣬ͷָ��ָ���½ڵ�
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
	PNode L = new node; //���ڱ���������
	PNode p = new node; //����ɾ�����������
	PNode q = new node; //����ɾ������ָ��
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
	PNode p = new node; //������Ľ��
	PNode q = new node; //���ڱ���������
	PNode L = new node; //���ڲ���������
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
class Stack :virtual public Linkstore //�ࣺ��ջ������ʽ�洢�����Ա�������ࣩ
{
private:
	PNode top; //ջ��ָ��
	PNode base; //ջ��ָ��
public:
	void init(); //����һ���յ�ջ
	void add(); //��ջ����
	void delet(); //��ջ����
	void traverse(); //��ջ����ʼ��������ӡ
};
void Stack::init()
{
	base = new node;
	base->next = NULL; //�̶�ջ��
	top = base; //ջ��ָ��ָ��ջ�ף���ջΪ��
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
		PNode p = new node; //����һ�����
		cin >> p->data;
		p->next = top; //��ý���next��Ϊջ����ǰ��
		top = p; //ջ��ָ��ָ��p��p��Ϊ�µ�ջ��
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
		p = top; //��ջ����ַ����p
		top = top->next; //ջ��ָ��ָ��ջ����ǰһ�����
		delete p; //�ͷ�ɾ���Ľ����ռ���ڴ�ռ�
	}
	return;
}
void Stack::traverse()
{
	PNode p; //����ָ�������ջ���ƶ� 
	cout << "List-2 elements : ";
	for (p = top; p->next != NULL; p = p->next)
		cout << p->data << ends;
	cout << endl;
	return;
}
class Queue :virtual public Linkstore //�ࣺ�����У�����ʽ�洢�����Ա�������ࣩ
{
private:
	PNode front; //��ͷָ��
	PNode rear; //��βָ��
public:
	void init(); //����һ���յĶ���
	void add(); //����µ�Ԫ���ڶ�β
	void delet(); //�ڶ�ͷɾ��Ԫ��
	void traverse(); //�Ӷ�ͷ��ʼ�������в���ӡ
};
void Queue::init()
{
	front = rear = new node;
	front->next = NULL; //�̶���ͷָ��
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
		rear->next = p; //�ڶ�β�����½ڵ�
		rear = p; //��βָ��ָ����p,p��Ϊ�µĶ�β
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
		p = front; //�Ѷ�ͷ��ַ����p
		front = p->next; //ȷ���µĶ�ͷ
		delete p;
	}
	return;
}
void Queue::traverse()
{
	PNode p; //����ָ������ڶ������ƶ� 
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
	p = &list1; //�Ե�������в���
	p->init();
	p->add();
	p->traverse();
	p->delet();
	p->traverse();
	p->insert();
	p->traverse();
	p = &list2; //��ջ���в���
	p->init();
	p->add();
	p->traverse();
	p->delet();
	p->traverse();
	p = &list3; //�Զ��н��в���
	p->init();
	p->add();
	p->traverse();
	p->delet();
	p->traverse();
	return 0;
}
#include <iostream>
using namespace std;

class LinearList//˳��� 
{
	public:
		virtual void in(int)=0;
		virtual void out(int)=0;
};

class SequenceList:public LinearList//˳����� 
{
	public:
		virtual void in(int);
		virtual void out(int);
		SequenceList();
	private:
		int *data;
		int length;
};

SequenceList::SequenceList()//˳���Ĺ��캯�� 
{	
	data=new int[10];
	for(int i=0;i<10;i++)
		data[i]=1;
	length=10;
}

void SequenceList::in(int n)//˳������ 
{	
	cout<<"����ڼ�����";
	int i;
	cin>>i;
	
	if(i<1||i>length+1)
		return;
	if(length>10)
		return;
	int *q=&data[i-1];
	for(int*p=&data[length-1];p>=q;--p)
		*(p+1)=*p;
	*q=n;
	++length;
	for(int j=0;j<10;j++)
		cout<<data[j]<<" ";
	cout<<endl;
}

void SequenceList::out(int n)//˳���ɾ�� 
{		
	cout<<"ɾ���ڼ�����";
	int i;
	cin>>i;
	
	int *p;
	if(i<1||i>length)
		return;
	p=&data[i-1];
	int*q=data+length-1;
	for(++p;p<=q;++p)
		*(p-1)=*p;
	--length;
	for(int j=0;j<10;j++)
		cout<<data[j]<<" ";
	cout<<endl;
}

typedef struct node//�������� 
{
	int data;
	struct node *next;
}NODE;

class LinkList:public LinearList//�������� 
{
	public:
		virtual void in(int);
		virtual void out(int);
	private:
		NODE*LL;
};

void LinkList::in(int n)//��������� 
{	
	NODE *h,*p,*q;
	h=p=q=new NODE;
	for(int count=1;count<n;count++)//Ĭ������5������ֵΪ1�������� 
	{
		p=new NODE;
		q->next=p;
		q=p;
		q->data=1;
		q->next=NULL;
	}
	LL=h;
	
	int num;
	cout<<"�����ĸ�����:";
	cin>>num;
	int i;
	cout<<"�����ĸ�λ��:";
	cin>>i;
	
	p=LL;//������� 
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)
		return;
	q=new NODE;
	q->data=num;
	q->next=p->next;
	p->next=q;
	
	p=h->next;//��� 
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void LinkList::out(int n)//������ɾ�� 
{	
	int i;
	cout<<"ɾ���ĸ�λ��:";
	cin>>i;
	
	NODE*p=LL;//ɾ������ 
	int j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!(p->next)||j>i-1)
		return;
	NODE*q=p->next;
	p->next=q->next;
	delete q;
	
	p=LL->next;//��� 
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

typedef struct line//���� 
{
	int data;
	struct line *next;
}LINE;

class Queue:public LinkList//������ 
{
public:
	void in(int);
	void out(int);
private:
	LINE*head;
	LINE*tail;
};

void Queue::in(int n)//�����
{	
	cout<<"����5����:" ;
	head = tail = new LINE;
	if (!head)
		return;
	head->next = NULL;
	int num;
	for (int i = 0; i < n; i++)
	{	
		cin >> num;
		LINE*p = new LINE;
		p->data = num;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}
	return;
}

void Queue::out(int n)//������
{
	int num;
	for (int i = 0; i < n; i++)
	{
		if (head == tail)
			return;
		LINE*p = new LINE;
		p = head->next;
		num = p->data;
		cout << num <<" ";
		head->next = p->next;
		if (tail == p)
			tail = head;
		delete p;
	}
}

typedef struct stack//ջ 
{
	int data;
	struct stack * next;
} STACK;

class Stack:public LinkList//ջ�� 
{
	public:
		void in(int);
		void out(int);
	private:
		STACK*top;
};

void Stack::in(int n)//��ջ 
{	
	cout<<"����5������";
	int num;
	for(int i=0;i<n;i++)
	{	
		STACK*p=new STACK;
		cin>>num;
		p->data=num;
		p->next=top;
		top=p;
	}
} 

void Stack::out(int n)//��ջ 
{	
	int num; 
	for(int i=0;i<n;i++)
	{	
		STACK*p=new STACK;
		num=top->data;
		p=top;
		top=top->next;
		delete p;
		cout<<num<<" ";
	}
}

int main()
{	
	cout<<"1.����"<<"\n"<<"2.ջ"<<"\n"<<"3.����"<<"\n"<<"4.˳���"<<endl;
	char choice;
	cin>>choice;
	LinearList *LL;
	Stack S;
	Queue Q;
	LinkList L;
	SequenceList SL;
	switch(choice)
	{
		case'1':LL=&Q;LL->in(5);LL->out(5);break;
		case'2':LL=&S;LL->in(5);LL->out(5);break;
		case'3':LL=&L;LL->in(5);LL->out(5);break;
		case'4':LL=&SL;LL->in(5);LL->out(5);break;
	}
	return 0;
}

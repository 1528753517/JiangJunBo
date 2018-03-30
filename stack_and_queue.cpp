#include<iostream>
using namespace std;
//��������
typedef struct NODE
{
	int data;
	NODE *next;
}NODE;
//��������Ա�
class form
{
	;
};
//������
class linked:public form
{
public:
	int data;
	NODE *head;
	NODE *end;
	NODE *nowend;
	//�������캯��
	linked();
	//�����������
	int putout();
private:
	//��������
	void Add(int n);
	//����ɾ��
	void Del(int num);
	//�����޸�
	void Mod(int num, int n);
	//��������
	NODE* Che(int n);

};
//����
NODE* linked::Che(int n)
{
	NODE *prep = head;
	while (prep->next != NULL)
	{
		if (prep->data == n)
		{
			return prep;
		}
	}
	return NULL;
}
//�޸�
void linked::Mod(int num, int n)
{
	NODE *prep = head->next;
	for (int i = 0; i < num; i++)
		prep = prep->next;
	prep->data = n;


}
//����
void linked::Add(int n)
{
	NODE *prep = new NODE;
	prep->data = n;
	prep->next = nowend;
	nowend = prep;
	head->next = nowend;
	
	
}
//ɾ��
void linked::Del(int num)
{
	int i;
	NODE *prep = head;
	NODE *deld;
	NODE *pre2;
	for (i = 0; i < num-1; i++)
	{
		prep = prep->next;
	}
	deld = prep->next;
	pre2 = prep;
	prep = prep->next->next;
	pre2->next = prep;
	free(deld);


}

//�������
int linked::putout()
{
	NODE *prep;
	prep = head->next;
	if (prep->next == NULL)
	{
		return 0;
	}
	while (prep->next != NULL)
	{
		cout << prep->data << "  ";
		prep = prep->next;
	}
	return 1;
}
//���캯��
linked::linked()
{
	head = new NODE;
	end = new NODE;
	nowend = end;
	head->next = end;
	end->next = NULL;
}
//������
class Queue :public linked
{
public:
	//���캯��
	Queue()
	{
		head = new NODE;
		end = new NODE;
		nowend = head;
		head->next = end;
		end->next = NULL; 
	}
	//��������βѹ��Ԫ��
	void Push(int n);
	//����ɾ��������Ԫ��
	void Pop();
	//���ض�����Ԫ��ֵ
	int Front()
	{
		return(head->next->data);
	}
	//���ض���βԪ��ֵ
	int Back()
	{
		return(nowend->data);
	}



};
//ɾ��������Ԫ��
void Queue::Pop()
{
	NODE *del=head->next;
	NODE *prep = head->next->next;
	head->next = prep;
	free(del);
}

//����βѹ��Ԫ��
void Queue::Push(int n)
{
	NODE *prep = new NODE;
	prep->data = n;
	nowend->next = prep;
	prep->next = end;
	nowend = prep;
}

//ջ��
class Stack:public linked
{
public:
	//����ѹ��Ԫ��
	void Push(int n);
	//���캯��
	Stack() :linked(){}
	//��������ջ��Ԫ��
	int Top();
	//����ɾ��ջ��Ԫ��
	void Pop();


};
//ɾ��ջ��Ԫ��
void Stack :: Pop()
{
	NODE *prep = nowend->next;
	free(nowend);
	nowend = prep;
	head->next = prep;
	

}
//����ջ��Ԫ��
int Stack::Top()
{
	return(head->next->data);
}
//ѹ��Ԫ��
void Stack::Push(int n)
{
	NODE *prep = new NODE;
	prep->data = n;
	prep->next = nowend;
	nowend = prep;
	head->next = nowend;
}

//���������ڹ��ܲ���QAQ
int main()
{
	Stack p;
	Queue q;
	linked l;
	p.Push(12);
	p.Push(99);
	p.Pop();
	p.Push(888);
	
	cout << p.Top() << endl;
	p.putout();
	cout << endl;
	q.Push(100);
	q.Push(123);
	q.Pop();
	q.Push(999);
	q.putout();
	cout << "NEW" << endl;
	getchar();
	return 0;
}

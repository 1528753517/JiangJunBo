#include<iostream>
using namespace std;
//声明链节
typedef struct NODE
{
	int data;
	NODE *next;
}NODE;
//虚基类线性表
class form
{
	;
};
//链表类
class linked:public form
{
public:
	int data;
	NODE *head;
	NODE *end;
	NODE *nowend;
	//声明构造函数
	linked();
	//声明输出函数
	int putout();

};
//输出函数
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
//构造函数
linked::linked()
{
	head = new NODE;
	end = new NODE;
	nowend = end;
	head->next = end;
	end->next = NULL;
}
//队列类
class Queue :public linked
{
public:
	//构造函数
	Queue()
	{
		head = new NODE;
		end = new NODE;
		nowend = head;
		head->next = end;
		end->next = NULL; 
	}
	//声明队列尾压入元素
	void Push(int n);
	//声明删除队列首元素
	void Pop();
	//返回队列首元素值
	int Front()
	{
		return(head->next->data);
	}
	//返回队列尾元素值
	int Back()
	{
		return(nowend->data);
	}



};
//删除队列首元素
void Queue::Pop()
{
	NODE *del=head->next;
	NODE *prep = head->next->next;
	head->next = prep;
	free(del);
}

//队列尾压入元素
void Queue::Push(int n)
{
	NODE *prep = new NODE;
	prep->data = n;
	nowend->next = prep;
	prep->next = end;
	nowend = prep;
}

//栈类
class Stack:public linked
{
public:
	//声明压入元素
	void Push(int n);
	//构造函数
	Stack() :linked(){}
	//声明返回栈顶元素
	int Top();
	//声明删除栈顶元素
	void Pop();


};
//删除栈顶元素
void Stack :: Pop()
{
	NODE *prep = nowend->next;
	free(nowend);
	nowend = prep;
	head->next = prep;
	

}
//返回栈顶元素
int Stack::Top()
{
	return(head->next->data);
}
//压入元素
void Stack::Push(int n)
{
	NODE *prep = new NODE;
	prep->data = n;
	prep->next = nowend;
	nowend = prep;
	head->next = nowend;
}

//主函数用于功能测试QAQ
int main()
{
	Stack p;
	Queue q;
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
	getchar();
	return 0;
}

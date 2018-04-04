#include<iostream>
#include<stack>
using namespace std;
//声明链节
typedef struct NODE
{
	char data;
	NODE *next;
}NODE;
//链表类
class linked
{
public:
	NODE *head;
	NODE *end;
	NODE *nowend;
	//声明构造函数
	linked();
	//声明输出函数
	int putout();
	//声明增加
	void Add(char n);

};
//增加
void linked::Add(char n)
{
	NODE *prep = new NODE;
	prep->data = n;
	prep->next = end;
	nowend->next= prep;
	nowend = prep;


}
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
	nowend = head;
	head->next = end;
	end->next = NULL;

}
//计算器类
class Calculator
{
public:
	//定义构造函数
	Calculator();
	//定义检测数字
	int CheckNumber(char a);
	//定义判断长数字函数
	int CheckNumber_s(NODE **Start);
	//定义判断是否为符号
	int CheckSymble(char a);
	//定义2数字计算函数
	int Count(int a, int b, char sym);
	//定义长式子计算函数
	int Counts(NODE**p, char flag);
	//记得最后改回私有**（暂时方便测试）**
	linked data;
	

};
//长式子计算函数
int Calculator::Counts(NODE**p, char flag)
{
	stack<int>nums;
	stack<char>syms;
	NODE *prep = *p;
	syms.push('#');
	//碰到flag结束
	while (prep->data !=flag)
	{
		
		if (CheckNumber(prep->data))//如果是数字则入栈
		{
			int c;
			c = CheckNumber_s(&prep);
			cout << "数字入栈  " << c << endl;
	
			nums.push(c);
		}
		else if (int fflag=CheckSymble(prep->data))//如果是符号
		{
			if (fflag == 1)//出现括号则递归调用
			{
				prep = prep->next;
				nums.push(Counts(&prep, ')'));
			}
			else if (fflag==3)//优先级高于栈顶
			{
				
				//else//否则检测下一个数字计算后入栈
				{
					int a, b;
					char c;
					a = nums.top();
					nums.pop();
					c = prep->data;
					prep = prep->next;
					if (prep->data == '(')//如果下一个是括号
					{
						prep = prep->next;
						b=Counts(&prep, ')');
					}
					else 
					{
						b = CheckNumber_s(&prep);
					}
					nums.push(b=Count(a, b, c));//b=***
					cout << "计算入栈  "<<b<<endl;
				}
			}
			else//优先级低于栈顶或同级直接入栈
			{
				char b;
				syms.push(b=prep->data);
				prep = prep->next;
				cout << "直接入栈  "<<b<<endl;
			}
		}
	}
	//至此两个栈中元素可顺序运算
	cout << "顺序计算  ";
	while (syms.top() != '#')
	{
		int a, b;
		char c;
		a = nums.top();
		nums.pop();
		b = nums.top();
		nums.pop();
		c = syms.top();
		syms.pop();
		nums.push(Count(a, b, c));


	}
	*p = prep->next;
	cout<< (nums.top())<<endl;
	return(nums.top());

}
//2数字计算函数
int Calculator::Count(int a, int b, char sym)
{
	if (sym == '+')
		return (a + b);
	else if (sym == '-')
		return (a - b);
	else if (sym == '*')
		return(a*b);
	else if (sym == '/')
		return(a / b);
	else
		return 0;
}
//判断是否为符号返回优先级
int Calculator::CheckSymble(char a)
{
	if (a == '+' || a == '-')
		return 4;
	else if (a == '*' || a == '/')
		return 3;
	else if (a == '(' || a == ')')
		return 1;
	else if (a == '#')
		return 2;
	else
		return 0;
}
//判断长数字函数
int Calculator::CheckNumber_s(NODE **Start)
{
	NODE *p, *q;
	int b=1,num=0;
	if (CheckNumber((*Start)->data))
	{
		p = q = *Start;
		while (CheckNumber(q->next->data))
		{
			q = q->next;
			b*=10;
		}
		for (; b != 0; b /= 10)
		{
			num += b*(p->data-48);
			p = p->next;
		}
		*Start = p;
		return num;

	}
	else
	{ 
		cout << "没检测到数字" << endl;
		return 0;
	}
		
}
//判断数字
int Calculator::CheckNumber(char a)
{
	if ((int)a >= (int)'0' && (int)a <= (int)'9')
		return 1;
	else
		return 0;

}


//构造函数
Calculator::Calculator()
{
	char prep='p';
	data.Add('#');
	while (prep != '#')
	{
		cin >> prep;
		data.Add(prep);
	}
	cout << "输入内容：" << endl;
	data.putout();//**测试**
}
int main()
{
	int p;
	cout << "请输入标准的数学算式，用 # 结束" << endl;
	Calculator New;
	p=New.Counts(&New.data.head->next->next,'#');
	cout<<"结果为" << p << endl;
	getchar();
	getchar();



}


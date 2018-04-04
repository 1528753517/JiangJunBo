#include <iostream>
using namespace std;

template<class type>
class stack
{	
	protected:
		class node
		{	
			public:
				type data;
				node*next;
		}*top;
	public:
		stack();
		~stack();
		bool empty();//判断是否为空
		bool get_top(type&);//取栈顶元素
		void push(type);//入栈
		void pop(type&);//出栈 	
		friend int evaluate();	
};

template<class type>
stack<type>::stack()
{                   
		top=new node;
		top=NULL;
}

template<class type>
stack<type>::~stack()
{
	node*p;
	while(top)
	{
		p=top;
		top=top->next;
		delete p;
	}
}

template<class type>
bool stack<type>::empty()
{
	if(top)
		return true;
	return false;
}

template<class type>
bool stack<type>::get_top(type&data)
{
	if(!empty())
		{
			data=top->data;
			return true;
		}
	return false;
}

template<class type>
void stack<type>::push(type data)
{
	top->data=data;
	top=top->next;
}

template<class type>
void stack<type>::pop(type&e)
{
	node*p;
	p=top;
	e=top->data;
	top=top->next;
	delete p;
}

bool checknum(char c)//判断数字
{
	if(c>='0'&&c<=9)
		return true;
	return false;
}

char precede(char c1,char c2)//判断运算符优先级 
{
	int m,n;
	if(c1=='+'||c1=='-')m=3;
	if(c1=='*'||c1=='/')m=5;
	if(c1=='(')m=1;
	if(c1==')')m=7;
	if(c1=='#')m=0;
	if(c1=='+'||c1=='-')n=2;
	if(c1=='*'||c1=='/')n=4;
	if(c1=='(')n=6;
	if(c1==')')n=1;
	if(c1=='#')n=0;
	
	if(m>n)
		return '>';
	else if(m==n)
		return '=';
	else
		return '<';
}

int run(char c,int a,int b)
{
	switch(c)
	{
		case'+':return a+b;break;
		case'-':return a-b;break;
		case'*':return a*b;break;
		case'/':return a/b;break;
	}
}

int evaluate()
{	
	stack<char>stack_char;
	stack_char.push('#');
	stack<int>stack_int;
	char c,d,e;
	int a,b;
	cin>>c;
	while(c!='#'||(stack_char.get_top(e)&&e!='#'))
	{	
		stack_char.get_top(e);
		if(checknum(c))
			{
				stack_int.push(c);
				cin>>c;
			}
		else
			switch(precede(e,c))
			{
				case'<':stack_char.push(c);cin>>c;break;
				case'=':stack_char.pop(d);cin>>c;break;
				case'>':stack_char.pop(d);stack_int.pop(a);stack_int.pop(b);stack_int.push(run(d,a,b));break;
			}
	}
	int x;
	return stack_int.get_top(x);
}


int main()
{	
	evaluate();
	return 0;
}

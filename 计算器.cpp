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
		type get_top();
		void push(type);
		type pop();	
		friend int evaluate();	
};

template<class type>
stack<type>::stack()
{                   
		top=new node;
}

template<class type>
type stack<type>::get_top()
{	
	if(top)	
		return top->data;
}

template<class type>
void stack<type>::push(type data)
{	
	node*p;
	p=new node;
	p->data=data;
    p->next=top;
    top=p;
}

template<class type>
type stack<type>::pop()
{	
	type data;
	node*p;
	p=new node;
	p=top;
	data=top->data;
	top=top->next;
	delete p;
	return data;
}

int ln(char ch)
{
    return(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='#');
}

char precede(char c1,char c2)
{
	int i=0,j=0;
    static char a[49]={ '>', '>', '<', '<', '<', '>', '>',
                        '>', '>', '<', '<', '<', '>', '>',
                        '>', '>', '>', '>', '<', '>', '>',
                        '>', '>', '>', '>', '<', '>', '>',
                        '<', '<', '<', '<', '<', '=', '!',
                        '>', '>', '>', '>', '!', '>', '>',
                        '<', '<', '<', '<', '<', '!', '='};
    switch(c1)
    {
    case '+' :  i=0;break;
    case '-' :  i=1;break;
    case '*' :  i=2;break;
    case '/' :  i=3;break;
    case '(' :  i=4;break;
    case ')' :  i=5;break;
    case '#' :  i=6;break;
    }
    switch(c2)
    {
    case '+' :  j=0;break;
    case '-' :  j=1;break;
    case '*' :  j=2;break;
    case '/' :  j=3;break;
    case '(' :  j=4;break;
    case ')' :  j=5;break;
    case '#' :  j=6;break;
    }
    return (a[7*i+j]);
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
	stack<char> stack_char;
	stack<int> stack_int;
	stack_char.push('#');
	int a,b;
	char c,theta,x;
	cin>>c;
	while(c!='#'||(stack_char.get_top()!='#'))	
		if(!ln(c))
			{	
				stack_int.push(c-'0');
				cin>>c;
			}
		else
		{
			switch(precede(stack_char.get_top(),c))
			{
				case'<':stack_char.push(c);cin>>c;break;
				case'=':x=stack_char.pop();cin>>c;break;
				case'>':theta=stack_char.pop();a=stack_int.pop();b=stack_int.pop();stack_int.push(run(theta,b,a));break;
			}
		}
	return stack_int.get_top();
}

int main()
{	
	cout<<evaluate();
	return 0;
}

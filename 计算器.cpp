#include <iostream>
#include<stack>
using namespace std;

int check(char ch)
{
    return(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='#');
}

char precede(char c1,char c2)
{
	int i=0,j=0;
    static char array[49]={ '>', '>', '<', '<', '<', '>', '>',
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
    return (array[7*i+j]);
}

 int run(int a,char c,int b) 
{
    switch(c)
    {
    case '+' :  return (a+b);
    case '-' :  return (a-b);
    case '*' :  return (a*b);
    case '/' :  return (a/b);
    }
    return 0;
}

int evaluate()
{	
	stack<char> stack_char;
	stack<int> stack_int;
	stack_char.push('#');
	int a,b;
	char c,theta;
	cin>>c;
	while(c!='#'||stack_char.top()!='#')	
	{
		if(!check(c))
			{	
				stack_int.push(c-'0');
				cin>>c;
			}
		else
		{
			switch(precede(stack_char.top(),c))
			{
				case'<':stack_char.push(c);cin>>c;;break;
				case'=':stack_char.pop();cin>>c;;break;
				case'>':theta=stack_char.top();stack_char.pop();
						a=stack_int.top();stack_int.pop();
						b=stack_int.top();stack_int.pop();
						stack_int.push(run(b,theta,a));break;
			}
		}
	}
	return stack_int.top();	
}

int main()
{	
	cout<<"ÊäÈëÀý×Ó:3+2*1#"<<endl; 
	cout<<evaluate();
	return 0;
}

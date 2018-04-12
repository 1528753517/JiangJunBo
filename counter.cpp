#include <iostream>
using namespace std;

struct figure//定义第一个栈---作为存放运算数的操作符 
{
	int datas[20];
	int top;
};

struct symbol_//定义第二个栈---作为存放运算符号的栈
{
	char symbol[20];
	int top;
};

class asdasd
{
public:
	void InitNum(figure *Num) { Num->top = -1; }//初始化运算数栈顶
	void InitSymbol(symbol_ *Symbol) { Symbol->top = -1; }//并且初始化运算符栈顶
	void PushNum(figure *Num, int x);//压一个数到栈顶
	void PushSymbol(symbol_ *Symbol, char ch);//压一个运算符到栈顶
	int PopNum(figure *Num);//将运算数从栈中读取出来
	char PopSymbol(symbol_ *Symbol);//将运算符从栈中取出来
	int GetNum(figure *Num);//取出相应的数
	char GetSymbol(symbol_ *Symbol);//取出相应运算符 
	short SymbolOrNum(char ch);//判断输入的符号是那些符号
	char Priority(char inputnum, char ch);//判断符号优先级运算
	int Calculate(int num1, char ch, int num2);//计算结果
	int MainCalc();//获取用户输入，并且进行计算

};

void asdasd::PushNum(figure *Num, int x)//压一个数到栈顶
{
	Num->top++;
	Num->datas[Num->top] = x;
}

void asdasd::PushSymbol(symbol_ *Symbol, char ch)//压一个运算符到栈顶
{
	Symbol->top++;
	Symbol->symbol[Symbol->top] = ch;
}

int asdasd::PopNum(figure *Num)//将运算数从栈中读取出来
{
	int num;
	num = Num->datas[Num->top];
	Num->top--;
	return num;
}

char asdasd::PopSymbol(symbol_ *Symbol)//将运算符从栈中取出来
{
	char ch;
	ch = Symbol->symbol[Symbol->top];
	Symbol->top--;
	return ch;
}

int asdasd::GetNum(figure *Num)//取出相应的数
{
	return Num->datas[Num->top];
}

char asdasd::GetSymbol(symbol_ *Symbol)//取出相应运算符 
{
	return Symbol->symbol[Symbol->top];
}

short asdasd::SymbolOrNum(char ch)//判断输入的符号是那些符号
{
	//判断所有需要用的操作符 包括 + - * / ( ) \n   
	if (ch == '+' || ch == '-' || ch == '*'
		|| ch == '/' || ch == '(' || ch == ')' || ch == '\n') return 1;

	else return 0;
}

char asdasd::Priority(char inputnum, char ch)//判断符号优先级运算
{
	switch (inputnum)
	{
		//加减在同一个优先级上   
	case '+':
	case '-':
	{
		if (ch == '+' || ch == '-') return '>';
		else if (ch == '*' || ch == '/') return '<';
		else if (ch == '(') return '<';
		else if (ch == ')') return '>';
		else return '>';
	}
	break;

	//乘除在同一优先级   
	case '*':
	case '/':
	{
		if (ch == '+' || ch == '-') return '>';
		else if (ch == '*' || ch == '/') return '>';
		else if (ch == '(') return '<';
		else if (ch == ')') return '>';
		else return '>';
	}
	break;

	//括号在所有优先级以上   
	case '(':
	{
		if (ch == ')') return '=';
		else return '<';
	}
	break;
	case ')':
	{
		return '>';
	}
	break;
	case '\n':
	{
		if (ch == '\n') return '=';
		else return '<';
	}
	break;
	}
}

int asdasd::Calculate(int num1, char ch, int num2)//计算结果
{
	int result;
	switch (ch)
	{
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
	}
	return result;
}

int asdasd::MainCalc()//获取用户输入，并且进行计算
{
	//主函数进行计算   
	figure datas;
	symbol_ symbol;
	int num1, num2, result, num;
	char ch, sign;

	InitNum(&datas);
	InitSymbol(&symbol);

	PushSymbol(&symbol, '\n');//把回车计算的操作符放在栈中
	ch = getchar();
	while ((ch != '\n') || (GetSymbol(&symbol) != '\n'))
	{
		if (!SymbolOrNum(ch))
		{
			num = atoi(&ch);  //将字符转换为整数  
			ch = getchar();   //获取输入  
			while (!SymbolOrNum(ch))
			{
				num = num * 10 + atoi(&ch);
				ch = getchar();   //当没有输入回车时，继续获取输入  
			}
			PushNum(&datas, num);
		}
		else
		{
			switch (Priority(GetSymbol(&symbol), ch))
			{
				//判断优先级后进行计算   
			case '<':
				PushSymbol(&symbol, ch);
				ch = getchar();
				break;
			case '=':
				sign = PopSymbol(&symbol);
				ch = getchar();  //获取输入  
				break;
			case '>':
				sign = PopSymbol(&symbol);
				num2 = PopNum(&datas);
				num1 = PopNum(&datas);
				result = Calculate(num1, sign, num2);
				PushNum(&datas, result);
				break;

			}
		}
	}
	result = GetNum(&datas);
	return result;
}

int main()
{
	int a;
	asdasd result;
	a = result.MainCalc();
	cout << a << endl;//输出结果
	return 0;
}
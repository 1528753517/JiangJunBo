#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef struct nodeC
{
	char data;
	nodeC* next;
}NodeC, *PNodeC;
typedef struct nodeN
{
	double data;
	nodeN* next;
}NodeN, *PNodeN;
class Calculater
{
private:
	string formula1; //中缀表达式
	string formula2; //后缀表达式
	double result; //表达式的值
	PNodeC ctop; //栈顶指针（操作符）
	PNodeC cbase; //栈底指针（操作符）
	PNodeN ntop; //栈顶指针（操作数）
	PNodeN nbase; //栈顶指针（操作数）
public:
	void inputFormula(); //输入要计算的表达式
	void changeFormula(); //中缀表达式转换为后缀表达式
	void calculate(); //计算（按照后缀表达式的计算规则）
	void outputResult(); //输出最后的结果
	void initStackC(); //栈的初始化（操作符）
	void pushStackC(char c); //数据c入栈（操作符）
	char popStackC(); //出栈（操作符），最后返回出栈的数据字符
	int emptyStackC(); //判断栈是否为空（操作符），若是，则返回1，不是则返回0
	char getCtop(); //得到栈顶数据（操作符）
	void initStackN(); //栈的初始化（操作数）
	void pushStackN(double n); //数据n入栈（操作数）
	double popStackN(); //出栈（操作数），最后返回出栈的数据数字版
	double getNtop(); //得到栈顶数据（操作数）
};
void Calculater::inputFormula()
{
	cout << "\n\n\t* Please input formula : ";
	cin >> formula1;
	return;
}
void Calculater::changeFormula()
{
	string save;
	initStackC();
	for (int i = 0; i < formula1.length(); i++)
	{
		char c = formula1[i];
		if (c >= '0'&&c <= '9')
		{
			save = c;
			formula2.append(save);
		}
		else
		{
			formula2.append(" ");
			if (c == '(' || c == '*' || c == '/')
				pushStackC(c);
			else if (c == '+' || c == '-')
			{
				while (getCtop() == '+' || getCtop() == '-' || getCtop() == '*' || getCtop() == '/')
				{
					save = popStackC();
					formula2.append(save);
				}
				pushStackC(c);
			}
			else
			{
				while (getCtop() != '(')
				{
					save = popStackC();
					formula2.append(save);
				}
				popStackC();
			}
		}
	}
	while (!emptyStackC())
	{
		save = popStackC();
		formula2.append(save);
	}
	cout << "\n\t* After chage : " << formula2;
	return;
}
void Calculater::calculate()
{
	changeFormula();
	char c;
	double number, num;
	int n, k;
	initStackN();
	for (int i = 0; i < formula2.length(); i++)
	{
		number = 0;
		c = formula2[i];
		if (c>='0'&&c<='9') //数字的字符转为十进制的数字
		{
			for (n = i, k = 0; formula2[n] >= '0'&&formula2[n] <= '9'; n++, k++);
			for (k--; k >= 0; k--,i++)
			{
				num = formula2[i] - 48;
				number += pow(10, k)*num;
			}
			i--;
			pushStackN(number);
		}
		else if(c=='+')
		{
			number = popStackN() + popStackN();
			pushStackN(number);
		}
		else if (c == '-')
		{
			number = -(popStackN() - popStackN());
			pushStackN(number);
		}
		else if (c == '*')
		{
			number = popStackN() * popStackN();
			pushStackN(number);
		}
		else if(c=='/')
		{
			number = (1 / popStackN()) * popStackN();
			pushStackN(number);
		}
		else;
	}
	result = getNtop();
	return;
}
void Calculater::outputResult()
{
	cout << "\n\n\t* Formula = " << result << "\n\n\t";
	return;
}
void Calculater::initStackC()
{
	cbase = new nodeC;
	ctop = cbase;
	return;
}
void Calculater::pushStackC(char c)
{
	PNodeC p = new nodeC;
	p->data = c;
	p->next = ctop;
	ctop = p;
	return;
}
char Calculater::popStackC()
{
	char c;
	PNodeC p = new nodeC;
	p = ctop;
	c = p->data;
	ctop = ctop->next;
	delete p;
	return c;
}
int Calculater::emptyStackC()
{
	if (ctop == cbase)
		return 1;
	else
		return 0;
}
char Calculater::getCtop()
{
	return ctop->data;
}
void Calculater::initStackN()
{
	nbase = new nodeN;
	ntop = nbase;
	return;
}
void Calculater::pushStackN(double n)
{
	PNodeN p = new nodeN;
	p->data = n;
	p->next = ntop;
	ntop = p;
	return;
}
double Calculater::popStackN()
{
	double number;
	PNodeN p = new nodeN;
	p = ntop;
	number = p->data;
	ntop = ntop->next;
	delete p;
	return number;
}
double Calculater::getNtop()
{
	return ntop->data;
}
int main()
{
	Calculater formula;
	formula.inputFormula();
	formula.calculate();
	formula.outputResult();
	return 0;
}
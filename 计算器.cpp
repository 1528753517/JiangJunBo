#include <iostream>
using namespace std;

struct figure//�����һ��ջ---��Ϊ����������Ĳ����� 
{
	int datas[20];
	int top;
};

struct symbol_//����ڶ���ջ---��Ϊ���������ŵ�ջ
{
	char symbol[20];
	int top;
};

void InitNum(figure *Num)//��ʼ��������ջ��
{
	Num->top = -1;
}

void InitSymbol(symbol_ *Symbol)//���ҳ�ʼ�������ջ��
{
	Symbol->top = -1;
}

void PushNum(figure *Num, int x)//ѹһ������ջ��
{
	Num->top++;
	Num->datas[Num->top] = x;
}

void PushSymbol(symbol_ *Symbol, char ch)//ѹһ���������ջ��
{
	Symbol->top++;
	Symbol->symbol[Symbol->top] = ch;
}

int PopNum(figure *Num)//����������ջ�ж�ȡ����
{
	int num;
	num = Num->datas[Num->top];
	Num->top--;
	return num;
}

char PopSymbol(symbol_ *Symbol)//���������ջ��ȡ����
{
	char ch;
	ch = Symbol->symbol[Symbol->top];
	Symbol->top--;
	return ch;
}

int GetNum(figure *Num)//ȡ����Ӧ����
{
	return Num->datas[Num->top];
}

char GetSymbol(symbol_ *Symbol)//ȡ����Ӧ����� 
{
	return Symbol->symbol[Symbol->top];
}

short SymbolOrNum(char ch)//�ж�����ķ�������Щ����
{
	//�ж�������Ҫ�õĲ����� ���� + - * / ( ) \n   
	if (ch == '+' || ch == '-' || ch == '*'
		|| ch == '/' || ch == '(' || ch == ')' || ch == '\n') return 1;

	else return 0;
}

char Priority(char inputnum, char ch)//�жϷ������ȼ�����
{
	switch (inputnum)
	{
		//�Ӽ���ͬһ�����ȼ���   
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

	//�˳���ͬһ���ȼ�   
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

	//�������������ȼ�����   
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

int Calculate(int num1, char ch, int num2)//������
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

int MainCalc()//��ȡ�û����룬���ҽ��м���
{
	//���������м���   
	figure datas;
	symbol_ symbol;
	int num1, num2, result, num;
	char ch, sign;

	InitNum(&datas);
	InitSymbol(&symbol);

	PushSymbol(&symbol, '\n');//�ѻس�����Ĳ���������ջ��
	ch = getchar();
	while ((ch != '\n') || (GetSymbol(&symbol) != '\n'))
	{
		if (!SymbolOrNum(ch))
		{
			num = atoi(&ch);  //���ַ�ת��Ϊ����  
			ch = getchar();   //��ȡ����  
			while (!SymbolOrNum(ch))
			{
				num = num * 10 + atoi(&ch);
				ch = getchar();   //��û������س�ʱ��������ȡ����  
			}
			PushNum(&datas, num);
		}
		else
		{
			switch (Priority(GetSymbol(&symbol), ch))
			{
				//�ж����ȼ�����м���   
			case '<':
				PushSymbol(&symbol, ch);
				ch = getchar();
				break;
			case '=':
				sign = PopSymbol(&symbol);
				ch = getchar();  //��ȡ����  
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
	int result;
	result = MainCalc();   
	cout << result << endl;//������
	return 0;
}
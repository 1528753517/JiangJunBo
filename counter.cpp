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

class asdasd
{
public:
	void InitNum(figure *Num) { Num->top = -1; }//��ʼ��������ջ��
	void InitSymbol(symbol_ *Symbol) { Symbol->top = -1; }//���ҳ�ʼ�������ջ��
	void PushNum(figure *Num, int x);//ѹһ������ջ��
	void PushSymbol(symbol_ *Symbol, char ch);//ѹһ���������ջ��
	int PopNum(figure *Num);//����������ջ�ж�ȡ����
	char PopSymbol(symbol_ *Symbol);//���������ջ��ȡ����
	int GetNum(figure *Num);//ȡ����Ӧ����
	char GetSymbol(symbol_ *Symbol);//ȡ����Ӧ����� 
	short SymbolOrNum(char ch);//�ж�����ķ�������Щ����
	char Priority(char inputnum, char ch);//�жϷ������ȼ�����
	int Calculate(int num1, char ch, int num2);//������
	int MainCalc();//��ȡ�û����룬���ҽ��м���

};

void asdasd::PushNum(figure *Num, int x)//ѹһ������ջ��
{
	Num->top++;
	Num->datas[Num->top] = x;
}

void asdasd::PushSymbol(symbol_ *Symbol, char ch)//ѹһ���������ջ��
{
	Symbol->top++;
	Symbol->symbol[Symbol->top] = ch;
}

int asdasd::PopNum(figure *Num)//����������ջ�ж�ȡ����
{
	int num;
	num = Num->datas[Num->top];
	Num->top--;
	return num;
}

char asdasd::PopSymbol(symbol_ *Symbol)//���������ջ��ȡ����
{
	char ch;
	ch = Symbol->symbol[Symbol->top];
	Symbol->top--;
	return ch;
}

int asdasd::GetNum(figure *Num)//ȡ����Ӧ����
{
	return Num->datas[Num->top];
}

char asdasd::GetSymbol(symbol_ *Symbol)//ȡ����Ӧ����� 
{
	return Symbol->symbol[Symbol->top];
}

short asdasd::SymbolOrNum(char ch)//�ж�����ķ�������Щ����
{
	//�ж�������Ҫ�õĲ����� ���� + - * / ( ) \n   
	if (ch == '+' || ch == '-' || ch == '*'
		|| ch == '/' || ch == '(' || ch == ')' || ch == '\n') return 1;

	else return 0;
}

char asdasd::Priority(char inputnum, char ch)//�жϷ������ȼ�����
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

int asdasd::Calculate(int num1, char ch, int num2)//������
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

int asdasd::MainCalc()//��ȡ�û����룬���ҽ��м���
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
	int a;
	asdasd result;
	a = result.MainCalc();
	cout << a << endl;//������
	return 0;
}
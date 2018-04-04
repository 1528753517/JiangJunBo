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
	string formula1; //��׺���ʽ
	string formula2; //��׺���ʽ
	double result; //���ʽ��ֵ
	PNodeC ctop; //ջ��ָ�루��������
	PNodeC cbase; //ջ��ָ�루��������
	PNodeN ntop; //ջ��ָ�루��������
	PNodeN nbase; //ջ��ָ�루��������
public:
	void inputFormula(); //����Ҫ����ı��ʽ
	void changeFormula(); //��׺���ʽת��Ϊ��׺���ʽ
	void calculate(); //���㣨���պ�׺���ʽ�ļ������
	void outputResult(); //������Ľ��
	void initStackC(); //ջ�ĳ�ʼ������������
	void pushStackC(char c); //����c��ջ����������
	char popStackC(); //��ջ��������������󷵻س�ջ�������ַ�
	int emptyStackC(); //�ж�ջ�Ƿ�Ϊ�գ��������������ǣ��򷵻�1�������򷵻�0
	char getCtop(); //�õ�ջ�����ݣ���������
	void initStackN(); //ջ�ĳ�ʼ������������
	void pushStackN(double n); //����n��ջ����������
	double popStackN(); //��ջ��������������󷵻س�ջ���������ְ�
	double getNtop(); //�õ�ջ�����ݣ���������
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
		if (c>='0'&&c<='9') //���ֵ��ַ�תΪʮ���Ƶ�����
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
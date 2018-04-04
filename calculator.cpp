#include<iostream>
#include<stack>
using namespace std;
//��������
typedef struct NODE
{
	char data;
	NODE *next;
}NODE;
//������
class linked
{
public:
	NODE *head;
	NODE *end;
	NODE *nowend;
	//�������캯��
	linked();
	//�����������
	int putout();
	//��������
	void Add(char n);

};
//����
void linked::Add(char n)
{
	NODE *prep = new NODE;
	prep->data = n;
	prep->next = end;
	nowend->next= prep;
	nowend = prep;


}
//�������
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
//���캯��
linked::linked()
{
	head = new NODE;
	end = new NODE;
	nowend = head;
	head->next = end;
	end->next = NULL;

}
//��������
class Calculator
{
public:
	//���幹�캯��
	Calculator();
	//����������
	int CheckNumber(char a);
	//�����жϳ����ֺ���
	int CheckNumber_s(NODE **Start);
	//�����ж��Ƿ�Ϊ����
	int CheckSymble(char a);
	//����2���ּ��㺯��
	int Count(int a, int b, char sym);
	//���峤ʽ�Ӽ��㺯��
	int Counts(NODE**p, char flag);
	//�ǵ����Ļ�˽��**����ʱ������ԣ�**
	linked data;
	

};
//��ʽ�Ӽ��㺯��
int Calculator::Counts(NODE**p, char flag)
{
	stack<int>nums;
	stack<char>syms;
	NODE *prep = *p;
	syms.push('#');
	//����flag����
	while (prep->data !=flag)
	{
		
		if (CheckNumber(prep->data))//�������������ջ
		{
			int c;
			c = CheckNumber_s(&prep);
			cout << "������ջ  " << c << endl;
	
			nums.push(c);
		}
		else if (int fflag=CheckSymble(prep->data))//����Ƿ���
		{
			if (fflag == 1)//����������ݹ����
			{
				prep = prep->next;
				nums.push(Counts(&prep, ')'));
			}
			else if (fflag==3)//���ȼ�����ջ��
			{
				
				//else//��������һ�����ּ������ջ
				{
					int a, b;
					char c;
					a = nums.top();
					nums.pop();
					c = prep->data;
					prep = prep->next;
					if (prep->data == '(')//�����һ��������
					{
						prep = prep->next;
						b=Counts(&prep, ')');
					}
					else 
					{
						b = CheckNumber_s(&prep);
					}
					nums.push(b=Count(a, b, c));//b=***
					cout << "������ջ  "<<b<<endl;
				}
			}
			else//���ȼ�����ջ����ͬ��ֱ����ջ
			{
				char b;
				syms.push(b=prep->data);
				prep = prep->next;
				cout << "ֱ����ջ  "<<b<<endl;
			}
		}
	}
	//��������ջ��Ԫ�ؿ�˳������
	cout << "˳�����  ";
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
//2���ּ��㺯��
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
//�ж��Ƿ�Ϊ���ŷ������ȼ�
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
//�жϳ����ֺ���
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
		cout << "û��⵽����" << endl;
		return 0;
	}
		
}
//�ж�����
int Calculator::CheckNumber(char a)
{
	if ((int)a >= (int)'0' && (int)a <= (int)'9')
		return 1;
	else
		return 0;

}


//���캯��
Calculator::Calculator()
{
	char prep='p';
	data.Add('#');
	while (prep != '#')
	{
		cin >> prep;
		data.Add(prep);
	}
	cout << "�������ݣ�" << endl;
	data.putout();//**����**
}
int main()
{
	int p;
	cout << "�������׼����ѧ��ʽ���� # ����" << endl;
	Calculator New;
	p=New.Counts(&New.data.head->next->next,'#');
	cout<<"���Ϊ" << p << endl;
	getchar();
	getchar();



}


#include<iostream>
using namespace std;
int black[10]; //�����ڰ�
class Teacher //�ࣺ��ʦ 
{
protected:
	int homework[10]; //��Ŀ
public:
	void Assign1() //ͨ��д�ںڰ��ϸ�ѧ������ҵ
	{
		cout << "Please input 10 numbers(on blackboard) : ";
		for (int i = 0; i < 10; i++)
			cin >> black[i];
	}
	friend class StudentC; //��Cѧ������Ϊ��ʦ��һ����Ԫ�࣬ʹ��ѧ������ֱ�ӵõ���ʦ������Ŀ
};
class Student //���ࣺѧ��
{
protected:
	int notebook[10]; //��ҵ��
	int a[201]; //���õĸ�������֮һ
public:
	void Assist() //��a��ʼ��Ϊ0������ʹ��Ͱ����
	{
		for (int i = 0; i < 201; i++)
			a[i] = 0;
	}
	virtual void Method(int, int)//����ҵ�ķ�ʽ����ͬ��ѧ��ʹ�ò�ͬ�ķ�ʽ��
	{
		cout << "Finished by ..." << endl;
	}
};
class StudentA : virtual public Student //ѧ�������ࣺA
{
public:
	void Method(int, int);
};
void StudentA::Method(int i,int n) //ʹ��Ͱ����ķ�ʽ�������д�ڱʼǱ���
{
	for (i = 0; i < 10; i++)
	{
		notebook[i] = black[i];
		a[100 + notebook[i]] += 1;
	}
	for (i = 0; i < 201; i++)
		for (n = 0; n < a[i]; n++)
			cout << i - 100 << ends;
	cout << endl;
}
class StudentB : virtual public Student //ѧ��������B
{
public:
	void Method(int, int);
};
void StudentB::Method(int i, int j)//�ò�������ķ�ʽ�������д�ڱʼǱ���
{
	for (i = 0; i < 10; i++)
		notebook[i] = black[i];
	for (i = 1; i < 10; i++)
	{
		int temp = notebook[i];
		for (j = i - 1; j >= 0 && notebook[j] > temp; j--)
			notebook[j + 1] = notebook[j];
		notebook[j + 1] = temp;
	}
	for (i = 0; i < 10; i++)
		cout << notebook[i] << ends;
	cout << endl;
}
class StudentC
{
private:
	int left; //���õĸ�������֮һ
	int right; //���õĸ�������֮һ
	Teacher T; //ѧ��C����ʦ��T
public:
	StudentC()
	{
		left = 0;
		right = 9;
	}
	void Assign2() //Tֱ���յ���ʦ���õ���ҵ
	{
		cout << "Please input 10 numbers(firsthang) : ";
		for (int i = 0; i < 10; i++)
			cin >> T.homework[i];
	}
	void output()
	{
		for (int i = 0; i < 10; i++)
			cout << T.homework[i] << ends;
		cout << endl;
	}
	void Work(int, int);
};
void StudentC::Work(int left, int right) //ֱ��ʹ�ÿ����������ʦ����ҵ���
{
	int i, j, t, temp;
	if (left>right)
		return;
	temp = T.homework[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (T.homework[j] >= temp && i<j)
			j--;
		while (T.homework[i] <= temp && i<j)
			i++;
		if (i<j)
		{
			t = T.homework[i];
			T.homework[i] = T.homework[j];
			T.homework[j] = t;
		}
	}
	T.homework[left] = T.homework[i];
	T.homework[i] = temp;
	Work(left, i - 1);
	Work(i + 1, right);
}
int main()
{
	Teacher t;
	Student *p;
	StudentA a;
	StudentB b;
	StudentC c;
	t.Assign1(); //ʹ�ù����ڰ岼������
	p = &a; //A�Ľ��
	p->Assist();
	p->Method(0,0);
	p = &b; //B�Ľ��
	p->Method(0,0);
	c.Assign2(); //C���յ���ʦֱ�Ӳ��õ�����
	c.Work(0, 9);
	c.output();
	return 0;
}
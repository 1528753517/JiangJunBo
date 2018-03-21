#include<iostream>
using namespace std;
class Arraysort //���������һ������
{
protected:
	int a[10];
public:
	void GetArray()//����ĳ�ʼ��
	{
		cout << "Please input 10 numbers : ";
		for (int i = 0; i < 10; i++)
			cin >> a[i];
	}
	virtual void sort(int,int)//�麯���Ĵ���ʹ�����͵�ָ����Ե��ú��Ͱ�š����š����ŵ��㷨����
	{
		cout << "Sorting successful !" << endl;
	}
	void output()//�������������
	{
		int i;
		for (i = 0; i < 10; i++)
			cout << a[i] << ends;
		cout << endl;
	}
};
class Bucketsort:virtual public Arraysort //Ͱ����
{
private:
	int a1[201];
public:
	Bucketsort()//��a[1]��ʼ��Ϊ0������ʹ��Ͱ����
	{
		for (int i = 0; i < 201; i++)
			a1[i] = 0;
	}
	void sort(int,int);
};
void Bucketsort::sort(int i,int n)//Ͱ����ľ����㷨
{
	for (i=0; i<10; i++)
		a1[100 + a[i]] += 1;
	for (i = 0; i < 201; i++)
		for (n=0; n < a1[i]; n++)
			cout << i - 100 << ends;
	cout << endl;
}
class Insertionsort :virtual public Arraysort //��������
{
public:
	void sort(int,int);
};
void Insertionsort::sort(int i,int j)//��������ľ����㷨
{
	for (i = 1; i < 10; i++)
		for (j = i; j > 0; j--)
			if (a[j] < a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
}
class Quicksort :virtual public Arraysort //��������
{
private:
	int left;
	int right;
public:
	Quicksort()
	{
		left = 0;
		right = 9;
	}
	void sort(int,int);
};
void Quicksort::sort(int left,int right)//��������ľ����㷨
{
	int i, j, t, temp;
	if (left>right)
		return;
	temp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i<j)
			j--;
		while (a[i] <= temp && i<j)
			i++;
		if (i<j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	sort(left, i - 1);
	sort(i + 1, right);
}
int main()
{
	Arraysort* p;
	Bucketsort b;
	Insertionsort i;
	Quicksort q;
	p = &b;
	p->GetArray();
	p->sort(0,0);//����Ͱ�����㷨
	p = &i;
	p->GetArray();
	p->sort(0,0);
	p->output();//���ò��������㷨
	p = &q;
	p->GetArray();
	p->sort(0,9);//���ÿ��������㷨
	p->output();
	return 0;
}
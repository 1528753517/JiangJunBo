#include<iostream>
using namespace std;
class Arraysort //关于排序的一个基类
{
protected:
	int a[10];
public:
	void GetArray()//数组的初始化
	{
		cout << "Please input 10 numbers : ";
		for (int i = 0; i < 10; i++)
			cin >> a[i];
	}
	virtual void sort(int,int)//虚函数的存在使基类型的指针可以调用后边桶排、快排、插排的算法函数
	{
		cout << "Sorting successful !" << endl;
	}
	void output()//输出排序后的数组
	{
		int i;
		for (i = 0; i < 10; i++)
			cout << a[i] << ends;
		cout << endl;
	}
};
class Bucketsort:virtual public Arraysort //桶排序
{
private:
	int a1[201];
public:
	Bucketsort()//给a[1]初始化为0，方便使用桶排序
	{
		for (int i = 0; i < 201; i++)
			a1[i] = 0;
	}
	void sort(int,int);
};
void Bucketsort::sort(int i,int n)//桶排序的具体算法
{
	for (i=0; i<10; i++)
		a1[100 + a[i]] += 1;
	for (i = 0; i < 201; i++)
		for (n=0; n < a1[i]; n++)
			cout << i - 100 << ends;
	cout << endl;
}
class Insertionsort :virtual public Arraysort //插入排序
{
public:
	void sort(int,int);
};
void Insertionsort::sort(int i,int j)//插入排序的具体算法
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
class Quicksort :virtual public Arraysort //快速排序
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
void Quicksort::sort(int left,int right)//快速排序的具体算法
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
	p->sort(0,0);//调用桶排序算法
	p = &i;
	p->GetArray();
	p->sort(0,0);
	p->output();//调用插入排序算法
	p = &q;
	p->GetArray();
	p->sort(0,9);//调用快速排序算法
	p->output();
	return 0;
}
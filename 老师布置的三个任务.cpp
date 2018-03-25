#include<iostream>
using namespace std;
int black[10]; //公共黑板
class Teacher //类：老师 
{
protected:
	int homework[10]; //题目
public:
	void Assign1() //通过写在黑板上给学生传作业
	{
		cout << "Please input 10 numbers(on blackboard) : ";
		for (int i = 0; i < 10; i++)
			cin >> black[i];
	}
	friend class StudentC; //将C学生声明为老师的一个友元类，使得学生可以直接得到老师出的题目
};
class Student //父类：学生
{
protected:
	int notebook[10]; //作业本
	int a[201]; //可用的辅助工具之一
public:
	void Assist() //给a初始化为0，方便使用桶排序
	{
		for (int i = 0; i < 201; i++)
			a[i] = 0;
	}
	virtual void Method(int, int)//做作业的方式（不同的学生使用不同的方式）
	{
		cout << "Finished by ..." << endl;
	}
};
class StudentA : virtual public Student //学生的子类：A
{
public:
	void Method(int, int);
};
void StudentA::Method(int i,int n) //使用桶排序的方式完成任务并写在笔记本上
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
class StudentB : virtual public Student //学生的子类B
{
public:
	void Method(int, int);
};
void StudentB::Method(int i, int j)//用插入排序的方式完成任务并写在笔记本上
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
	int left; //可用的辅助工具之一
	int right; //可用的辅助工具之一
	Teacher T; //学生C的老师是T
public:
	StudentC()
	{
		left = 0;
		right = 9;
	}
	void Assign2() //T直接收到老师布置的作业
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
void StudentC::Work(int left, int right) //直接使用快速排序对老师的作业求解
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
	t.Assign1(); //使用公共黑板布置任务
	p = &a; //A的解答
	p->Assist();
	p->Method(0,0);
	p = &b; //B的解答
	p->Method(0,0);
	c.Assign2(); //C接收到老师直接布置的任务
	c.Work(0, 9);
	c.output();
	return 0;
}
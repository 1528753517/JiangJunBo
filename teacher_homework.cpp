#include<iostream>
#include<string>
using namespace std;
//基类people
class people
{
public:
	int homework[10];
	people(string n,int a[10]);//声明构造函数
	virtual void disply();//声明输出函数
	virtual void dohomework(int a[10]);//声明处理作业函数
private:
	string name;
};
//做作业 
void people::dohomework(int a[10])
{
	return;
}
//构造函数
people::people(string n,int a[10])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		homework[i] = a[i];
	}
	name = n;
}
//输出
void people::disply()
{
	int i;
	cout << "姓名:" << name << endl;
	cout <<"作业:" << endl;
	for (i = 0; i < 10; i++)
	{
		cout << homework[i] << " ";
	}
	cout << endl;
	

}
//派生快排学生 a
class student_a :public people
{
public:
	student_a(string n, int a[10]);//声明构造函数
	virtual void dohomework();//声明做作业函数
	void quickSort(int s[], int l, int r);//快速排序

};
//构造函数a
student_a::student_a(string n, int a[10]) :people(n, a)
{
	;
}
//快排做作业a
void student_a::dohomework ()
{
	quickSort(homework, 0, 9);
}
//派生插排学生b
class student_b :public people
{
public:
	//构造函数b
	student_b(string n,int a[10]):people(n,a)
	{
		;
	}
	//声明插入排序
	void insert(int arr[], int length);
	//做作业插入排序b
	virtual void dohomework()
	{
		insert(homework, 10);
	}
	
};
//派生桶排序学生c
class student_c :public people
{public:
	//构造函数c
	student_c(string n, int a[10]) :people(n, a)
	{
		;
	}
	//声明桶排序
	void barrel(int arr[], int length);
	//做作业桶排序c
	virtual void dohomework()
	{
		barrel(homework, 10);
	}
};
//【简单的（只针对正整数）】桶排序
void student_c::barrel(int arr[], int length)
{
	int j,flag=0;
	int bar[10000] = {0};
	for (int i = 0; i < length; i++)
	{
		bar[arr[i]]++;
	}
	for (int i = 0; i < 10000; i++)
	{
		if (bar[i] != 0)
		{
			for (j = 0; j< bar[i]; j++)
			{
				arr[flag] = i;
				flag++;
			}
		}
	}

}
//快速排序
void student_a::quickSort(int s[], int l, int r)
{
	if (l< r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) 
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i]< x)   
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1);  
		quickSort(s, i + 1, r);
	}
}
//插入排序
void student_b::insert(int arr[], int length)
{
	int j, key;
	for (int i = 1; i < length; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

class teacher
{
public:
	void assign(int h[10])
	{
		for (int i = 0; i < 10; i++)
		{
			a->homework[i] = b->homework[i] = c->homework[i] = h[i];
		}

	}
	teacher(student_a *aa, student_b *bb, student_c *cc)
	{
		a = aa;
		b = bb;
		c = cc;
	}
private:
	student_a *a;
	student_b *b;
	student_c *c;

};
//主函数
int main()
{
	
	//定义作业
	int a[10] = { 123,3445,2343,55,2,45,1321,33,0,12 };
	//定义学生
	student_a aa("daming", a);
	student_b bb("erming", a);
	student_c cc("sanming", a);
	//定义学生指针
	student_a *pa=&aa;
	student_b *pb=&bb;
	student_c *pc=&cc;
	//定义老师
	teacher laowang(pa, pb, pc);
	//布置作业
	laowang.assign(a);
	//做作业并输出结果
	pa->dohomework();
	pa->disply();
	pb->dohomework();
	pb->disply();
	pc->dohomework();
	pc->disply();
	getchar();
	


}

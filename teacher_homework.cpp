#include<iostream>
#include<string>
using namespace std;
//����people
class people
{
public:
	int homework[10];
	people(string n,int a[10]);//�������캯��
	virtual void disply();//�����������
	virtual void dohomework(int a[10]);//����������ҵ����
private:
	string name;
};
//����ҵ 
void people::dohomework(int a[10])
{
	return;
}
//���캯��
people::people(string n,int a[10])
{
	int i;
	for (i = 0; i < 10; i++)
	{
		homework[i] = a[i];
	}
	name = n;
}
//���
void people::disply()
{
	int i;
	cout << "����:" << name << endl;
	cout <<"��ҵ:" << endl;
	for (i = 0; i < 10; i++)
	{
		cout << homework[i] << " ";
	}
	cout << endl;
	

}
//��������ѧ�� a
class student_a :public people
{
public:
	student_a(string n, int a[10]);//�������캯��
	virtual void dohomework();//��������ҵ����
	void quickSort(int s[], int l, int r);//��������

};
//���캯��a
student_a::student_a(string n, int a[10]) :people(n, a)
{
	;
}
//��������ҵa
void student_a::dohomework ()
{
	quickSort(homework, 0, 9);
}
//��������ѧ��b
class student_b :public people
{
public:
	//���캯��b
	student_b(string n,int a[10]):people(n,a)
	{
		;
	}
	//������������
	void insert(int arr[], int length);
	//����ҵ��������b
	virtual void dohomework()
	{
		insert(homework, 10);
	}
	
};
//����Ͱ����ѧ��c
class student_c :public people
{public:
	//���캯��c
	student_c(string n, int a[10]) :people(n, a)
	{
		;
	}
	//����Ͱ����
	void barrel(int arr[], int length);
	//����ҵͰ����c
	virtual void dohomework()
	{
		barrel(homework, 10);
	}
};
//���򵥵ģ�ֻ�������������Ͱ����
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
//��������
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
//��������
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
//������
int main()
{
	
	//������ҵ
	int a[10] = { 123,3445,2343,55,2,45,1321,33,0,12 };
	//����ѧ��
	student_a aa("daming", a);
	student_b bb("erming", a);
	student_c cc("sanming", a);
	//����ѧ��ָ��
	student_a *pa=&aa;
	student_b *pb=&bb;
	student_c *pc=&cc;
	//������ʦ
	teacher laowang(pa, pb, pc);
	//������ҵ
	laowang.assign(a);
	//����ҵ��������
	pa->dohomework();
	pa->disply();
	pb->dohomework();
	pb->disply();
	pc->dohomework();
	pc->disply();
	getchar();
	


}

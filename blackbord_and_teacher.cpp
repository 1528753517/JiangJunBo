#include<iostream>
#include<string>
using namespace std;
//����people
class people
{
public:
	int homework[10];
	people(string n, int a[10]);//�������캯��
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
people::people(string n, int a[10])
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
	cout << "��ҵ:" << endl;
	for (i = 0; i < 10; i++)
	{
		cout << homework[i] << " ";
	}
	cout << endl;


}
//�½���ڰ�
class blackbord
{
public:
	int homework[10];
	blackbord()
	{
		for (int i = 0; i < 10; i++)
		{
			homework[i] = 0;
		}
	}

};
//������ʦ
class teacher:public people
{
public:
	//���캯��
	teacher( string n,int a[10] ) :people(n, a)
	{
		;
	}
	//������ҵ���ڰ�
	void assign(blackbord *b)
	{
		for (int i = 0; i < 10; i++)
		{
			b->homework[i] = homework[i];
		}
	}
};
class student :public people
{
public:
	//���캯��
	student(string n, int a[10]) :people(n, a)
	{}
	//ѧ���Ӻڰ�����ҵ
	void gethomework(blackbord *b)
	{
		int flag = 0;
		for (int i = 0; i < 10; i++)
		{
			if (b->homework[i] == 0)
				flag++;
			homework[i] = b->homework[i];

		}
		if (flag == 9)
		{
			cout << "��ʦ����û����ҵhahaha" << endl;
		}
	}
};
//��������ѧ�� a
class student_a :public student
{
public:
	student_a(string n, int a[10]);//�������캯��
	virtual void dohomework();//��������ҵ����
	void quickSort(int s[], int l, int r);//��������

};
//���캯��a
student_a::student_a(string n, int a[10]) :student(n, a)
{
	;
}
//��������ҵa
void student_a::dohomework()
{
	quickSort(homework, 0, 9);
}
//��������ѧ��b
class student_b :public student
{
public:
	//���캯��b
	student_b(string n, int a[10]) :student(n, a)
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
class student_c :public student
{
public:
	//���캯��c
	student_c(string n, int a[10]) :student(n, a)
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
	int j, flag = 0;
	int bar[10000] = { 0 };
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

//������
int main()
{
	//����ѧ��ָ��
	student_a *pa;
	student_b *pb;
	student_c *pc;
	//������ҵ
	int blank[10] ={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//��ʼ��ѧ����ҵ��Ϊ��
	int a[10] = { 99,0,34,343,1332,5,666,7,8,888 };
	//����ѧ��
	student_a aa("daming", blank);
	student_b bb("erming", blank);
	student_c cc("sanming", blank);
	//������ʦ���ڰ�
	teacher tt("laowang", a),*pt;
	blackbord hh;
	blackbord *ph;
	pt = &tt;
	ph = &hh;
	pa = &aa;
	pb = &bb;
	pc = &cc;
	pt->assign(ph);
	pa->gethomework(ph);
	pa->dohomework();
	pa->disply();
	pb->gethomework(ph);
	pb->dohomework();
	pb->disply();
	pc->gethomework(ph);
	pc->dohomework();
	pc->disply();
	pt->disply();
	getchar();



}
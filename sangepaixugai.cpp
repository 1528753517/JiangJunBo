#include <iostream>
using namespace std;
class bassclass							//基类
{
public:
	int number[5];
	virtual void reply(int a[], int, int) = 0;
	bassclass()
	{
		int number3[5] = { 5,2,8,4,3 };
		memcpy(number, number3, sizeof(number3));
	}

};

class teacher :public bassclass		//老师
{
public:
	virtual void reply(int number1[], int left, int right)
	{
		int i;
		cout << "老师：我要留作业。" << endl << "从小到大排这五个数：" << endl;
		for (i = 0; i < 5; i++)						//输出数组
			cout << number[i] << " ";
		cout << endl;
	}
};

class student1 :public bassclass		//桶排序
{
public:
	virtual void reply(int number1[], int left, int right)
	{

		int b[11];
		int i, j;
		cout << "学生1：老师这是我排的数：" << endl;
		for (i = 0; i <= 10; i++)
			b[i] = 0;
		for (i = 0; i < 5; i++)
			b[(number[i])]++;
		for (i = 0; i <= 10; i++)
			for (j = 1; j <= b[i]; j++)
				cout << i << " ";
		cout << endl;
	}
};



class student2 :public bassclass		//插入排序
{
public:
	virtual void reply(int number1[], int left, int right)
	{
		int i, j, temp, k, number2[5];
		cout << "学生2：老师这是我排的数：" << endl;
		for (i = 0; i < 5; i++)
			number2[i] = number[i];
		for (i = 1; i < 5; i++)						//进行N-1轮插入过程
		{
			j = 0;
			while ((number2[j] < number2[i]) && (j < i))//首先找到元素a[i]需要插入的位置
				j++;								//将元素插入到正确的位置
			if (i != j)								//如果i==j，说明a[i]刚好在正确的位置
			{
				temp = number2[i];
				for (k = i; k > j; k--)
					number2[k] = number2[k - 1];
				number2[j] = temp;
			}
		}
		for (i = 0; i < 5; i++)						//输出数组
			cout << number2[i] << " ";
		cout << endl;
	}
};

class student3 :public bassclass					//快速排序
{
public:
	virtual void reply(int number2[], int left, int right)
	{
		int i, j, s, t;
		cout << "学生2：老师这是我排的数：" << endl;
		if (left < right)
		{
			s = number2[(left + right) / 2];
			i = left - 1;
			j = right + 1;
			while (1)
			{
				while (number2[++i] < s);			//找到第一个大于s的number[i]的值
				while (number2[--j] > s);			//原理同上
				if (i >= j)
				{
					printf("i=[%d],j=[%d]\n", i, j);
					break;
				}
				t = number2[i];
				number2[i] = number2[j];
				number2[j] = t;


			}
			reply(number2, left, i - 1);			//递归
			reply(number2, j + 1, right);			//递归
		}
		for (i = 0; i < 5; i++)						//输出数组
			cout << number2[i] << " ";
		cout << endl;
	}

};

int main()
{
	bassclass *a;
	teacher e;
	student1 b;
	student2 c;
	student3 d;
	int ee[5] = { 5,2,8,4,3 };
	a = &e;
	a->reply(ee, 0, 4);
	a = &b;
	a->reply(ee, 0, 4);
	a = &c;
	a->reply(ee, 0, 4);
	a = &c;
	a->reply(ee, 0, 4);
	return 0;
}
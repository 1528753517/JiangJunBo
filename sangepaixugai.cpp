#include <iostream>
using namespace std;
class bassclass							//����
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

class teacher :public bassclass		//��ʦ
{
public:
	virtual void reply(int number1[], int left, int right)
	{
		int i;
		cout << "��ʦ����Ҫ����ҵ��" << endl << "��С���������������" << endl;
		for (i = 0; i < 5; i++)						//�������
			cout << number[i] << " ";
		cout << endl;
	}
};

class student1 :public bassclass		//Ͱ����
{
public:
	virtual void reply(int number1[], int left, int right)
	{

		int b[11];
		int i, j;
		cout << "ѧ��1����ʦ�������ŵ�����" << endl;
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



class student2 :public bassclass		//��������
{
public:
	virtual void reply(int number1[], int left, int right)
	{
		int i, j, temp, k, number2[5];
		cout << "ѧ��2����ʦ�������ŵ�����" << endl;
		for (i = 0; i < 5; i++)
			number2[i] = number[i];
		for (i = 1; i < 5; i++)						//����N-1�ֲ������
		{
			j = 0;
			while ((number2[j] < number2[i]) && (j < i))//�����ҵ�Ԫ��a[i]��Ҫ�����λ��
				j++;								//��Ԫ�ز��뵽��ȷ��λ��
			if (i != j)								//���i==j��˵��a[i]�պ�����ȷ��λ��
			{
				temp = number2[i];
				for (k = i; k > j; k--)
					number2[k] = number2[k - 1];
				number2[j] = temp;
			}
		}
		for (i = 0; i < 5; i++)						//�������
			cout << number2[i] << " ";
		cout << endl;
	}
};

class student3 :public bassclass					//��������
{
public:
	virtual void reply(int number2[], int left, int right)
	{
		int i, j, s, t;
		cout << "ѧ��2����ʦ�������ŵ�����" << endl;
		if (left < right)
		{
			s = number2[(left + right) / 2];
			i = left - 1;
			j = right + 1;
			while (1)
			{
				while (number2[++i] < s);			//�ҵ���һ������s��number[i]��ֵ
				while (number2[--j] > s);			//ԭ��ͬ��
				if (i >= j)
				{
					printf("i=[%d],j=[%d]\n", i, j);
					break;
				}
				t = number2[i];
				number2[i] = number2[j];
				number2[j] = t;


			}
			reply(number2, left, i - 1);			//�ݹ�
			reply(number2, j + 1, right);			//�ݹ�
		}
		for (i = 0; i < 5; i++)						//�������
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
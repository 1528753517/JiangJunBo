#include <iostream>
using namespace std;

class Sort
{
public:
	virtual void sort(int a[],int ,int )= 0;
};

class Sort_1:public Sort
{
public:
	virtual void sort(int a[],int left,int right)
	{
		int b[11];
		int i, j;
		for (i = 0; i <= 10; i++)
			b[i] = 0;
		for (i = 0; i < 5; i++)
			b[(a[i])]++;
		for (i = 0; i <= 10; i++)
			for (j = 1; j <= b[i]; j++)
				cout << i<<" ";
		cout << endl;
	}
};

class Sort_2 :public Sort 
{
	public:
		virtual void sort(int a[], int left, int right)
		{
			int temp, i,j,t;
			if (left > right)
				return;
			temp = a[left];
			i = left;
			j = right;
			while (i != j)
			{
				while (a[j] >= temp && i < j)
					j--;
				while (a[i] <= temp && i < j)
					i++;
				if (i < j)
				{
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
			a[left] = a[i];
			a[i] = temp;

			sort(a, left, i - 1);
			sort(a, i + 1, right);

		}
};

class Sort_3 :public Sort
{
public:
	virtual void sort(int num[],int left,int right)
	{
		int n = 5;
		int i = 0;
		int j = 0;
		int tmp = 0;
		for (i = 1; i<n; i++)
		{
			tmp = num[i];
			j = i - 1; 
			while (j >= 0 && tmp<num[j])  
			{
				num[j + 1] = num[j];
				j--;
			}
			num[j + 1] = tmp;
		}
		for (i = 0; i < 5; i++)
			cout << num[i] << " ";
	}
};

int main()
{	
	Sort *pt;
	Sort_1 a;
	Sort_2 b;
	Sort_3 c;
	
	int NUM[5]={7,3,8,5,1};
	pt = &a;
	pt->sort(NUM, 0, 4);


	int num[5] = { 7,3,8,5,1 };
	pt = &b;
	pt->sort(num,0,4);
	for (int i = 0; i <=4; i++)
		cout << num[i] << " ";
	cout << endl;

	int Num[5] = { 7,3,8,5,1 };
	pt=&c;
	pt->sort(Num, 0, 4);


	return 0;
}
#include<iostream>
using namespace std;
class Number {
	friend ostream & operator<<(ostream &out, Number &obj);			//����Ϊ��Ԫ
	friend istream & operator>>(istream &in, Number &obj);
public:
	Number(int a)
	{
		this->a = a;												//����ָ��this
	}
private:															//����˽��int��
	int a;
};
ostream & operator<<(ostream &out, Number &obj)						//����
{
	out << obj.a;
	return out;
}
istream & operator>>(istream &in, Number &obj)
{
	in >> obj.a ;
	if (!in)
	{
		obj = Number(0);
	}
	return in;
}
int main()
{
	Number t1(0);
	cout << "������һ��int����:";
	cin >> t1;
	cout << t1 << endl;;
	return 0;
}
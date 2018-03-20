#include<iostream>
using namespace std;
class Number {
	friend ostream & operator<<(ostream &out, Number &obj);			//定义为友元
	friend istream & operator>>(istream &in, Number &obj);
public:
	Number(int a)
	{
		this->a = a;												//隐藏指针this
	}
private:															//两个私有int型
	int a;
};
ostream & operator<<(ostream &out, Number &obj)						//重载
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
	cout << "请输入一个int属性:";
	cin >> t1;
	cout << t1 << endl;;
	return 0;
}
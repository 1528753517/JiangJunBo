#include <iostream>
using namespace std;

class Plural
{
private:
	int real;
	int imag;
public:
	Plural() {real = 0, imag = 0;}
	Plural(int, int);
	friend istream & operator >>(istream&, Plural&);
	friend ostream & operator <<(ostream&, Plural&);
};

Plural :: Plural(int Real, int Imag)
{
	real = Real;
	imag = Imag;
}

istream & operator>>(istream &input, Plural &P)
{	input >> P.real >> P.imag;
	return input;
}

ostream & operator<<(ostream &output, Plural &P)
{	if(P.imag>=0)
		output << P.real << "+" << P.imag << "i" << endl;
	else
		output << P.real << P.imag << "i" << endl;
	return output;
}

int main()
{
	Plural a;
	cin >> a;
	cout << a;
	return 0;
}
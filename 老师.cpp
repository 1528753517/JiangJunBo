#include <iostream>
using namespace std;

class teacher
{
public:
	teacher(int h = 0) :homework(h) {};
	void deliever(teacher&);//��ʦֱ�ӷ���ҵ
	friend class student;
	friend class blackboard;
private:
	int homework;
};
 
class student
{
public:
	student(int h = 0) :homework(h) {};
	void receive(teacher&,student&);//ѧ��ֱ���յ���ʦ��ҵ
	friend class blackboard;
private:
	int homework;
};

class blackboard
{
public:
	blackboard(int h = 0) :homework(h) {};
	void push(student&,blackboard&);//��ѧ����ҵ��Ϣ
	void pull(teacher&,blackboard&);//��ʦ����ҵ��Ϣ�����ڰ�

private:
	int homework;
};

void blackboard::push(student&STU,blackboard&BLACK)
{
	STU.homework = BLACK.homework;
	cout << "С���Ӻڰ�֪����" << BLACK.homework << "����ҵ" << endl;
}

void blackboard::pull(teacher &TEA,blackboard&BLACK)
{
	BLACK.homework = TEA.homework;
	cout << "��ʦ��" << BLACK.homework << "����ҵд���ڰ�" << endl;
}

void teacher::deliever(teacher&TEA)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		TEA.homework++;
	cout << "��ʦֱ�ӷ���"<<TEA.homework<<"����ҵ"<<endl;
}

void student::receive(teacher&TEA,student&STU)
{
	STU.homework = TEA.homework;
	cout << "С��ֱ�ӽӵ���" << STU.homework << "����ҵ" << endl;
}

int main()
{
	teacher TEA;
	student STU;
	blackboard BLACK;
	TEA.deliever(TEA);//��ʦ����n����ҵ
	STU.receive(TEA,STU);//С��ֱ������n����ҵ
	BLACK.pull(TEA,BLACK);//��ʦ��n����ҵд���ڰ�
	BLACK.push(STU,BLACK);//ѧ���Ӻڰ���֪����n����ҵ
	return 0;
}
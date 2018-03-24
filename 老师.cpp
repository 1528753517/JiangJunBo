#include <iostream>
using namespace std;

class teacher
{
public:
	teacher(int h = 0) :homework(h) {};
	void deliever(teacher&);//老师直接发作业
	friend class student;
	friend class blackboard;
private:
	int homework;
};
 
class student
{
public:
	student(int h = 0) :homework(h) {};
	void receive(teacher&,student&);//学生直接收到老师作业
	friend class blackboard;
private:
	int homework;
};

class blackboard
{
public:
	blackboard(int h = 0) :homework(h) {};
	void push(student&,blackboard&);//给学生作业信息
	void pull(teacher&,blackboard&);//老师把作业信息传到黑板

private:
	int homework;
};

void blackboard::push(student&STU,blackboard&BLACK)
{
	STU.homework = BLACK.homework;
	cout << "小明从黑板知道了" << BLACK.homework << "份作业" << endl;
}

void blackboard::pull(teacher &TEA,blackboard&BLACK)
{
	BLACK.homework = TEA.homework;
	cout << "老师把" << BLACK.homework << "份作业写到黑板" << endl;
}

void teacher::deliever(teacher&TEA)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		TEA.homework++;
	cout << "老师直接发了"<<TEA.homework<<"份作业"<<endl;
}

void student::receive(teacher&TEA,student&STU)
{
	STU.homework = TEA.homework;
	cout << "小明直接接到了" << STU.homework << "份作业" << endl;
}

int main()
{
	teacher TEA;
	student STU;
	blackboard BLACK;
	TEA.deliever(TEA);//老师布置n份作业
	STU.receive(TEA,STU);//小明直接收了n份作业
	BLACK.pull(TEA,BLACK);//老师吧n份作业写到黑板
	BLACK.push(STU,BLACK);//学生从黑板上知道了n份作业
	return 0;
}
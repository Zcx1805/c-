#include<iostream>
using namespace std;
//class Date;
//class Time
//{
//	friend class Date; 
//public:
//	Time(int hour=1)
//		: _hour(hour)
//	{}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int year = 2021)
//		: _year(year)
//
//	{}
//	void SetTimeOfDate(int hour)
//	{
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
//		t._hour = hour;
//		
//	}
//private:
//	int _year;
//	Time t;
//};

class A
{
private:
	static int staticnum;
	int i;
public:
	class B
	{
	public:
		void print(const A& a)
		{
			cout << staticnum << endl;
			//ֱ�ӷ���
			cout << a.i << endl;
			//����������
		}
	};
};
int A::staticnum = 1;
//��̬��Ա��Ҫ���ⶨ��
int main()
{
	//B::b;��ΪB��A�Ҫ��A����������������
	A::B b;
	b.print(A());
	return 0;
}
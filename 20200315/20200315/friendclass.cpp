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
//		// 直接访问时间类私有的成员变量
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
			//直接访问
			cout << a.i << endl;
			//对象名访问
		}
	};
};
int A::staticnum = 1;
//静态成员需要类外定义
int main()
{
	//B::b;因为B在A里，要用A的类名来创建对象
	A::B b;
	b.print(A());
	return 0;
}
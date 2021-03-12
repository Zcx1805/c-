#include<iostream>

using namespace std;
class Date{
	public:
		//天数
		int getDay(int year, int month){
			int dayarr[13] = { 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			int day = dayarr[month];
			if (month == 2 && (year == 4 && year != 100) || year == 400){
				day += 1;
			}
			return day;
		}

		//构造函数
		Date(int year=2021,int month=1,int day=1){
			if (year<0 || month<0 || month>12 || day>getDay(year,month)){
				_year = 1;
				_month = 1;
				_day = 1;
				cout << "非法日期！" << endl;
			}
			else{
				_year = year;
				_month = month;
				_day = day;
			}
		}

		//运算符重载函数
		Date& operator+=(int day){
			_day += day;
			while (_day > getDay(_year, _month)){
				_day -= getDay(_year, _month);
				++_month;
				while (_month > 13){
					_year++;
					_month = 1;
				}
			}
			return *this;
		}

		Date operator+(int day){
			Date copy(*this);
			copy = copy + day;
			return copy;
		}

		//前置
		Date& operator++(){
			return *this += 1;
		
		}

		//后置
		Date operator++(int a){
			Date copy(*this);
			copy += 1;
			return copy;
		}

		Date& operator-=(int day){
			_day -= day;
			while (day <= 0){
				--_month;

				if (_month == 0){
					--_year;
				}
				_month = 12;
				_day += getDay(_year, _month);
			}
			return *this;
		}


		//前置
		Date& operator--(){
			return *this -= 1;
		}
		
		//后置
		Date operator--(int a){
			Date copy(*this);
			copy -= 1;
			return copy;
		}

		bool operator==(const Date&d){
			return (_year == d._year&&_month == d._month&&_day == d._day);
		}

		bool operator!=(const Date&d){
			return !(*this == d);
		}

		bool operator>(const Date&d){
			if (_year > d._year){
				return true;
			}
			else if (_year == d._year){
				if (_month > d._month){
					return true;
				}
				else if (_month == d._month){
					if (_day == d._day){
						return true;
					}
				}
			}
			return false;
		}

		bool operator>=(const Date&d){
			return *this > d || *this == d;
		}

		bool operator<(const Date&d){
			return !(*this>=d);
		}

		bool operator<=(const Date&d){
			return !(*this>d);
		}


		int operator-(const Date&d){
			Date max = *this;
			Date min=d;
			int flag = 1;
			if (min > max){
				flag = -1;
				max = d;
				min = *this;
			}
			int count = 0;
			while (max != min){
				min++;
				count++;
			}
			return flag*count;
		}

	private:
		int _year;
		int _month;
		int _day;

};
#pragma once

#include <iostream>

using namespace std;

//class time
//{
//public:
//	time()
//	{
//		_year = 2000;
//		_month = 1;
//		_day = 1;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
class Date
{
	//一般来说成员函数是公有的允许外部调用该函数
public:
	//Date(/*Date *this,*/)
	//{
	//	_year = 2000;
	//	_month = 1;
	//	_day = 1;
	//}
	Date(/*Date *this,*/int year = 2000, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//Date d1 = d2; //Date d1(d2);
	Date(/*Date *this,*/const Date& d) //编译器有自己的拷贝构造函数，可以完成类似这样的浅拷贝
	{								   //但是像链表的拷贝需要开辟空间再拷贝这种是不行的，这种拷贝是叫做深拷贝
		this->_year = d._year;          
		this->_month = d._month;
		this->_day = d._day;
	}
	//  d1 == d2
	bool operator == (/*Date *this,*/ const Date& d)
	{
		return this->_year == d._year &&
			this->_month == d._month &&
			this->_day == d._day;
	}

	//d1 = d2
	const Date& operator = (/*Date *this,*/const Date& d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;

		return d; 
	}
	void Print(/*Date *this,*/);


	//一般来说，成员变量会设置成是私有的不允许直接访问
private:
	int _year;
	int _month;
	int _day;
	//time a;
};

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//	~Stack()
//	{
//		free(_a);
//		_size = 0;
//		_capacity = 0;
//	}
//private:
//	int *_a;
//	int _size;
//	int _capacity;
//};


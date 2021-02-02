#include "class.h"

void Date::SetDate(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::PrintDate()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

#pragma once

#include <iostream>

using namespace std;

class Date
{
public:
	void SetDate(int year, int month, int day);
	void PrintDate();

private:
	int _year;
	int _month;
	int _day;
};



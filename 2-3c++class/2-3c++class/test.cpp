#include "class.h"

int main()
{

	//Date d1; //用类定义出来的变量 d1 就是对象
	//Date d2; //定义出另一个对象

	//Date d1(2000, 1, 1);

	
	Date d1(2000, 2, 2);
	Date d2; //初始化的时候要用拷贝构造函数
	Date d3;

	d3 = d2 = d1;  // 赋值的时候用到赋值运算符
	d1 == d2;

	d1.Print();
	d2.Print();
	d3.Print();

	system("pause");
	return 0;
}


#include <iostream>

using namespace std;

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	printf("%d\n", ret);
//
//	system("pause");
//	return 0;
//}


//int main()
//{
//	/*int a = 1;
//	int b = 2;
//
//	int& c = a;
//	c = b;
//
//	printf("c = %d\n", c);
//	printf("a = %d\n", a);*/
//
//	//int& b = a;
//	//int& c = a;
//	//int& d = a;
//
//
//	//int& c;
//	//int& b = a; //定义一个引用类型
//	//
//
//	//printf("b = %d\n", b);
//
//	//b = 2;
//	//printf("a = %d\n", a);  
//
//	//const int a = 1; //a经过const修饰后变成了值不能被修改的常变量
//
//	//int& b = a; 
//	//const int& c = a;
//
//	//int& a = 1;
//	//const int& a = 1;
//
//	//int a = 1;
//	//double& b = a;
//	//const double& c = a;
//	//
//	
//
//
//	system("pause");
//	return 0;
//}

//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("a = %d,b = %d\n", a, b);
//
//	Swap(a, b);
//
//	printf("a = %d,b = %d\n", a, b);
//
//	system("pause");
//	return 0;
//}

int& Func1()
{
	static int a = 0;
	a++;
	return a;
}

int& Func2()
{
	int a = 0;
	a++;
	return a;
}

int main()
{

	printf("%d\n", Func());
	printf("%d\n", Func());
	printf("%d\n", Func());

	system("pause");
	return 0;
}

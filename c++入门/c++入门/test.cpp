//
////每个c++程序都要包含的i(输入)o(输出)流
//#include <iostream>
//
////将std(c++的标准)命名空间全部展开
//using namespace std;
//
//namespace myName
//{
//	int a = 0;
//	int b = 1;
//	int c = 0;
//}
//
//using myName::b;
//
//using namespace myName;
//
//int main()
//{ 
//
//	cout << myName::a << " " << b << endl;
//	
//	/*printf("hello world\n");
//	cout << "hello world" << endl;*/
//
//	system("pause");
//	return 0;
//}

#include <iostream>

using namespace std;

//namespace myName
//{
//	//全局变量的定义
//	int a;
//	int b;
//	int c;
//
//	//函数的声明
//	int AddFunc(int x, int y);
//
//	//函数的定义
//	int SubFunc(int x, int y)
//	{
//		return x - y;
//	}
//
//	//其它的命名空间的定义
//	namespace otherName
//	{
//		int a;
//		int b;
//	}
//
//}

//namespace myName
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//}
//
////将myName命名空间中的所有全局变量名或函数名都引入。所有成员都可以直接使用
//using namespace myName;
//
//int main()
//{
//	
//	printf("%d ", a);
//	printf("%d ", b);
//	printf("%d ", c);
//
//	return 0;
//}

int Add(int x , int y )
{
	return x + y ;
}

double Add(double x, double y)
{
	return x + y;
}


int main()
{

	printf("x + y = %d\n", Add(1, 2));

	printf("x + y = %.2lf\n", Add(1.1, 2.2));

	system("pause");
	return 0;
}
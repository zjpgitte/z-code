#include "class.h"

//inline int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	
//	int result = Add(1, 2);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//
//	int a = 1;
//	auto b = a;
//	printf("%d\n", b);
//
//	system("pause");
//	return 0;
//}


//void testFor(int *a)
//{
//	for (auto e:a)
//	{
//		cout << e << endl;
//	}
//}
//int main()
//{
//	//int a[] = { 1, 2, 3, 4, 5, 6 };
//
//	////正常情况下遍历数组
//	//for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
//	//{
//	//	cout << a[i] << " ";
//	//}
//	//cout << endl;
//
//	////范围for遍历
//	//for (auto e:a)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//int *a = nullptr;
//
//	//auto b = a;
//	//auto* c = a;//这两种方式都可以定义指针
//
//	//auto& d = a;//定义引用必须加 & 编译器才能推导出来定义的是引用
//
//	//auto a = 1, b = 2; //可以推导出 a和b 的类型是 int 
//
//	//auto a = 1.0, b = 2.0; //可以推导出 a和b 是float
//
//	//auto a = 'a', b = 'b';//可以推导出 a和b 是char
//
//	//auto a = 1, b = 2.0, c = 'c'; //这样定义就不行，因为编译器只根据声明的第一个元素
//	//							//的类型来声明后续变量。
//
//
//
//	int a[] = { 1, 2, 3, 4, 5, 6 };
//	testFor(a);
//
//	printf("%d\n", sizeof(a));
//
//
//	return 0;
//}

//void student::PrintScore()
//{
//	printf("%d\n", _score);
//}
//
//struct student
//{
//	//成员
//	//成员变量
//	int _name;
//	int _age;
//	int _score;
//
//	//成员函数
//	void PrintScore();
//};


//
//struct student
//{
//	//成员
//	//成员变量
//	int _name;
//	int _age;
//	int _score;
//	
//	//成员函数
//	void PrintScore()
//	{
//		printf("%d\n", _score);
//	}
//};

int main()
{

	//student st;
	//st.PrintScore();

	Date d1;
	d1.SetDate(2020, 2, 2);
	d1.PrintDate();

	system("pause");
	return 0;
}
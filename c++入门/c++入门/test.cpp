//
////ÿ��c++����Ҫ������i(����)o(���)��
//#include <iostream>
//
////��std(c++�ı�׼)�����ռ�ȫ��չ��
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
//	//ȫ�ֱ����Ķ���
//	int a;
//	int b;
//	int c;
//
//	//����������
//	int AddFunc(int x, int y);
//
//	//�����Ķ���
//	int SubFunc(int x, int y)
//	{
//		return x - y;
//	}
//
//	//�����������ռ�Ķ���
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
////��myName�����ռ��е�����ȫ�ֱ����������������롣���г�Ա������ֱ��ʹ��
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
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
//	////��������±�������
//	//for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
//	//{
//	//	cout << a[i] << " ";
//	//}
//	//cout << endl;
//
//	////��Χfor����
//	//for (auto e:a)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//int *a = nullptr;
//
//	//auto b = a;
//	//auto* c = a;//�����ַ�ʽ�����Զ���ָ��
//
//	//auto& d = a;//�������ñ���� & �����������Ƶ����������������
//
//	//auto a = 1, b = 2; //�����Ƶ��� a��b �������� int 
//
//	//auto a = 1.0, b = 2.0; //�����Ƶ��� a��b ��float
//
//	//auto a = 'a', b = 'b';//�����Ƶ��� a��b ��char
//
//	//auto a = 1, b = 2.0, c = 'c'; //��������Ͳ��У���Ϊ������ֻ���������ĵ�һ��Ԫ��
//	//							//����������������������
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
//	//��Ա
//	//��Ա����
//	int _name;
//	int _age;
//	int _score;
//
//	//��Ա����
//	void PrintScore();
//};


//
//struct student
//{
//	//��Ա
//	//��Ա����
//	int _name;
//	int _age;
//	int _score;
//	
//	//��Ա����
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
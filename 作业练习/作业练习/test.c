#include<stdio.h>
#include<windows.h>
//int test(int a, int b)
//{
//	printf("%d \n", a + b);
//}
//����һ������ָ�룬ָ��ĺ���������int�ββ��ҷ���һ������ָ�룬
//���ص�ָ��ָ��һ����һ��int�β��ҷ���int�ĺ���*/
//int add(int a, int b)
//{
//	
//	return a+b;
//}
int main()
{
	int *F(int, int);
	int(*F)(int, int);
	int *(*F)(int, int);
	int(*(*F)(int, int))(int);
	/*int a = 10, b = 20;
	add(a,b);
	int (*p)(int, int) ;
	p = add;
	printf("test:%p\n", add);
	printf("p   :%p\n", p);*/
	/*int arr[5];
	int *p = arr;
	int (*q)[5]=arr;
	printf("arr:%p\n", arr);
	printf("p  :%p\n", p);
	printf("p+1:%p\n", p+1);
	printf("q  :%p\n", q );
	printf("q+1:%p\n", q + 1);*/
	system("pause");
	return 0;
}
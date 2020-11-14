#include<stdio.h>
#include<windows.h>
//int test(int a, int b)
//{
//	printf("%d \n", a + b);
//}
//定义一个函数指针，指向的函数有两个int形参并且返回一个函数指针，
//返回的指针指向一个有一个int形参且返回int的函数*/
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
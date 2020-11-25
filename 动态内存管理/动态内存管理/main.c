#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//考察内容：局部变量的地址不能做返回值
char *GetMemery()
{
	char p[] = "hello world";//栈上开辟的内存空间，函数结束后，之前占用的内存全部被释放，
	return p;				//内存当中的数据变为失效数据，不可被访问
							//在定义函数时应避免函数返回值是一个局部变量的地址，否则会出现上述情况
}
void test()					//当调用test()和GetMemery()时，先后开辟两块内存空间，分别供这两个函数使用
{							//当GetMemery()调用结束后，原内存空间被释放，其中数据不变，仅仅时变为无效
	char *str = NULL;		//当再次调用函数(例如:printf())时，会覆盖掉原GetMemery()使用的内存，从而修改
	str = GetMemery();		//其中的数据而导致 打印出 乱码。
	printf(str);	
}
int main()
{
	
	test();
	//int *p = NULL;
	//int *ptr = NULL;
	//ptr = (int *)malloc(0);
	//if (NULL == ptr)
	//{
	//	printf("malloc error!\n");
	//	return 1;
	//}
	//printf("malloc success!\n");
	//
	/*for (int i = 0; i < 6; i++)
	{
		*p = 4;
		printf("%d\n", *p);
		p++;
	}*/
	/*for (int i = 0; i < 20; i++)
	{
		*p = i;
		p++;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d\n", *p);
	}*/
	/*char *ptr = (char*)realloc(p, 2);
	if (NULL == ptr)
	{
		printf("realloc error!\n");
		return 1;
	}
	p = ptr;*/
	//free(ptr);
	system("pause");
	return 0;
}
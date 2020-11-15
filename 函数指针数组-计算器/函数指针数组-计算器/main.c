#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	if (0 == b)
	{
		printf("Error! \n");
		return -1;
	}
	return a / b;
}
void Menu()
{
	printf(" 0. 退出\n");
	printf(" 1. 加法           2.减法\n");
	printf(" 3. 乘法           4.除法\n");

}
int main()
{
	int(*arr[5])(int, int) = { NULL, Add, Sub, Mul, Div };
	int quit = 0;
	int select = 0;
	int a = 0, b = 0;
	while (!quit)
	{
		Menu();
		printf("请输入序号：");
		scanf("%d", &select);
		if (select < 0 || select > 4)
		{
			continue;
		}
		if (0 == select)
		{
			quit = 1;
			continue;
		}
		printf("请输入两个操作数：");
		scanf("%d %d", &a, &b);
		printf("result : %d\n",arr[select](a,b));

	}
	system("pause");
	return 0;
}
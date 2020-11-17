#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
//int Max_Div_Num(int a, int b)
//{
//	int num = 0;
//	for (int i = 1; i < a; i++)
//	{
//		if ((0 == a % i) && (0 == b % i))
//		{
//			num = i;
//		}
//	}
//	return num;
//}
//辗转相除法：大数除小数，小数变大数，余数变小数
int Max_Div_Num(int max, int min)
{
	if (max < min)
	{
		int temp = max;
		max = min;
		min = temp;

	}
	int c = 0;
	while (1)
	{
		c = max % min;
		if (0 == c)
		{
			break;
		}
		max = min;
		min = c;
	}
	return min;
}
int main()
{
	int a, b;
	printf("输入两个数：\n");
	scanf("%d %d", &a, &b);
	printf("%d\n",Max_Div_Num(a, b));
	system("pause");
	return 0;
}
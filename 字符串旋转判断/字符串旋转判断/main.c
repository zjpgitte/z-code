#include <stdio.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX 100
void Revolve(char *str)//旋转一次字符串
{
	char *start = str;
	char *end = str;
	while ('\0' != *end)
	{
		end++;
	}
	end--;
	char ch = *start;
	while ('\0' != *(start+1))
	{
		*start = *(start + 1);
		start++;
	}
	*end = ch;
}
int Judge(char *str1,char *str2,int num1)//num1是str1的长度
{
	if (str1 == NULL || str2 == NULL)
	{
		return -1;
	}
	int num = 0;
	while (1)//旋转多次字符串
	{
		Revolve(str1);//旋转一次字符串，
		num++;
		if (strcmp(str1, str2) == 0)
		{
			return 1;
		}
		if (num == num1)
		{
			return 0;
		}

	}
}
int main()
{
	char str1[MAX] = { 0 };
	char str2[MAX] = { 0 };
	printf("输入字符串1：");
	gets(str1);
	printf("输入字符串2：");
	gets(str2);
	//旋转一次字符串1
	//多次旋转，判断旋转之后的字符串和字符串2是否相等
	if (Judge(str1, str2, strlen(str1)) == 1)
	{
		printf("str1是str2旋转之后的字符串\n");
	}
	if (Judge(str1, str2, strlen(str1)) == 0)
	{
		printf("str1不是str2旋转之后的字符串\n");
	}
	
	system("pause");
	return 0;
}
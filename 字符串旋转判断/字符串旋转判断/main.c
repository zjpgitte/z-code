#include <stdio.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX 100
void Revolve(char *str)//��תһ���ַ���
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
int Judge(char *str1,char *str2,int num1)//num1��str1�ĳ���
{
	if (str1 == NULL || str2 == NULL)
	{
		return -1;
	}
	int num = 0;
	while (1)//��ת����ַ���
	{
		Revolve(str1);//��תһ���ַ�����
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
	printf("�����ַ���1��");
	gets(str1);
	printf("�����ַ���2��");
	gets(str2);
	//��תһ���ַ���1
	//�����ת���ж���ת֮����ַ������ַ���2�Ƿ����
	if (Judge(str1, str2, strlen(str1)) == 1)
	{
		printf("str1��str2��ת֮����ַ���\n");
	}
	if (Judge(str1, str2, strlen(str1)) == 0)
	{
		printf("str1����str2��ת֮����ַ���\n");
	}
	
	system("pause");
	return 0;
}
#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable:4996)
#define Max 100
void Strcpy(char str2[], char str1[])
{
	char *p=str1, *q=str2;
	while (*q++ = *p++);
	
}
int main()
{
	char str1[] = "hello";
	char str2[Max];
	Strcpy(str2, str1);
	printf("%s", str2);
	system("pause");
	return 0;
}
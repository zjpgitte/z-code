#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable:4996)
void reverse(char *left ,char *right)
{
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
int main()
{
	char str[100] = { 0 };
	gets(str);
	reverse(str, str + strlen(str) - 1);
	char *left = str;
	char *right = str;
	while (*right != '\0')
	{
		while (*right != ' ' && *right != '\0')
		{
			right++;
		}
		reverse(left, right - 1);
		right++;
		left = right;
	}
	printf("%s\n", str);
	system("pause");
	return 0;
}
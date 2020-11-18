#include <stdio.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)
//找打str1中的‘\0’，从该位置开始拷，到str2的‘\0’结束；最后加上'\0'
char *My_Strcat(char *str1, const char *str2)
{
	if (NULL == str1 || NULL == str2)
	{
		return "FALSE";
	}

	char *p = str1;
    const	char *q = str2;
	while ((*p) != '\0')
	{
		p++;
	}
	while ((*q) != '\0')
	{
		*p++ = *q++;
	}
	*p = '\0';
	return str1;

}
int My_strcmp(const char *str1, const char *str2)
{
	const char *p = str1;
	const char *q = str2;
	while ((*p) != '\0' && (*q) != '\0')
	{
		if (*p == *q)
		{
			p++; q++;
		}
		else
		{
			return *p > *q ? (*p - *q):(*q - *p);
		}
	}
	if ('\0' == *p && '\0' == *q)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
char *My_strcpy(char *str1, const char *str2)
{
	char *p = str1;
    const char *q = str2;
	while (*q != '\0')
	{
		*p++ = *q++;
	}
	*p = '\0';
	return str1;
}
int My_strlen(char *str)
{
	char *p = str;
	int count=0;
	while (*p != '\0')
	{
		p++;
		count++;
	}
	return count;
}
int main()
{
	char str1[50] = "hello ";
	char str2[] = "hell ";
	printf("%d\n", My_strlen(str1));
	printf("%s\n", My_strcpy(str1, str2));
	printf("%s\n", My_Strcat(str1, str2));
	printf("%d\n",My_strcmp(str1, str2));
	system("pause");
	return 0;
}
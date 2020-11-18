#include <stdio.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)
//strlen , strcpy , strcat , strstr , strncpy , strncat ,stncmp , strtok
int main()
{
	char str1[] = "hello bit";
	char *str2 = "hello bit!";//该字符串保存在字符常量区，str2中保存的是串的首地址，即‘h’的地址
	char str3[50]="1.";
	char *str4 = NULL;
	char ch = 'A';
	if (isupper(ch))
	{
		printf("OK\n");
	}
	else
	{
		printf("NO\n");
	}
	//printf("%s\n", strncat(str3, str1, 6));
	//printf("%d\n", strncmp(str1, str2,6));
	//char *pch = strtok(str1, " ,!");
	//while (NULL != pch)
	//{
	//	printf("%s\n", pch);
	//	pch = strtok(NULL, " ,!");//strtok 打印一个字符串的多个字符，第一次传参 传 指针  后续传参 传NULL
	//}
	/*while (NULL != pch)
	{
		printf("%s\n", pch);
		pch = strtok(str1, " ,!");
	}*/
	//printf("%s\n", strstr(str1, "w"));//从str1中找 w，返回值是w的地址
	//printf("%d\n", strlen(str1));
	//printf("%d\n", strlen(str2));
	//printf("%s\n", strcpy(str3, str1));//目标指针一定要指向一块空间且空间一定要足够大
	//printf("%s\n", strncpy(str3, str2, 1));//从源字符串读 n 个 拷给 目标空间，若n>strlen(scr)则补0
	//printf("%s\n", strcat(str3, str1));//
	system("pause");
	return 0;
}
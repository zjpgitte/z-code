#include <stdio.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)
//strlen , strcpy , strcat , strstr , strncpy , strncat ,stncmp , strtok
int main()
{
	char str1[] = "hello bit";
	char *str2 = "hello bit!";//���ַ����������ַ���������str2�б�����Ǵ����׵�ַ������h���ĵ�ַ
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
	//	pch = strtok(NULL, " ,!");//strtok ��ӡһ���ַ����Ķ���ַ�����һ�δ��� �� ָ��  �������� ��NULL
	//}
	/*while (NULL != pch)
	{
		printf("%s\n", pch);
		pch = strtok(str1, " ,!");
	}*/
	//printf("%s\n", strstr(str1, "w"));//��str1���� w������ֵ��w�ĵ�ַ
	//printf("%d\n", strlen(str1));
	//printf("%d\n", strlen(str2));
	//printf("%s\n", strcpy(str3, str1));//Ŀ��ָ��һ��Ҫָ��һ��ռ��ҿռ�һ��Ҫ�㹻��
	//printf("%s\n", strncpy(str3, str2, 1));//��Դ�ַ����� n �� ���� Ŀ��ռ䣬��n>strlen(scr)��0
	//printf("%s\n", strcat(str3, str1));//
	system("pause");
	return 0;
}
#include <stdio.h>
#include <windows.h>
//��str1����str2,str1�����str2����,��󷵻�str1
//�ж�*str1��*str2�Ƿ���ȣ��ǣ�Pָ��str1��qָ��str2���Ƚ�*p,*q pq�ֱ������
//q�ߵ�ͷ˵���ҵ��˷���str1������û�ҵ�str1��������½�����������
const char *my_strstr(const char *str1, const char *str2)
{
	while (*str1)//str1�����
	{
		const char *p = str1;//���Ҫ����str1
		const char *q = str2;
		while (*str2 && *p == *q)//�ж��ǲ��Ƕ�Ӧ��ÿ���ַ�����ͬ
		{
			p++;
			q++;
		}//ѭ���˳������ֿ��� 1.*str2 == '\0' 2.*p != *q;
		if (*q == '\0')
		{
			return str1;//����ҵ����򷵻�str1
		}
		str1++;
	}
	return NULL;//������ִ�е���˵��û�ҵ���
}
int main()
{
	char str1[] = "abcd 123 abcde 1234";
	char str2[] = "abcd";
	printf("%s\n", my_strstr(str1, str2));
	system("pause");
	return 0;
}
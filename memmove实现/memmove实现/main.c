#include <stdio.h>
#include <windows.h>
//memcpyû�п����ڴ��ص����������memmove�ж���������˿���
//���ڴ��ص���ʱ������Ӧ�ÿ����� ��->�� ���� ��->��
void my_memmove(void *_str1, void *_str2,int num)
{
	char *str1 = (char *)_str1;
	char *str2 = (char *)_str2;
	if (str1 > str2 && str1 < str2 + num - 1)
	{
		str1 = str1 + num - 1;//
		str2 = str2 + num - 1;//��str1��str2���ֱ�ָ��ĩβλ�ô�
		while (num)
		{
			*str1 = *str2;
			str1--;
			str2--;
			num--;
		}
	}
	while (num)
	{
		*str1++ = *str2++;
		num--;
	}
}
int main()
{
	char str1[20] = "abcde";
	my_memmove(str1+1, str1 , strlen(str1) + 1);
	printf("%s\n", str1);
	system("pause");
	return 0;
}
#include <stdio.h>
#include <windows.h>
#include <string.h>
//memcpy ���ڴ濽���������޹أ������ֽ�Ϊ��λ
void my_memcpy(void *_str1, void *_str2, int num)
{
	char *str1 = (char *)_str1;//�����������charռ��һ���ֽڵ����ԣ������ú��ȡһ���ֽ����ݣ�
	char *str2 = (char *)_str2;
	while (num)
	{
		*str1++ = *str2++;
		num--;
	}
}
int main()
{
	char str1[8] = "world!";
	char str2[50];
	my_memcpy(str2,str1,strlen(str1)+1);
	printf("%s\n", str2);
	system("pause");
	return 0;
}
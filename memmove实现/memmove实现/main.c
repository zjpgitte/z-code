#include <stdio.h>
#include <windows.h>
//memcpy没有考虑内存重叠的情况，在memmove中对这个进行了考虑
//当内存重叠的时候我们应该考虑是 低->高 还是 高->低
void my_memmove(void *_str1, void *_str2,int num)
{
	char *str1 = (char *)_str1;
	char *str2 = (char *)_str2;
	if (str1 > str2 && str1 < str2 + num - 1)
	{
		str1 = str1 + num - 1;//
		str2 = str2 + num - 1;//让str1和str2都分别指向末尾位置处
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
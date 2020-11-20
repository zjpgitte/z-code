#include <stdio.h>
#include <windows.h>
//在str1中找str2,str1向后走str2不变,最后返回str1
//判断*str1和*str2是否相等，是：P指向str1，q指向str2，比较*p,*q pq分别向后走
//q走到头说明找到了返回str1，否则没找到str1向后走重新进行上述过程
const char *my_strstr(const char *str1, const char *str2)
{
	while (*str1)//str1向后走
	{
		const char *p = str1;//最后要返回str1
		const char *q = str2;
		while (*str2 && *p == *q)//判断是不是对应的每个字符都相同
		{
			p++;
			q++;
		}//循环退出有两种可能 1.*str2 == '\0' 2.*p != *q;
		if (*q == '\0')
		{
			return str1;//如果找到了则返回str1
		}
		str1++;
	}
	return NULL;//当程序执行到这说明没找到。
}
int main()
{
	char str1[] = "abcd 123 abcde 1234";
	char str2[] = "abcd";
	printf("%s\n", my_strstr(str1, str2));
	system("pause");
	return 0;
}
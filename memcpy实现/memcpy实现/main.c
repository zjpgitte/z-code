#include <stdio.h>
#include <windows.h>
#include <string.h>
//memcpy 是内存拷贝与类型无关，它以字节为单位
void my_memcpy(void *_str1, void *_str2, int num)
{
	char *str1 = (char *)_str1;//这里仅仅利用char占用一个字节的属性，解引用后读取一个字节内容；
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
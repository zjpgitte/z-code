#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PrintArray(int *arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void MyMemcpy(void *_dst, const void *_src, int size)
{
	char *dst = (char*)_dst;
	char *src = (char*)_src;//因为是内存拷贝因为强制类型转换尾char这样解引用后就可以逐个字节拷贝
	while (size--)//size是src的字节数量
	{
		*dst = *src;
		dst++;
		src++;
	}
}
void MyMemmove(void *_dst, const void *_src, int size)
{
	char *dst = (char*)_dst;
	char *src = (char*)_src;
	if (dst > src && dst < src+size)//满足内存上述的第二种内存重叠时采用从尾到头的拷贝方式
	{
		for (int i = size-1; i >= 0;--i)
		{
			dst[i] = src[i];
		}
	}
	else//正常情况下采用从头到尾拷贝
	{
		for (int i = 0; i < size; i++)
		{
			dst[i] = src[i];
		}
	}

}

int main()
{
	char src[20] = "hello";
	char dst[20];
	memmove(dst, src, strlen(src) + 1);
	printf("%s\n", dst);

	system("pause");
	return 0;
}

//int main()
//{
//	char src[20] = "hello world";
//	char dst[20] ;
//	/*memcpy(src + 1, src, strlen(src) + 1);
//	printf("%s\n", src);
//	memmove(src + 1, src, strlen(src) + 1);
//	printf("%s\n", src);*/
//	//MyMemcpy(src+1, src, strlen(src) + 1);
//	//printf("%s\n", src);
//	MyMemmove(src+2, src, strlen(src) + 1);
//	printf("%s\n", src);
//	
//
//	system("pause");
//	return 0;
//}
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
	char *src = (char*)_src;//��Ϊ���ڴ濽����Ϊǿ������ת��βchar���������ú�Ϳ�������ֽڿ���
	while (size--)//size��src���ֽ�����
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
	if (dst > src && dst < src+size)//�����ڴ������ĵڶ����ڴ��ص�ʱ���ô�β��ͷ�Ŀ�����ʽ
	{
		for (int i = size-1; i >= 0;--i)
		{
			dst[i] = src[i];
		}
	}
	else//��������²��ô�ͷ��β����
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
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
int CompareInt(const void *_p, const void *_q)//�û�д�ıȽ�ĳ�������ݵĺ������Ƚϵ���ʲô�������û��������˺����������������������մ��Ƚϵ��������ݵ���ʼ��ַ
{											//void* ���Խ�����������ͨ����������ָ��
	const int *p = (int *)_p;
	const int *q = (int *)_q;//�û�Ҫ�Ƚ�ʲô���͵����ݾͶ���ʲô���͵�����
	return *p - *q;
}
void Printnum(int arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void my_qsort(void *_arr, int num, int size, int Compare(void *,void *))
{
	if (NULL == _arr)
	{
		return;
	}
	char *arr = (char *)_arr;           
	for (int i = 0; i < num - 1; i++)//����ʹ��ð������
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (CompareInt(arr+j*size,arr+(j+1)*size) < 0)//�Ƚϵ���ʲô���͵�Ԫ�����û�����������ֻ�ṩ�Ƚϵ�����Ԫ�ص��׵�ַ
			{
				char *temp1 = arr + j*size;//��������ֻ֪���������Ƚϱ������׵�ַ�Լ���С(size)���������ֻ��ͨ������
				char *temp2 = arr + (j + 1)*size;//��������ÿ���ֽڵ����ݽ����������������н���
				int _size = size;
				while (_size)
				{
					char temp = *temp1;
					*temp1 = *temp2;
					*temp2 = temp;
					temp1++;
					temp2++;
					_size--;
				}
			}
		}
	}
}
int main()
{
	int arr[] = { 2, 4, 2, 1, 6, 5, 9, 8, 5, 2, 9 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Printnum(arr, num);
	my_qsort(arr, num, sizeof(int), CompareInt);//��������������Ԫ������arr�������������͵����飬�������������������ʹ�С���������Ƚϼ����ֽ�
	Printnum(arr, num);
	system("pause");
	return 0;
}
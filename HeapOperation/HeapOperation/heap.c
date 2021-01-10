#include "heap.h"
void HeapPrint(Heap *php)
{
	assert(php);
	for (int i = 0; i < php->_size; i++)
	{
		printf("%d ", php->_a[i]);
	}
	printf("\n");
}


void Swap(HPDataType *x, HPDataType *y)
{
	HPDataType temp = *x;
	*x = *y;
	*y = temp;
}

//��С��ʹ�����µ����㷨(ʹ��ǰ���Ǹ�������������ΪС�ѻ���ΪҶ�ӽ��)
//ʱ�临�Ӷ�ΪlogN
void AdjustDown(HPDataType *a, int size, int root)//
{
	assert(a);
	int parent = root;//��¼˫�׽��λ��
	int child = 2 * parent + 1;//��¼ֵ��С�ĺ��ӵ�λ��
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child++;
		}//�ҵ�ֵ��С�ĺ��ӵ�λ��

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}//��֤˫�׵�ֵ�Ⱥ���С
		else
		{
			break;
		}
	}

}

//�ѵĴ���(С��)
//���ѵ�ʱ�临�Ӷ�ΪO(N)����O(NlogN)
//ԭ����ÿ�����µ����ĸ�λ�ò�ͬ���������Ҳ��ͬ
void HeapInit(Heap *php, int *a, int n)
{
	assert(php && a);
	//��ʼ�����е�Ԫ��
	php->_a = (HPDataType *)malloc(sizeof(HPDataType)*n);
	if (php->_a == NULL)
	{
		printf("malloc error!\n");
		exit(0);
	}
	memcpy(php->_a, a, sizeof(HPDataType)*n);//�������е�Ԫ�س�ʼ�����ѵ���
	php->_size = n;
	php->_capacity = n;

	//������
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(php->_a, n, i);
	}//��ÿ������������ΪС��
	
}

//�ѵ�����
void HeapDestory(Heap *php)
{
	assert(php);
	free(php->_a);
	php->_size = 0;
}
void AdjustUp(int *a, int size, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)//child�ߵ�������
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//ѹ��Ԫ��
void HeapPush(Heap *php, int x)
{
	assert(php);
	php->_a[php->_size++] = x;
	AdjustUp(php->_a, php->_size, php->_size - 1);
}
//�����Ѷ�Ԫ��
void HeapPop(Heap *php)
{
	assert(php);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}
//ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap *php)
{
	assert(php);
	return php->_a[0];
}
//�ѵ����ݸ���
int Heapsize(Heap *php)
{
	return php->_size;
}
//�ѵ��п�
int HeapEmpty(Heap *php)
{
	assert(php);
	return !php->_size;
}

//�Ժ���n��Ԫ�ص���������(������)
void HeapSort(int *a, int n)
{
	assert(a);
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//����Ĺؼ��Ѷ��Ͷ�β������ʹ�����µ����㷨����ʱ�临�Ӷ�ΪO(NlogN)��С
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}//ʱ�临�Ӷ�O(NlogN)
}
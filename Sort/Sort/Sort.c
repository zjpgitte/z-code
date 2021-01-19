#include "sort.h"

void PrintArray(int *a, int n)
{
	for (int i = 0; i < n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

//ֱ�Ӳ�������
//ʱ�临�Ӷ� O(N^2)    n��Ԫ��ÿ�ζ�Ҫ���Ѿ��ź����Ԫ�ؽ��бȽ�Ȼ�����
//�����Ѿ������ӽ�����������: O(N)
//�����������ӽ����������� O(N^2)
void InsertSort(int *a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1;++i)//ÿ�� i+1 λ�õ�Ԫ�ز��뵽���Ѿ��ź����Ԫ�ص��в���
	{
		//�������� 
		int end = i; 
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])//
			{
				a[end + 1] = a[end];//����һλ
				--end;
			}
			else
			{
				break;
			}
		}
		//������tmp >= a[end] ��Ҳ������ end �ߵ��� -1,���ս�����ǽ�tmp�ŵ�end+1λ�ô�
		a[end + 1] = tmp;
	}
	
}

//ϣ������
void ShellSort(int *a, int n)
{
	assert(a);
	int gap = n;//ÿ�������Ǽ��Ϊgap��Ԫ�ؽ�������
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		
		//Ԥ����ÿ�ζԼ��Ϊgap��Ԫ�ؽ�������,ʹ����ӽ�����
		//���һ��gap = 1,�൱���ǽ���ֱ�Ӳ�������,����ֱ���ź���
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];//��end + gap λ�õ�Ԫ�ز����Ѿ��ź����Ԫ��������
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;  //
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;  

		}

	}
	
}

void SelectSort(int *a, int n)
{
	int begin = 0;
	int end = n - 1;
	int maxi = 0;
	int mini = 0;
	while (begin < end)
	{
		maxi = mini = begin;
		//��������С��Ԫ��
		for (int i = begin+1; i <= end;i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			Swap(&mini, &maxi);
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}

}

void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1 < n && a[child+1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}

void HeapSort(int *a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
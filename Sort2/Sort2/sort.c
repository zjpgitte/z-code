#include "sort.h"

void PrintArray(int *a, int n)
{
	for (int i = 0; i < n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//ֱ�Ӳ�������
void InsertSort(int *a, int n)
{
	for (int i = 0; i < n - 1;++i)
	{
		int end = i;
		int tmp = a[end + 1];//tmp�ǽ�Ҫ������Ԫ��
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;//end+1�ǲ����λ��
	}
}

//ϣ������
void ShellSort(int *a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//��gap������1��ʱ����е���Ԥ����
		//gap = 1����ֱ�Ӳ�������
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap;++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
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
void Swap(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

//ֱ��ѡ������
void SelectSort(int *a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}

		Swap(&a[max], &a[end]);
		//���min����end����ô�ϴν�������СԪ�ؾͻ�����֮ǰ���Ԫ�ص��Ǹ�λ��
		//��ʱ��Ҫ����min��λ��
		if (min == end)
		{
			Swap(&max, &min);
		}
		Swap(&a[min], &a[begin]);
		begin++;
		end--;
	}
}

//������
void HeapSort(int *a, int n)
{
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0;--i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;//��¼δ��������һ��Ԫ��
	int size = n;//δ�����Ԫ�صĸ���
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//�����Ѷ��Ķ�β
		size--;
		AdjustDown(a, size, 0);//ѡ����Ԫ��
		end--;
	}
}
//���µ����㷨
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;

	while (child < n)
	{
		//�����Һ����нϴ��
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		//���ӱ�˫�״󽻻�
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		//˫���Ѿ����ں��ӣ��������������Ѿ��Ǵ��ֱ���˳�ѭ��
		else
		{
			break;
		}
	}
}

//ð��
void BubbleSort(int *a, int n)
{
	for (int j = 0; j < n - 1;j++)
	{
		int change = 0;
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				Swap(&a[i], &a[i + 1]);
				change = 1;
			}
		}
		if (change == 0)
		{
			break;
		}
	}
	
}
int GetMidIndex(int *a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[right] < a[mid])
		{
			if (a[right] > a[left])
			{
				return right;
			}
			else
			{
				return left;
			}
		}
		else
		{
			return mid;
		}
	}
	else
	{
		if (a[right] > a[mid])
		{
			if (a[left] > a[right])
			{
				return right;
			}
			else
			{
				return left;
			}
		}
		else
		{
			return mid;
		}
	}
}
int PartSort1(int *a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);
	int keyIndex = right;
	while (left < right)
	{
		//���������ұ�key���
		while (left < right && a[left] <= a[keyIndex])
		{
			left++;
		}
		//���������ұ�keyС��
		while (left < right && a[right] >= a[keyIndex])
		{
			right--;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyIndex]);
	return keyIndex;
}
int PartSort2(int *a, int left, int right)
{
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}
int PartSort3(int *a, int left, int right)
{
	int keyIndex = right;
	int prev = left - 1;
	int cur = left;
	while (cur < right)
	{
		if (a[cur] < a[keyIndex] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[++prev], &a[keyIndex]);
	return prev;
}
//��������   ������[left,right]�е���
void QuickSort(int *a, int left, int right)
{
	//��ֻ��һ��Ԫ��ʱ�������
	if (left - right + 1 > 4)
	{
		int mid = PartSort3(a, left, right);
		//��[left,mid-1]�ų�����
		QuickSort(a, left, mid - 1);
		//��[mid+1,right]�ų�����
		QuickSort(a, mid + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
	
}

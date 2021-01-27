#include "sort.h"
#include "Stack.h"


//ֱ�Ӳ�������
void InsertSort(int *a, int n)
{
	//���±�Ϊi��Ԫ�ز��뵽�Ѿ��ĺ����������
	for (int i = 1; i < n;i++)
	{
		//end��¼�Ѿ��ź���Ĳ���δ��temp�Ƚ�Ԫ�ص��±꣬��ʼֵΪ 0
		int end = i - 1;

		//temp��¼��������Ҫ�����Ԫ�ص�ֵΪa[end+1],��ʱend+1λ�ÿ������
		int temp = a[end + 1];

		while (end >= 0)
		{
			//�ұ�tempС��Ԫ��
			if (a[end] > temp)
			{
				//��a[end] > temp����a[end]����Ƶ�end+1λ�ô�,��ʱendλ�ÿ������
				a[end + 1] = a[end];
				end--;
			}
			else//a[end] <= temp��˵���ҵ��˱�tempС��Ԫ��,Ϊa[end]
			{
				break;
			}
		}
		//temp���뵽a[end]�ĺ���end+1λ�ô�; ��end = -1��ͬ�����뵽end+1λ�ô�
		a[end + 1] = temp;
	}
}

//ϣ������
void ShellSort(int *a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		//ÿ�ζ��Ѽ��Ϊgap��Ԫ�ؽ�������
		gap = gap / 3 + 1;
		for (int i = gap; i < n; ++i)//i��ÿ�����������Ԫ�ص��±�
		{
			int end = i - gap;//end�Ǵ��Ƚ�Ԫ��
			int temp = a[end + gap];//��������Ԫ����temp����
			while (end >= 0)
			{
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = temp;

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
	
	//��[begin,end]��ѡ����С�ķŵ�benginλ�ô���ѡ�����ķŵ�endλ�ô�
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;//��������ĵ�һ��Ԫ�ؾ���������С��

		//��[begin,end]ѡ��������maxi��¼�±�,��С����mini��¼
		for (int i = begin; i <= end;i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		//�����ķŵ�end����С�ķŵ�begin
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			Swap(&maxi, &mini);
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child+1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
//������
void HeapSort(int *a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0;i--)
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

//ð������
void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n - 1;i++)
	{
		int change = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
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
	if (a[mid] < a[left])
	{
		if (a[mid] < a[right])
		{
			if (a[left] < a[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
		else
		{
			return mid;
		}
	}
	else
	{
		if (a[mid] >= a[right])
		{
			if (a[left] >= a[right])
			{
				return left;
			}
			else
			{
				return right;
			}
		}
		else
		{
			return mid;
		}
	}
}
//����ָ�뷨
int PartSort1(int *a, int left, int right)
{
	//����ȡ��,��֤rightλ�ô���Ԫ�ز���������С��
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);

	int keyIndex = right;
	//���������ұ�key��ģ����������ұ�keyС��,��������λ��
	while (left < right)
	{
		while (left < right && a[left] <= a[keyIndex])
		{
			left++;
		}
		while (left < right && a[right] >= a[keyIndex])
		{
			right--;
		}
		Swap(&a[left], &a[right]);
	}

	//��key�ŵ�����λ��
	Swap(&a[left], &a[keyIndex]);
	return left;
}
//�ڿӷ�
int PartSort2(int *a, int left, int right)
{
	//����ȡ��,��֤rightλ�ô���Ԫ�ز���������С��
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	int key = a[right];//�����ұߵ�Ԫ�ر����������ұ߾���һ����
	while (left < right)
	{
		//����߿�ʼ�ұ�key���
		while (left < right && a[left] <= key)
		{
			left++;
		}
		//�ҵ�����ұߵĿ�,������߾��γ���һ����
		a[right] = a[left];

		//���ұ������ұ�keyС��
		while (left < right && a[right] >= key)
		{
			right--;
		}
		//�ҵ������ߵĿӣ������ұ����γ���һ����
		a[left] = a[right];
	}
	//key����left��rigright����λ�õĿ�
	a[left] = key;
	return left;
}
//ǰ��ָ�뷨
int PartSort3(int *a, int left, int right)
{
	//����ȡ��,��֤rightλ�ô���Ԫ�ز���������С��
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	int keyIndex = right;
	int cur = left;
	int prev = left - 1;//prev�Ǳ�keyС�����һ��Ԫ��,prev+1�Ǳ�key��ĵ�һ��Ԫ��
	//cur�ӵ�һ��λ���ұ�keyС�ķŵ�prev+1��λ�ô�
	while (cur < right)
	{
		if (a[cur] < a[keyIndex] &&  ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev + 1], &a[keyIndex]);
	return prev + 1;
}
void QSort(int *a, int left, int right)
{
	//�ݹ����,ֻʣһ��Ԫ�ز�����
	if (left >= right)
	{
		return;
	}
	int midIndex = PartSort3(a, left, right);
	QSort(a, left, midIndex - 1);
	QSort(a, midIndex + 1,right);
}
//��������
void QuickSort(int *a, int n)
{
	int left = 0;
	int right = n - 1;
	QSortNonR(a, left, right);
}
//��������ǵݹ�
//�ݹ�ת��Ϊ�ǵݹ����ַ�ʽ��1.ѭ����쳲������� 2.��ջģ��
//�ǵݹ�ĺô���1.���Ч��ʡȥ�˿���ջ֡��ʱ��(������ߵıȽ���)
			//  2.�ڴ���ջ�Ŀռ��Ƿǳ�С��һ����M����8M�������ѿռ���G�����
			//  3.��ջģ��ǵݹ����ĵ��Ƕѿռ������Ч��ֹջ�����
void QSortNonR(int *a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st))
	{
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		int midIndex = PartSort3(a, left, right);

		//����[left,midIndex-1] [midIndex+1,right] ʱ���²㺯��������ջ
		//��ջ�������ڵ������´�ѭ��ʱ����е�������
		//�����䲻����ʱ(���䲻���ڻ�������ֻ��һ��Ԫ��)���򲻽�����ջ�������´�ѭ�������е�������
		if (midIndex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, midIndex+1);
		}
		if (midIndex - 1 > left )
		{
			StackPush(&st, midIndex-1);
			StackPush(&st, left);
		}


	}
}

void SortArray(int *a, int begin1, int end1, int begin2, int end2,int *temp)
{
	int left = begin1;
	int right = end2;
	//[begin1,end1] [begin2,end2] ���������������
	//�ϲ���һ����������
	int i = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}

	//������������ʣ������ݷŵ�temp����ĺ���
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	//��temp�������������д�� a ������
	memcpy(a + left, temp, sizeof(int)*(right - left + 1));
}



void _MergeSort(int *a, int left, int right,int *temp)
{
	if (left >= right)
	{
		return;
	}
	//����������ֳ���������[left,mid] [mid+1,right]
	int mid = (left + right) / 2;

	//��[left,mid]���й鲢����
	_MergeSort(a, left, mid, temp);
	//��[mid+1,right]���й鲢����
	_MergeSort(a, mid+1, right, temp);

	//��[left,mid]��[mid+1,right]�����������������ʱ��Ҫ��������������кϲ�ʹ�� [left,right] ��������������������	
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	SortArray(a, begin1, end1, begin2, end2, temp);
}

//�鲢�ݹ�����
//�鲢�����ʱ�临�Ӷȣ�O(N*logN)
//������Ϊ���һ�κϲ���ʱ�临�Ӷ�O(N),�����ڶ����ε�ʱ�临�Ӷ�ΪO(N/2)����ô�ڶ����ʱ�临�ӵ�ΪO(N)
//�ݹ����Ĳ���ΪO(logN)�����ܵ�ʱ�临�Ӷ�ΪO(N*logN)

void MergeSort(int *a, int n)
{
	int *temp = malloc(sizeof(int)*n);

	_MergeSort(a, 0, n - 1,temp);

}

//�鲢�ǵݹ�����
void MergeSortNonR(int *a, int n)
{
	int *temp = malloc(sizeof(int)*n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			
			//�ϲ���ʱ���ǽ�����������ĺϲ�������ڶ�������ķ�Χ������(���ڶ������鲻����)�򲻽��кϲ� 
			//��������µ�һ������ķ�Χ��������end2���ܴ���Ҳ���ܲ�����
			//���ǲ������Ƿ���ڣ�ֻҪ�ڶ������鲻���ھͲ����кϲ�
			if (begin2 >= n)
			{
				break;
			}

			//�ߵ���˵���ڶ����������������������䲻����,��ʱ�ڶ���������ڽ�����Ԫ�صĸ������һ�����鲻ͬ
			//��Ҫ����������Ĵ�СΪn-1��֤����Խ�磬Ȼ���ٺ͵�һ������ϲ� ���ϲ���ʱ����������Ԫ�صĸ�����һ����ͬ
			if (end2 >= n)
			{
				end2 = n-1;
			}
			
			//����������кϲ�����
			SortArray(a, begin1, end1, begin2, end2, temp);
		}
		gap *= 2;
	}
	

}
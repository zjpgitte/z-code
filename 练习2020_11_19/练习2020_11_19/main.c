#include <stdio.h>
#include <windows.h>
//�۰����
void BinarySearch(int arr[], int num, int n)
{
	int start = 0;
	int end = num - 1;
	int mid = (start + end) / 2;
	while (start <= end)
	{
		if (n > arr[mid])
		{
			start = mid + 1; // ������Ϊ�����Ѿ�ȷ�� arr[mid] ����Ҫ�ҵ����Ը���start��ʱ��ֵΪmid+1.�������endʱͬ��
			mid = (start + end) / 2;
		}
		else if (n < arr[mid])
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else
		{
			printf("�±꣺%d\n", mid);
			break;
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 20, 89, 367 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int n = 1;
	BinarySearch(arr, num,n);
	system("pause");
	return 0;
}
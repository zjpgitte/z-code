#include<stdio.h>
#include <windows.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
		unsigned long long a = 0;
		for (int i = 0; i < ASize; i++)
		{
			a = a*10 + A[i];
		}//求A对应的数字a
		a += K;
		unsigned long long s = a;
		int n = 0;
		if (s == 0)
		{
			*returnSize = 1;
			int *Arr = (int*)malloc(sizeof(int)*(n + 1));
			Arr[0] = 0;
			return Arr;
		}
		else
		{
			while (s)
			{
				n++;
				s /= 10;
			}
			*returnSize = n;
			int *Arr = (int*)malloc(sizeof(int)*n);
			while (a && n >= 0)
			{
				Arr[n - 1] = a % 10;
				a /= 10;
				n--;
			}
			return Arr;
		}

	}
//这种情况下会发生越界；
int main()
{
	int A[] = { 3, 8, 0, 3, 0, 2, 7, 0, 7, 6, 4, 9, 9, 1, 7, 6, 6, 1, 6, 4};
	int k = 670;
	int num = sizeof(A) / sizeof(A[0]);
	int b;
	int *a = addToArrayForm(A, num, k, &b);
	for (int i = 0; i < b; i++)
	{
		printf("%d ", a[i]);
	}

	system("pause");
	return 0;
}
#include <stdio.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* singleNumbers(int* nums, int numsSize, int* returnSize){
	//ͨ��������鵱�е�ÿ��Ԫ������������������Ľ��ret ��ret != 0
	//��ôret�Ķ�����������һ����һλ�� 1���������������ֵĶ����������ڸñ���λ��һ����1 ��һ����0�� 
	//����λ��1�ķ�Ϊһ�飬��0�ķ�Ϊһ�飬�ٽ����������ֱ���򼴿ɵĵ����ս����
	int ret = 0;
	returnSize[0] = 0;
	returnSize[1] = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}
	int pos = 0;
	while (pos < 31)
	{
		if (ret & (1 << pos)) // ret��λ�� 1 << pos λ���ж���һλ��1����λ��Ľ��һ����Ϊ0������Ϊ1��Ҳ���ܲ���1.
		{
			break;
		}
		pos++;
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] & (1 << pos))
		{
			returnSize[0] ^= nums[i];
		}
		else
		{
			returnSize[1] ^= nums[i];
		}
	}
	return returnSize;
}
void Print(int *arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int nums[100] = { 4, 1, 4, 6 };
	int numsSize = 4;
	int returnSize[2] = { 0 };
	singleNumbers(nums, numsSize, returnSize);
	Print(returnSize, 2);
	system("pause");
	return 0;
}
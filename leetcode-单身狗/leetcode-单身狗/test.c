#include <stdio.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int* singleNumbers(int* nums, int numsSize, int* returnSize){
	//ͨ��������鵱�е�ÿ��Ԫ������������������Ľ��ret ��ret != 0
	//��ôret�Ķ�����������һ����һλ�� 1���������������ֵĶ����������ڸñ���λ��һ����1 ��һ����0�� 
	//����λ��1�ķ�Ϊһ�飬��0�ķ�Ϊһ�飬�ٽ����������ֱ���򼴿ɵĵ����ս����
	int ret = 0;
	
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];//ret������ֻ����һ�ε������Ľ��
	}
	int pos = 0;
	while (pos < 31)
	{
		if (ret & (1 << pos)) // ret��λ�� 1 << pos λ���ж���һ����λ��1��
		{
			break;
		}
		pos++;
	}//���յõ���pos����������ֻ����һ�ε�������λ��ͬ����һλ
	int *returnNums = (int *)malloc(sizeof(int)* 2);//���ֻ����һ�ε���������
	returnNums[0] = 0;
	returnNums[1] = 0;// ��ʼ��Ϊ0 .��Ϊ�κ������0����������
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] & (1 << pos))
		{
			returnNums[0] ^= nums[i];//���鵱�е�posλ����0�������õ����
		}
		else
		{
			returnNums[1] ^= nums[i];//���鵱�е�posλ��0�������õ����
		}
	}
	*returnSize = 2;
	return returnNums;
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
	int size = 0;
	int *a = singleNumbers(nums, numsSize,&size );
	Print(a, size);
	system("pause");
	return 0;
}
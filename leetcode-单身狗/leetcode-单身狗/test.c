#include <stdio.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int* singleNumbers(int* nums, int numsSize, int* returnSize){
	//通过异或数组当中的每个元素求出那两个数字异或的结果ret ，ret != 0
	//那么ret的二进制序列中一定有一位是 1（即：这两个数字的二进制序列在该比特位上一个是1 另一个是0） 
	//将该位是1的分为一组，是0的分为一组，再将这两组数分别异或即可的到最终结果。
	int ret = 0;
	
	for (int i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];//ret是两个只出现一次的数异或的结果
	}
	int pos = 0;
	while (pos < 31)
	{
		if (ret & (1 << pos)) // ret按位与 1 << pos 位来判断哪一比特位是1。
		{
			break;
		}
		pos++;
	}//最终得到的pos就是那两个只出现一次的数比特位不同的那一位
	int *returnNums = (int *)malloc(sizeof(int)* 2);//存放只出现一次的那两个数
	returnNums[0] = 0;
	returnNums[1] = 0;// 初始化为0 .因为任何书异或0都是它本身
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] & (1 << pos))
		{
			returnNums[0] ^= nums[i];//数组当中第pos位不是0的数异或得到结果
		}
		else
		{
			returnNums[1] ^= nums[i];//数组当中第pos位是0的数异或得到结果
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
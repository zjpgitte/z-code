#include <stdio.h>
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* singleNumbers(int* nums, int numsSize, int* returnSize){
	//通过异或数组当中的每个元素求出那两个数字异或的结果ret ，ret != 0
	//那么ret的二进制序列中一定有一位是 1（即：这两个数字的二进制序列在该比特位上一个是1 另一个是0） 
	//将该位是1的分为一组，是0的分为一组，再将这两组数分别异或即可的到最终结果。
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
		if (ret & (1 << pos)) // ret按位与 1 << pos 位来判断哪一位是1。按位与的结果一定不为0，可能为1，也可能不是1.
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
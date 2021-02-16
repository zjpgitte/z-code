#include "test.h"

int thirdMax(int* nums, int numsSize){
	long min = nums[0];
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] < min)
		{
			min = nums[i];
		}
	}

	long firstMax = min, secondMax = min - 1, thirdMax = min - 2;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == firstMax || nums[i] == secondMax || nums[i] == thirdMax)
		{
			continue;
		}
		if (nums[i] > firstMax)
		{
			thirdMax = secondMax;
			secondMax = firstMax;
			firstMax = nums[i];
		}
		else if (nums[i] > secondMax)
		{
			thirdMax = secondMax;
			secondMax = nums[i];
		}
		else if (nums[i] > thirdMax)
		{
			thirdMax = nums[i];
		}
	}

	if (thirdMax == min - 1 || thirdMax == min - 2)
	{
		return firstMax;
	}
	return thirdMax;
}

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize){
	int *nums = malloc(sizeof(int)*(digitsSize + 1));
	int nextNum = 1; //进位
	int cur = digitsSize - 1;
	int i = 0;
	while (cur >= 0)
	{
		int ret = digits[cur--] + nextNum;
		if (ret > 9)
		{
			ret -= 10;
			nextNum = 1;
			nums[i++] = ret;
		}
		else
		{
			nextNum = 0;
			nums[i++] = ret;
		}
	}
	if (nextNum == 1)
	{
		nums[i++] = 1;
	}

	int left = 0, right = i - 1;
	while (left < right)
	{
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++;
		right--;
	}

	*returnSize = i;
	return nums;

}

int pivotIndex(int* nums, int numsSize){
	int sum = 0, preSum = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		sum += nums[i];
	}

	//找一个元素：该元素左边的元素和等于右边的元素和
	for (int i = 0; i < numsSize; ++i)
	{
		if (preSum == sum - preSum - nums[i])
		{
			//找到后返回当前元素下标
			return i;
		}
		preSum += nums[i];
	}

	//循环结束说明没找到
	return -1;

}
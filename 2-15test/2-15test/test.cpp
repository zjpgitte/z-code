#include "test.h"


//仅翻转字母
char * reverseOnlyLetters(char * S){
	char *left = S, *right = S;
	while (*right != '\0')
	{
		right++;
	}
	right--;
	while (left < right)
	{
		if (!(*left >= 'A' && *left <= 'Z' || *left >= 'a' && *left <= 'z'))
		{
			left++;
		}
		else if (!(*right >= 'A' && *right <= 'Z' || *right >= 'a' && *right <= 'z'))
		{
			right--;
		}
		else
		{
			char temp = *left;
			*left = *right;
			*right = temp;
			left++;
			right--;
		}
	}

	return S;

}



//有序数组的平方
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* sortedSquares(int* nums, int numsSize, int* returnSize){
	for (int i = 0; i < numsSize; i++)
	{
		nums[i] *= nums[i];
	}

	int *arr = (int*)malloc(sizeof(int)*numsSize);
	int left = 0, right = numsSize - 1;
	int i = numsSize - 1;
	while (left <= right)
	{
		if (nums[left] > nums[right])
		{
			arr[i--] = nums[left++];
		}
		else
		{
			arr[i--] = nums[right--];
		}
	}

	memcpy(nums, arr, sizeof(int)*numsSize);
	free(arr);

	*returnSize = numsSize;
	return nums;
}



//合并有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int i = m + n - 1;
	int cur1 = m - 1, cur2 = n - 1;
	//nums1和nums2从尾到头找大的，放到nums1的后面
	while (cur1 >= 0 && cur2 >= 0)
	{
		if (nums1[cur1] >= nums2[cur2])
		{
			nums1[i--] = nums1[cur1--];
		}
		else
		{
			nums1[i--] = nums2[cur2--];
		}
	}

	//将两个数组剩余元素放到nums1中
	while (cur1 >= 0)
	{
		nums1[i--] = nums1[cur1--];
	}
	while (cur2 >= 0)
	{
		nums1[i--] = nums2[cur2--];
	}
}


//返回最后一个单词长度
int lengthOfLastWord(char * s){
	if (s == NULL)
	{
		return 0;
	}
	char *begin = s;
	char *end = s;

	//end 走到尾
	while (*end != '\0')
	{
		end++;
	}

	//end走到最后一个单词的尾字母
	end--;
	while (*end == ' ' && end != s)
	{
		end--;
	}

	//begin走到最后一个单词的前面
	begin = end;
	while (*begin != ' ' && begin != s)
	{
		begin--;
	}

	if (*begin == ' ')
	{
		return end - begin;
	}
	else
	{
		return end - begin + 1;
	}



}


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int left = 0, right = ASize - 1;
	while (left < right)
	{
		while (left < right && A[left] % 2 == 0)
		{
			left++;
		}
		while (left < right && A[right] % 2 != 0)
		{
			right--;
		}
		int temp = A[left];
		A[left] = A[right];
		A[right] = temp;
		left++;
		right--;
	}

	*returnSize = ASize;
	return A;
}
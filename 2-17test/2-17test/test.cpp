#include "test.h"

char * addBinary(char * a, char * b){
	int aSize = strlen(a) + 1;
	int bSize = strlen(b) + 1;
	int size = aSize > bSize ? aSize : bSize;
	char *returnArray = malloc(size + 1);

	//pa,pb��ָ�����һ��Ԫ��
	int pa = strlen(a) - 1;
	int pb = strlen(b) - 1;
	int i = 0; //i������λ��

	//�����ֵ
	char nextNum = '0';  // ��¼��λ
	while (pa >= 0 || pb >= 0)
	{
		char A = '0', B = '0';
		if (pa >= 0)
		{
			A = a[pa--];
		}
		if (pb >= 0)
		{
			B = b[pb--];
		}

		char ret = A + B + nextNum - 2 * '0'; //��ͬλ�ϵĺ�
		if (ret > '1')
		{
			nextNum = '1';
			ret -= 2;
			returnArray[i++] = ret;
		}
		else
		{
			nextNum = '0';
			returnArray[i++] = ret;
		}

	}

	if (nextNum == '1')
	{
		returnArray[i++] = nextNum;
	}

	//��������
	int left = 0, right = i - 1;
	while (left < right)
	{
		int temp = returnArray[left];
		returnArray[left] = returnArray[right];
		returnArray[right] = temp;
		left++;
		right--;
	}

	returnArray[i] = '\0';

	return returnArray;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	//һ�������㷨
	// int* returnArry = (int*)malloc(sizeof(int)*2);
	// *returnSize = 2;
	// for(int i = 0; i < numsSize; i++)
	// {
	//     for(int j = i+1; j < numsSize; j++)
	//     {
	//         if(nums[i] + nums[j] == target)
	//         {
	//             returnArry[0] = i;
	//             returnArry[1] = j;
	//             return returnArry;
	//         }
	//     }
	// }


	// return returnArry;


	//������ϣ��
	//�����ֵ����Сֵ

	int min = nums[0], max = nums[0];
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] > max)
		{
			max = nums[i];
		}
		if (nums[i] < min)
		{
			min = nums[i];
		}
	}
}
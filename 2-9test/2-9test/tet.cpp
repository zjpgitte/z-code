void Revorse(int *a, int left, int right)
{
	while (left < right)
	{
		int temp = a[left];
		a[left] = a[right];
		a[right] = temp;
		left++;
		right--;
	}
}

void rotate(int* nums, int numsSize, int k){
	if (k <= 0)
	{
		return;
	}
	k %= numsSize;

	//整体逆序
	Revorse(nums, 0, numsSize);
	//前k个逆序 ， [0, k-1]
	Revorse(nums, 0, k - 1);
	//后n-k个数逆序 [k, numsSize-1]
	Revorse(nums, k, numsSize - 1);


}
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

	//��������
	Revorse(nums, 0, numsSize);
	//ǰk������ �� [0, k-1]
	Revorse(nums, 0, k - 1);
	//��n-k�������� [k, numsSize-1]
	Revorse(nums, k, numsSize - 1);


}
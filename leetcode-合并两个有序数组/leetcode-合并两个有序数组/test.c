#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	//�������������������ֱ����������鵱���� ����
	//�ŵ�nums1 ������� 
	//���nums2ʣ��Ԫ�طŵ�nums1��(��ʣ��Ԫ��λΪ 0 ����ִ�����һ��)
	int inums1 = m - 1, inums2 = n - 1, jnums1 = m + n - 1;
	while (inums1 >= 0 && inums2 >= 0)
	{
		if (nums1[inums1] > nums2[inums2])
		{
			nums1[jnums1] = nums1[inums1];
			jnums1--;
			inums1--;
		}
		else
		{
			nums1[jnums1] = nums2[inums2];
			jnums1--;
			inums2--;
		}
	}//��nums1 ��num2 ������ηŵ�nums1����
	while (inums2 >= 0)
	{
		nums1[jnums1] = nums2[inums2];
		inums2--;
		jnums1--;
	}//nums2����ʣ����ŵ�nums1��λ��,
	//��nums1��ʣ�࣬ʣ�����ЩԪ��ԭ������nums1�������ƶ�

}
void Print(int *nums1, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", nums1[i]);
	}

}
int main()
{
	int nums1[10] = { 1, 2, 3 };
	int nums2[] = { 2, 5, 6 };
	int m = 3, n = 3;
	int num1 = sizeof(nums1) / sizeof(nums1[0]);
	int num2 = sizeof(nums2) / sizeof(nums2[0]);
	merge(nums1, num1,m, nums2, num2,n);
	Print(nums1, m+n);
	system("pause");
	return 0; 
}
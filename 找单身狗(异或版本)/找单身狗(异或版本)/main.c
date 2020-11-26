#include <stdio.h>
#include <windows.h>
//主要思想：想办法将数组当中这两个数字分开；
// 将数组中的所有数字全部异或，得到的结果(ret)一定这两个数字异或之后的结果
//那么ret的二进制序列中一定有一个比特位是1，而在这两个数字对应的比特位上一定是有一个是1，有一个是0
//将该位是1的分到一组，是0的分到一组。将两组数分别异或就会得到这两个数字。
// 异或的基本性质：  2、相同的数异或为0 3、和0异或是他本身 4、和1异或相当于取反
void Search(int arr[], int num)
{
	int ret = 0;
	for (int i = 0; i < num; i++)//求这几个数异或之后的结果（即：其中两个不相同的数异或的结果）
	{
		ret ^= arr[i];
	}
	int pos = 0;
	for (int i = 0; i < 32; i++)//找ret中比特位是1的那一位(第pos位)
	{
		if ((ret & (1 << i)) != 0)
		{
			pos = i;
			break;
		}
	}
	int ret1 = 0;
	int ret2 = 0;
	for (int i = 0; i < num; i++)
	{
		if ((arr[i] & (1 << pos)) != 0)
		{
			ret1 ^= arr[i];
		}
		else
		{
			ret2 ^= arr[i];//通过判断第pos位是否为1将这两个数分开。
		}
	}
	printf("%d\n", ret1);
	printf("%d\n", ret2);

}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 5 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Search(arr,num);
	system("pause");
	return 0;
}
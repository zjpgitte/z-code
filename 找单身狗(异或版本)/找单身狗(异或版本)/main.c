#include <stdio.h>
#include <windows.h>
//��Ҫ˼�룺��취�����鵱�����������ַֿ���
// �������е���������ȫ����򣬵õ��Ľ��(ret)һ���������������֮��Ľ��
//��ôret�Ķ�����������һ����һ������λ��1���������������ֶ�Ӧ�ı���λ��һ������һ����1����һ����0
//����λ��1�ķֵ�һ�飬��0�ķֵ�һ�顣���������ֱ����ͻ�õ����������֡�
// ���Ļ������ʣ�  2����ͬ�������Ϊ0 3����0����������� 4����1����൱��ȡ��
void Search(int arr[], int num)
{
	int ret = 0;
	for (int i = 0; i < num; i++)//���⼸�������֮��Ľ��������������������ͬ�������Ľ����
	{
		ret ^= arr[i];
	}
	int pos = 0;
	for (int i = 0; i < 32; i++)//��ret�б���λ��1����һλ(��posλ)
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
			ret2 ^= arr[i];//ͨ���жϵ�posλ�Ƿ�Ϊ1�����������ֿ���
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
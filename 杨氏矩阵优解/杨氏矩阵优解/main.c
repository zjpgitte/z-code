#include <stdio.h>
#include <windows.h>
#define row 3
#define col 3
//从最右上角的数开始找 ，若要找的数大于右上角的数则 向下走 否则 向左走
void Search(int arr[][col], int x, int y, int num)
{ 
	int i = 0;
	int j = y - 1;
	while (i >= 0 && j <= y - 1)
	{
		if (num > arr[i][j])
		{
			i++;
		}
		else if (num < arr[i][j])
		{
			j--;
		}
		else
		{
			printf("下标：%d %d", i, j);
			break;
		}

	}
}
int main()
{
	int arr[row][col] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int num = 9;
	Search(arr, row, col, num);
	system("pause");
	return 0;
}
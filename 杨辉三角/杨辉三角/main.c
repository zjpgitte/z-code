#include<stdio.h>
#include<windows.h>
#define MAX 100
#define MAX 100
void PrintYangTriangle(int row)
{
	int arr[MAX][MAX];
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		arr[i][j] = 1; arr[i][i-j] = 1;
		for ( j = 1; j <= i - 1; j++)
		{
			arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row - i; j++)
			printf(" ");
		for (int j = 0; j <= i; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int row = 9;
	PrintYangTriangle(row);
	system("pause");
	return 0;
}
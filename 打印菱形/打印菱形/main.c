#include<stdio.h>
#include<windows.h>
#define row 7
#define col 13
void Print()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col / 2 - i; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < 2 * (i + 1) - 1; k++)
		{
			printf("*");
		}
		printf("\n");
		
	}
	for (int i = 0; i < row - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < col - 2 * (i + 1); j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
int main()
{
	Print();
	system("pause");
	return 0;
}
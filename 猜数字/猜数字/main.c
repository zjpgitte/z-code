#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void Menu()
{
	printf("1.play\n");
	printf("2.quit\n");
}
void game()
{
	int num = 0;
	srand((unsigned) time(NULL));
	int Rand = rand() % 10;
	printf("请输入你心目中的数字：");
	while (1)
	{
		scanf("%d", &num);
		if (num < Rand)
		{
			printf("猜小了\n");
			printf("请重新输入：");
		}
		else if (num > Rand)
		{
			printf("猜大了\n");
			printf("请重新输入：");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
	}
	printf("还来不\n");
}
int main()
{

	int select = 0;
	int quit = 0;
	while (!quit)
	{
		Menu();
		printf("请输入序号：");
		scanf("%d", &select);
		switch (select)
		{
		case 1:game();
			 break;
		case 2:quit = 1;
			 break;
		}
	}
	system("pause");
	return 0;
}
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
	printf("����������Ŀ�е����֣�");
	while (1)
	{
		scanf("%d", &num);
		if (num < Rand)
		{
			printf("��С��\n");
			printf("���������룺");
		}
		else if (num > Rand)
		{
			printf("�´���\n");
			printf("���������룺");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			break;
		}
	}
	printf("������\n");
}
int main()
{

	int select = 0;
	int quit = 0;
	while (!quit)
	{
		Menu();
		printf("��������ţ�");
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
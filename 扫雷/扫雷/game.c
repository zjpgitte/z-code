#include"game.h"
void show(char board[][COL])
{
	printf("   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 |");
	printf("\n");
	printf("--------------------------------------------\n");
	for (int i = 1; i < ROW - 1; i++)
	{
		printf("%2d |", i);
		for (int j = 1; j < COL - 1; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		printf("--------------------------------------------\n");
	}
}
char Num(char BombBoard[][COL],int  x,int  y)
{
	return ( (BombBoard[x - 1][y - 1] + BombBoard[x - 1][y] + BombBoard[x - 1][y + 1] + \
		BombBoard[x][y - 1] + BombBoard[x][y + 1] + \
		BombBoard[x + 1][y - 1] + BombBoard[x + 1][y] + BombBoard[x + 1][y + 1]) - 8 * '0');
}
char Player(char ChesBoard[][COL],char BombBoard[][COL])
{
	int x = 0;
	int y = 0;
	printf("请输入坐标:");
	scanf("%d %d", &x, &y);
	if (BombBoard[x][y] == '1')
	{
		return 'L';
	}
	while (1)
	{
		if (ChesBoard[x][y] == '*')
		{
			char num = Num(BombBoard, x, y)+'0';
			ChesBoard[x][y] = num;
			return 'N';
			break;
		}
		else
		{
			printf("请重新输入：");
		}
	}
	

}
void Computer(char BombBoard[][COL])
{
	int x = 1;
	int y = 1;
	srand((unsigned)time(NULL));
	for (int i = 0; i < NUM; i++)
	{
		x = rand() % 11;
		y = rand() % 11;
		if (x > 0 && y > 0)
		{
			BombBoard[x][y] = '1';
		}
		else
		{
			--i;
		}
	}
}
void game()
{
	char ChesBoard[ROW][COL], BombBoard[ROW][COL];
	memset(ChesBoard, '*', sizeof(ChesBoard));
	memset(BombBoard, '0', sizeof(BombBoard));
	
	Computer(BombBoard);     //生成随机炸弹
	while (1)
	{
		show(ChesBoard);
		char ret=Player(ChesBoard, BombBoard);
		
		if (ret == 'L')
		{
			printf("你被炸死了！\n");
			break;
		}
		system("cls");
		
	}
	show(BombBoard);

}
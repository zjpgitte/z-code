#include "game.h"
void Menu()
{
	printf("1.play\n");
	printf("2.exit\n");
}
void ShowBoard(char ChesBoard[][COL])
{
	printf(" | 0 | 1 | 2 |  \n");
	printf("--------------\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d|", i );
		for (int j = 0; j < 3; j++)
		{
			printf(" %c |", ChesBoard[i][j]);
		}
		printf("\n--------------\n");
		
	}
	printf("\n");
}
void Player(char ChesBoard[][COL])
{
	int x = 0;
	int y = 0;
	printf("输入坐标:");
	while (1)
	{
		
		scanf("%d %d", &x, &y);
		if (ChesBoard[x][y] == ' ')
		{
			ChesBoard[x][y] = '1';
			break;
		}
		else printf("重新输入坐标:");
	}
	
}
char Judge(char ChesBoard[][COL])
{
	if ((ChesBoard[0][0] == ChesBoard[0][1] && ChesBoard[0][1] == ChesBoard[0][2] && (ChesBoard[0][0] == '1'  || ChesBoard[0][0] == '0')) || \
		(ChesBoard[1][0] == ChesBoard[1][1] && ChesBoard[1][1] == ChesBoard[1][2] && (ChesBoard[1][0] == '1'  || ChesBoard[1][0] == '0')) || \
		(ChesBoard[2][0] == ChesBoard[2][1] && ChesBoard[2][1] == ChesBoard[2][2] && (ChesBoard[2][0] == '1'  || ChesBoard[2][0] == '0')) || \
		(ChesBoard[0][0] == ChesBoard[1][0] && ChesBoard[1][0] == ChesBoard[2][0] && (ChesBoard[0][0] == '1' || ChesBoard[0][0] == '0')) || \
		(ChesBoard[0][1] == ChesBoard[1][1] && ChesBoard[1][1] == ChesBoard[2][1] && (ChesBoard[0][1] == '1' || ChesBoard[0][1] == '0')) || \
		(ChesBoard[0][2] == ChesBoard[1][2] && ChesBoard[1][2] == ChesBoard[2][2] && (ChesBoard[0][2] == '1' || ChesBoard[0][2] == '0')) || \
		(ChesBoard[0][0] == ChesBoard[1][1] && ChesBoard[1][1] == ChesBoard[2][2] && (ChesBoard[0][0] == '1'  || ChesBoard[0][0] == '0')) || \
		(ChesBoard[0][2] == ChesBoard[1][1] && ChesBoard[1][1] == ChesBoard[2][0] && (ChesBoard[0][2] == '1'  || ChesBoard[0][2] == '0')))
		return 'W';
	 else if (ChesBoard[0][0] != ' ' && ChesBoard[0][1] != ' ' && ChesBoard[0][2] != ' '&&\
		     ChesBoard[1][0] != ' ' && ChesBoard[1][1] != ' ' && ChesBoard[1][2] != ' '&&\
		     ChesBoard[2][0] != ' ' && ChesBoard[2][1] != ' ' && ChesBoard[2][2] != ' ' )
		return 'H';
	else return 'N';
}
void Computer(char ChesBoard[][COL])
{
	srand((unsigned) time(NULL));
	int x = rand() % 3;
	int y = rand() % 3;
	while (1)
	{
		if (ChesBoard[x][y] == ' ')
		{
			ChesBoard[x][y] = '0';
			break;
		}
		else 
		{
			srand((unsigned)time(NULL));
			x = rand() % 3;
			y = rand() % 3;
		}
		
	}
}
void Game()
{
	char ChesBoard[ROW][COL];
	memset(ChesBoard, ' ', sizeof(ChesBoard));
	
	while (1)
	{
		ShowBoard(ChesBoard);
		Player(ChesBoard); 
		if (Judge(ChesBoard) == 'W')
		{
			printf("恭喜你，你赢了！\n");
			break;
		}
		else if (Judge(ChesBoard)== 'H')
		{
			printf("和棋!\n");
			break;
		}
		Computer(ChesBoard);
		
		if (Judge(ChesBoard) == 'W')
		{
			printf("你输了！\n");
			break;
		}
		else if (Judge(ChesBoard) == 'H')
		{
			printf("和棋!\n");
			break;
		}
		system("cls");
	}
	ShowBoard(ChesBoard);
}
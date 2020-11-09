#include"game.h"
int main()
{
	int quit = 0, select = 0;
	while (!quit)
	{
		printf("«Î ‰»Î£∫");
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
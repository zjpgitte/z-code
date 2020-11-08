#include "game.h"
int main()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu();
		printf("«Î ‰»Î£∫");
		scanf("%d", &select);
		switch (select)
		{
		case 1:Game();
			break;
		case 2:quit = 1;
			break;
		}
	}
	system("pause");
	return 0;
}
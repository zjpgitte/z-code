#include "CampusNagative.h"
int main()
{
	AdjMartrix G;
	int select = 0;
	int quit = 0;
	InitCampusGraph(&G);//初始化校园导航图

	while (!quit)
	{
		Menu();
		printf("输入操作的序号#");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			DisaplyCampusGraph(&G);//显示各个景点及代号
			printf("\n");
			break;
		case 2:
			SearchVertexDate(&G);//查询景点信息(简介)
			printf("\n");

			break;
		case 3:
			SearchArcDate(&G);//查询路径
			printf("\n");

			break;
		case 4:DevelopOption(&G);//开发人选项(修改顶点信息和边的长度)
			break;
		default:quit = 1;
			printf("\n");

			break;
		}
		system("pause");

	}
	
	return 0;
}
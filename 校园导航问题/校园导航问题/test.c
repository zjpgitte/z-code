#include "CampusNagative.h"
int main()
{
	AdjMartrix G;
	int select = 0;
	int quit = 0;
	InitCampusGraph(&G);//��ʼ��У԰����ͼ

	while (!quit)
	{
		Menu();
		printf("������������#");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			DisaplyCampusGraph(&G);//��ʾ�������㼰����
			printf("\n");
			break;
		case 2:
			SearchVertexDate(&G);//��ѯ������Ϣ(���)
			printf("\n");

			break;
		case 3:
			SearchArcDate(&G);//��ѯ·��
			printf("\n");

			break;
		case 4:DevelopOption(&G);//������ѡ��(�޸Ķ�����Ϣ�ͱߵĳ���)
			break;
		default:quit = 1;
			printf("\n");

			break;
		}
		system("pause");

	}
	
	return 0;
}
#include "CampusNagative.h"
typedef struct SeqListNode
{
	int path[SIZE];
	int len;
}SeqListNode;

void InitCampusGraph(AdjMartrix *G);//��ʼ��ͼ
static void InitVertex(AdjMartrix *G);//��ʼ������
void InitArc(AdjMartrix *G);//��ʼ����
void SearchVertexDate(AdjMartrix *G);//��ѯ������Ϣ
void SearchArcDate(AdjMartrix *G);//����������������·��
void ShortPath(AdjMartrix *G, int vs, int vd);//�����·��
void DisaplyCampusGraph(AdjMartrix *G);//��ʾͼ�Ķ���
void ModifyCampusGraph(AdjMartrix *G);//�޸�ͼ�ж���ͱߵ���Ϣ
void ModifyArcNode(AdjMartrix *G);

static void SaveVertex(AdjMartrix *G);//������Ϣ�����ļ�
static void SaveArcNode(AdjMartrix *G);//�����ڵ���Ϣ���浽�ļ�

void SeqListPushBack(SeqListNode *s,int x);//��x�����sβ
int Member(SeqListNode *s, int x);//�ж�x�Ƿ�Ϊs�еĳ�Ա
void PrintPath(SeqListNode *s, AdjMartrix *G);//��ӡ ·��s
void InitSeqList(SeqListNode *s);//��ʼ��˳���


void InitCampusGraph(AdjMartrix *G)//��ʼ��ͼ
{
	InitVertex(G);//��ʼ��ͼ�Ķ���
	InitArc(G);//��ʼ����
}

static void InitVertex(AdjMartrix *G)//��ʼ��ͼ�Ķ���
{
	assert(G);
	G->vertexnum = SIZE;
	FILE *fp = fopen("vertexdate.txt", "rb");
	if (NULL == fp)//��ʼ�����Ӽ��̶�ȡ
	{
		for (int i = 0; i < SIZE; i++)
		{
			printf("�����%d���������ƣ�", i + 1);
			gets(G->vertex[i].name);
			G->vertex[i].number = i + 1;
			printf("������:");
			gets(G->vertex[i].introduc);
		}
	}
	else//��ʼ�����ļ���ȡ
	{
		fread(G->vertex, sizeof(VertexDateType), SIZE, fp);
		fclose(fp);
	}
	
	SaveVertex(G);//��������Ϣ��������vertexdate.txt���ļ���
}

void InitArc(AdjMartrix *G)//��ʼ����
{
	assert(G);
	FILE *fp = fopen("arcdate.txt", "rb");
	if (NULL == fp)//��ʼ���Ӽ���
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				G->arc[i][j].distance = INFINITY;
			}
		}//��ʼ��ÿ���߲���ͨ
		printf("����ߵĸ���:");
		scanf("%d", &G->arcnum);
		for (int i = 0; i < G->arcnum; i++)
		{
			printf("�����%d���ߵ������������:", i + 1);
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			printf("����ñߵ�Ȩֵ:");
			int weight = 0;
			scanf("%d", &weight);
			G->arc[v1-1][v2-1].distance = weight;
			G->arc[v2-1][v1-1].distance = weight;
		}
	}//��ʼ����Ȩֵ�ı�
	else
	{
		fread(G, sizeof(int), 2, fp);
		fread(G->arc, sizeof(ArcNodeType), SIZE * SIZE, fp);
		fclose(fp);
	}

	SaveArcNode(G);
}

void ModifyArcNode(AdjMartrix *G)//�޸ıߵ���Ϣ
{
	assert(G);
	if (G->arcnum == 0)
	{
		printf("ͼΪ��\n");
		return;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("����Ҫ�޸ĵıߵ������������:");
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		printf("����ñߵ�Ȩֵ:");
		int weight = 0;
		scanf("%d", &weight);
		G->arc[v1 - 1][v2 - 1].distance = weight;
		G->arc[v2 - 1][v1 - 1].distance = weight;
	}
	SaveArcNode(G);

}
void SearchVertexDate(AdjMartrix *G)//��ѯ������Ϣ
{
	assert(G);

	printf("�����뾰�����:");
	int num;
	scanf("%d", &num);
	printf("%d.", G->vertex[num - 1].number);
	printf("%s\n", G->vertex[num - 1].name);
	printf("���:%s\n", G->vertex[num - 1].introduc);
}
void SearchArcDate(AdjMartrix *G)//��ѯ�������������·��
{
	if (G == NULL)
	{
		return;
	}
	int src = 0;
	int dst = 0;
	printf("������Դλ�ú�Ŀ��ֵ�Ĵ���:\n");
	while (1)
	{
		printf("Դλ�ô���:");
		scanf("%d", &src);
		printf("Ŀ�ĵش���:");
		scanf("%d", &dst);
		if ((src > 0 && src < 13) && (dst >0 && dst < 13))
		{
			break;
		}
		printf("��������\n");
	}
	ShortPath(G, src - 1, dst - 1);
	
}
void ShortPath(AdjMartrix *G, int vs, int vd)//�����·��
{
	SeqListNode s, path[SIZE];
	int dist[SIZE] = { 0 };
	InitSeqList(&s);
	SeqListPushBack(&s, vs);
	for (int i = 0; i < SIZE; i++)
	{
		InitSeqList(&path[i]);//��ʼ��·��
		
			dist[i] = G->arc[vs][i].distance;//��ʼ��dist[i]��ֵΪ vs��i �Ĵ�С
			SeqListPushBack(&path[i], vs);//ÿһ��·���Ŀ�ʼ����Ϊ ���� vs
		
	}//��ʼ��dist,path[i]
	for (int i = 0; i < SIZE-1; i++)
	{
		int k = 0;
		int min = INFINITY;
		for (int j = 0; j < SIZE; j++)
		{
			if (!Member(&s, j) && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}//��dist[i]��ֵС�Ķ���
		if (min == INFINITY) return;
		SeqListPushBack(&s, k);
		SeqListPushBack(&path[k], k);
		if (k == vd)
		{
			PrintPath(&path[k], G);
			return;
		}
		for (int j = 0; j < SIZE; ++j)
		{
			if ((!Member(&s, j)) && (G->arc[k][j].distance < INFINITY) && (dist[j] >(dist[k] + G->arc[k][j].distance)))
			{
				dist[j] = dist[k] + G->arc[k][j].distance;
				path[j] = path[k];
			}
		}

	}
}
static void SaveVertex(AdjMartrix *G)//
{
	FILE *fp = fopen("vertexdate.txt", "wb");
	if (fp == NULL)
	{
		printf("open file error!");
		return;
	}
	fwrite(G->vertex, sizeof(VertexDateType), SIZE, fp);
	fclose(fp);
}//���涥�㵽�ļ���
static void SaveArcNode(AdjMartrix *G)//�����ڵ���Ϣ���浽�ļ�
{
	assert(G);
	FILE *fp = fopen("arcdate.txt", "wb");
	if (NULL == fp)
	{
		printf("open file error!\n");
		return;
	}
	fwrite(G, sizeof(int), 2, fp);
	fwrite(G->arc, sizeof(ArcNodeType), SIZE * SIZE, fp);
	fclose(fp);

}//����ߵ��ļ�
void DisaplyCampusGraph(AdjMartrix *G)
{
	assert(G);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d.", G->vertex[i].number);
		printf("%s\n", G->vertex[i].name);
	}
}//��ӡ����
void InitSeqList(SeqListNode *s)
{
	s->len = 0;
}

void SeqListPushBack(SeqListNode *s,int x)
{
	s->path[s->len] = x;
	s->len++;
}
int Member(SeqListNode *s, int x)
{
	for (int i = 0; i < s->len; i++)
	{
		if (s->path[i] == x)
		{
			return 1;
		}
	}
	return 0;
}
void PrintPath(SeqListNode *s, AdjMartrix *G)
{
	for (int i = 0; i < s->len; i++)
	{
		int n = s->path[i];
		printf("%s", G->vertex[n].name);
		if (i != (s->len - 1))
		{
			printf("-->");
		}
	}
	printf("\n");
}
void Menu()
{
	printf("###############################\n");
	printf("#       1.��ʾУ԰����        #\n");
	printf("#       2.��ѯУ԰����        #\n");
	printf("#       3.��ѯ���⾰��·��    #\n");
	printf("#       4.������Աѡ��        #\n");
	printf("#       0.�˳�                #\n");
	printf("###############################\n");

}
void DisaplyArc(AdjMartrix *G)
{
	assert(G);
	int i = 0, j = 0;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (G->arc[i][j].distance < INFINITY)
			{
				printf("%s--%d-->%s\n", G->vertex[i].name, G->arc[i][j].distance, G->vertex[j].name);
			}
		}
	}
}
static void Menu1()
{
	printf("#############################\n");
	printf("#  1.�޸�У԰ͼ��Ϣ         #\n");
	printf("#  2.��ʾ������������·��   #\n");
	printf("#  3.����                   #\n");
	printf("#############################\n");
}
void DevelopOption(AdjMartrix *G)
{
	int select;
	
	int quit = 0;
	while (!quit)
	{
		Menu1();
		printf("����ѡ��:\n");
		scanf("%d", &select);
		switch (select)
		{

		case 1:
			ModifyCampusGraph(G);//�޸�ͼ����Ϣ
			break;
		case 2:
			DisaplyArc(G);//��ʾ������Ϣ
			printf("\n");
			break;
		default:
			quit = 1;
			break;
		}
	}
}
void Menu2()
{
	printf("####################\n");
	printf("#1.�޸ľ�����Ϣ    #\n");
	printf("#2.�޸ľ�������  #\n");
	printf("#3.�˳�            #\n");
	printf("####################\n");
}
void ModifyVertex(AdjMartrix *G)//�޸Ķ�����Ϣ
{
	assert(G);
	printf("�����޸ľ���Ĵ���:\n");
	int num = 0;int date;
	scanf("%d", &num);
	printf("�����޸ĵ���Ϣ:\n");
	
	while (1)
	{
		printf("1.����   2.���\n");
		scanf("%d", &date); getchar();
		if (date == 1)
		{
			printf("�����޸ĺ������:");
			gets(G->vertex[num-1].name);
			break;
		}
		else if (date == 2)
		{
			printf("�����޸ĺ�ļ��:");
			gets(G->vertex[num-1].introduc);
			break;
		}
		else
		{
			printf("��������:\n");
		}
	}
	SaveVertex(G);
}
void ModifyArc(AdjMartrix *G)//�޸ıߵ���Ϣ
{
	printf("�����޸ĵıߵ���������(�м��Կո�ָ�):\n");
	while (1)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		if (v1 > 0 && v1 < 13 && v2 > 0 && v2 < 13)
		{
			printf("%s--%d-->%s\n", G->vertex[v1 - 1].name, G->arc[v1 - 1][v2 - 1].distance, G->vertex[v2 - 1].name);
			printf("�����޸ĺ�ľ���:\n");
			scanf("%d", &G->arc[v1 - 1][v2 - 1].distance);
			printf("%s--%d-->%s\n", G->vertex[v1 - 1].name, G->arc[v1][v2 - 1].distance, G->vertex[v2 - 1].name);
			printf("\n");
			break;
		}
		else
		{
			printf("���������޸ĵıߵ���������(�м��Կո�ָ�):\n");
		}
	}
}
void ModifyCampusGraph(AdjMartrix *G)
{
	int select = 0;int quit = 0;
	while (!quit)
	{
		Menu2();
		printf("����ѡ��:\n");
		scanf("%d", &select);
			switch (select)
			{
			case 1:ModifyVertex(G);
				break;
			case 2:ModifyArc(G);
				break;
			default:quit = 1;
				break;
			}

		
	}
}






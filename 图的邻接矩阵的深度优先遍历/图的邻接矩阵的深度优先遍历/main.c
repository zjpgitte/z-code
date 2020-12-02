#include <stdio.h>
#include <windows.h>
//ͼ�Ľ����ͱ���
//����һ�����ڽӾ���
//���������������ȱ��������������������ʾ���ϡ�
#pragma warning(disable:4996)
#define MAX_VERTEX_NUM 20
#define INFINITY 32768
int visit[20];
typedef struct
{
	char vertex[MAX_VERTEX_NUM];
	int arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vertexnum;
	int arcnum;
}VertexMatrix;
int Loc(VertexMatrix *G, char c)
{
	int i = 0;
	while (i < G->vertexnum)
	{
		if (c == G->vertex[i])
		{
			return i;
		}
		i++;
	}
	return -1;
}

//������������������������������Ļ�����ͨ��
void Creat(VertexMatrix *G)
{
	if (NULL == G)
	{
		return;
	}
	printf("���붥��������");
	scanf("%d", &G->vertexnum); getchar();
	printf("���붥�����У�\n");
	while (1)
	{
		int j = 0; char ch;
		while (((ch = getchar()) != '\n') && (j < G->vertexnum ) )
		{
			G->vertex[j] = ch;
			j++;
		}
		//Ϊÿ������������֣�
		if (ch == '\n') break;
		fflush(stdin);
		printf("�������룺");
	}
	printf("���뻡��������");
	scanf("%d",&G->arcnum);
	for (int i = 0; i < G->vertexnum; i++)
	{
		for (int j 
			= 0; j < G->vertexnum; j++)
		{
			G->arc[i][j] = 0;
		}
	}//��ʼ��ÿ����Ϊ0��
	for (int i = 0; i < G->arcnum; i++)
	{
		char vi,vj;
		printf("�������%d��ߵ��������㣺",i+1);
		scanf(" %c %c", &vi, &vj); getchar();
		int n1 = Loc(G, vi);
		int n2 = Loc(G, vj);//��vi��vj��Ӧ���±�
		G->arc[n1][n2] = 1;
		G->arc[n2][n1] = 1;
	}
	
}
void DFS(VertexMatrix *G, int v0)
{
	printf("%c", G->vertex[v0]);
	visit[v0] = 1;
	for (int vi = 0; vi < G->vertexnum; vi++)
	{
		if (G->arc[v0][vi] == 1 && !visit[vi])
		{
			DFS(G, vi);
		}
	}//������ȱ�������ͼ��
	
}
int main()
{
	VertexMatrix G;
	Creat(&G);
	DFS(&G,0);
	printf("\n");
	system("pause");
	return 0;
}
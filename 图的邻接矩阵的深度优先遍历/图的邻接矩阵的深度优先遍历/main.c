#include <stdio.h>
#include <windows.h>
//图的建立和遍历
//建立一个用邻接矩阵
//并对其进行深度优先遍历将遍历序列输出到显示器上。
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

//顶点数量、弧的数量、哪两个顶点的弧是连通的
void Creat(VertexMatrix *G)
{
	if (NULL == G)
	{
		return;
	}
	printf("输入顶点数量：");
	scanf("%d", &G->vertexnum); getchar();
	printf("输入顶点序列：\n");
	while (1)
	{
		int j = 0; char ch;
		while (((ch = getchar()) != '\n') && (j < G->vertexnum ) )
		{
			G->vertex[j] = ch;
			j++;
		}
		//为每个顶点编上名字；
		if (ch == '\n') break;
		fflush(stdin);
		printf("重新输入：");
	}
	printf("输入弧的数量：");
	scanf("%d",&G->arcnum);
	for (int i = 0; i < G->vertexnum; i++)
	{
		for (int j 
			= 0; j < G->vertexnum; j++)
		{
			G->arc[i][j] = 0;
		}
	}//初始化每条边为0；
	for (int i = 0; i < G->arcnum; i++)
	{
		char vi,vj;
		printf("请输入第%d组边的两个顶点：",i+1);
		scanf(" %c %c", &vi, &vj); getchar();
		int n1 = Loc(G, vi);
		int n2 = Loc(G, vj);//找vi，vj对应的下标
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
	}//深度优先遍历无向图；
	
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
#include "CampusNagative.h"
typedef struct SeqListNode
{
	int path[SIZE];
	int len;
}SeqListNode;

void InitCampusGraph(AdjMartrix *G);//初始化图
static void InitVertex(AdjMartrix *G);//初始化顶点
void InitArc(AdjMartrix *G);//初始化边
void SearchVertexDate(AdjMartrix *G);//查询顶点信息
void SearchArcDate(AdjMartrix *G);//查找任意两个顶点路径
void ShortPath(AdjMartrix *G, int vs, int vd);//求最短路径
void DisaplyCampusGraph(AdjMartrix *G);//显示图的顶点
void ModifyCampusGraph(AdjMartrix *G);//修改图中顶点和边的信息
void ModifyArcNode(AdjMartrix *G);

static void SaveVertex(AdjMartrix *G);//顶点信息保存文件
static void SaveArcNode(AdjMartrix *G);//将弧节点信息保存到文件

void SeqListPushBack(SeqListNode *s,int x);//将x插入表s尾
int Member(SeqListNode *s, int x);//判断x是否为s中的成员
void PrintPath(SeqListNode *s, AdjMartrix *G);//打印 路径s
void InitSeqList(SeqListNode *s);//初始化顺序表


void InitCampusGraph(AdjMartrix *G)//初始化图
{
	InitVertex(G);//初始化图的顶点
	InitArc(G);//初始化边
}

static void InitVertex(AdjMartrix *G)//初始化图的顶点
{
	assert(G);
	G->vertexnum = SIZE;
	FILE *fp = fopen("vertexdate.txt", "rb");
	if (NULL == fp)//初始化：从键盘读取
	{
		for (int i = 0; i < SIZE; i++)
		{
			printf("输入第%d个景点名称：", i + 1);
			gets(G->vertex[i].name);
			G->vertex[i].number = i + 1;
			printf("输入简介:");
			gets(G->vertex[i].introduc);
		}
	}
	else//初始化从文件读取
	{
		fread(G->vertex, sizeof(VertexDateType), SIZE, fp);
		fclose(fp);
	}
	
	SaveVertex(G);//将顶点信息保存至“vertexdate.txt”文件中
}

void InitArc(AdjMartrix *G)//初始化边
{
	assert(G);
	FILE *fp = fopen("arcdate.txt", "rb");
	if (NULL == fp)//初始化从键盘
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				G->arc[i][j].distance = INFINITY;
			}
		}//初始化每条边不连通
		printf("输入边的个数:");
		scanf("%d", &G->arcnum);
		for (int i = 0; i < G->arcnum; i++)
		{
			printf("输入第%d条边的两个顶点代号:", i + 1);
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			printf("输入该边的权值:");
			int weight = 0;
			scanf("%d", &weight);
			G->arc[v1-1][v2-1].distance = weight;
			G->arc[v2-1][v1-1].distance = weight;
		}
	}//初始化有权值的边
	else
	{
		fread(G, sizeof(int), 2, fp);
		fread(G->arc, sizeof(ArcNodeType), SIZE * SIZE, fp);
		fclose(fp);
	}

	SaveArcNode(G);
}

void ModifyArcNode(AdjMartrix *G)//修改边的信息
{
	assert(G);
	if (G->arcnum == 0)
	{
		printf("图为空\n");
		return;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("输入要修改的边的两个顶点代号:");
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		printf("输入该边的权值:");
		int weight = 0;
		scanf("%d", &weight);
		G->arc[v1 - 1][v2 - 1].distance = weight;
		G->arc[v2 - 1][v1 - 1].distance = weight;
	}
	SaveArcNode(G);

}
void SearchVertexDate(AdjMartrix *G)//查询顶点信息
{
	assert(G);

	printf("请输入景点代号:");
	int num;
	scanf("%d", &num);
	printf("%d.", G->vertex[num - 1].number);
	printf("%s\n", G->vertex[num - 1].name);
	printf("简介:%s\n", G->vertex[num - 1].introduc);
}
void SearchArcDate(AdjMartrix *G)//查询任意两个顶点的路径
{
	if (G == NULL)
	{
		return;
	}
	int src = 0;
	int dst = 0;
	printf("请输入源位置和目标值的代号:\n");
	while (1)
	{
		printf("源位置代号:");
		scanf("%d", &src);
		printf("目的地代号:");
		scanf("%d", &dst);
		if ((src > 0 && src < 13) && (dst >0 && dst < 13))
		{
			break;
		}
		printf("重新输入\n");
	}
	ShortPath(G, src - 1, dst - 1);
	
}
void ShortPath(AdjMartrix *G, int vs, int vd)//求最短路径
{
	SeqListNode s, path[SIZE];
	int dist[SIZE] = { 0 };
	InitSeqList(&s);
	SeqListPushBack(&s, vs);
	for (int i = 0; i < SIZE; i++)
	{
		InitSeqList(&path[i]);//初始化路径
		
			dist[i] = G->arc[vs][i].distance;//初始化dist[i]的值为 vs到i 的大小
			SeqListPushBack(&path[i], vs);//每一条路径的开始设置为 顶点 vs
		
	}//初始化dist,path[i]
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
		}//找dist[i]中值小的顶点
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
}//保存顶点到文件中
static void SaveArcNode(AdjMartrix *G)//将弧节点信息保存到文件
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

}//保存边到文件
void DisaplyCampusGraph(AdjMartrix *G)
{
	assert(G);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d.", G->vertex[i].number);
		printf("%s\n", G->vertex[i].name);
	}
}//打印顶点
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
	printf("#       1.显示校园景点        #\n");
	printf("#       2.查询校园景点        #\n");
	printf("#       3.查询任意景点路径    #\n");
	printf("#       4.开发人员选项        #\n");
	printf("#       0.退出                #\n");
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
	printf("#  1.修改校园图信息         #\n");
	printf("#  2.显示任意两个景点路径   #\n");
	printf("#  3.返回                   #\n");
	printf("#############################\n");
}
void DevelopOption(AdjMartrix *G)
{
	int select;
	
	int quit = 0;
	while (!quit)
	{
		Menu1();
		printf("输入选项:\n");
		scanf("%d", &select);
		switch (select)
		{

		case 1:
			ModifyCampusGraph(G);//修改图的信息
			break;
		case 2:
			DisaplyArc(G);//显示弧的信息
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
	printf("#1.修改景点信息    #\n");
	printf("#2.修改景点间距离  #\n");
	printf("#3.退出            #\n");
	printf("####################\n");
}
void ModifyVertex(AdjMartrix *G)//修改顶点信息
{
	assert(G);
	printf("输入修改景点的代号:\n");
	int num = 0;int date;
	scanf("%d", &num);
	printf("输入修改的信息:\n");
	
	while (1)
	{
		printf("1.名称   2.简介\n");
		scanf("%d", &date); getchar();
		if (date == 1)
		{
			printf("输入修改后的名称:");
			gets(G->vertex[num-1].name);
			break;
		}
		else if (date == 2)
		{
			printf("输入修改后的简介:");
			gets(G->vertex[num-1].introduc);
			break;
		}
		else
		{
			printf("重新输入:\n");
		}
	}
	SaveVertex(G);
}
void ModifyArc(AdjMartrix *G)//修改边的信息
{
	printf("输入修改的边的两个顶点(中间以空格分隔):\n");
	while (1)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		if (v1 > 0 && v1 < 13 && v2 > 0 && v2 < 13)
		{
			printf("%s--%d-->%s\n", G->vertex[v1 - 1].name, G->arc[v1 - 1][v2 - 1].distance, G->vertex[v2 - 1].name);
			printf("输入修改后的距离:\n");
			scanf("%d", &G->arc[v1 - 1][v2 - 1].distance);
			printf("%s--%d-->%s\n", G->vertex[v1 - 1].name, G->arc[v1][v2 - 1].distance, G->vertex[v2 - 1].name);
			printf("\n");
			break;
		}
		else
		{
			printf("重新输入修改的边的两个顶点(中间以空格分隔):\n");
		}
	}
}
void ModifyCampusGraph(AdjMartrix *G)
{
	int select = 0;int quit = 0;
	while (!quit)
	{
		Menu2();
		printf("输入选项:\n");
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






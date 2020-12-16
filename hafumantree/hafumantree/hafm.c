#include"hafm.h"
void Printhfmtree(hfmtree_t *hft)
{
	int n = hft->n;
	char *str = (char*)malloc(sizeof(char)*(n+1));
	str[n] = '\0';
	for (int i = 0; i < n; i++)
	{
		str[i] = hft->hf[i].ch;
	}
	printf("%s", str);//打印叶子节点
	printf("\n");
	for (int i = n; i < 2 * n - 1; i++)
	{
		printf("%d ", hft->hf[i].weight);
	}
	printf("\n");

}
static void InputLeaves(hfmtree_t *hft)
{
	assert(hft);
	printf("输入叶子节点数量:");
	scanf("%d", &hft->n); getchar();
	int n = hft->n;
	hft->hf = (hfmNode_t*)malloc(sizeof(hfmNode_t)*(2 * n - 1));
	if (hft->hf == NULL)
	{
		printf("malloc error\n");
		return;
	}
	for (int i = 0; i < n; i++)//输入每个叶子节点的权值和字符
	{
		printf("请输入第%d个叶子节点代表的字符:",i+1);
		hft->hf[i].ch = getchar(); 
		printf("请输入第%d个叶子节点的权值:", i + 1);
		scanf("%d", &hft->hf[i].weight); getchar();
	}
}
static int FindMin(hfmtree_t *hft,int n)
{
	int min ;
	hfmNode_t *cur = hft->hf;
	for (int i = 0; i < n; i++)
	{
		if (cur[i].parent == -1)
		{
			min = i;
			break;
		}
	}//在未被访问的叶子中，找到一个叶子假设它的权值最小
	for (int i = 0; i < n; i++)
	{
		if (cur[i].parent == -1 && cur[i].weight < cur[min].weight)
		{
			min = i;
		}
	}
	hft->hf[min].parent = visited;
	return min;
}
void CreatHfmTree(hfmtree_t *hft)
{
	int n = hft->n;
	for (int i = 0; i < 2 * n - 1; i++)//每个节点初始化
	{
		hft->hf[i].Lchild = -1;
		hft->hf[i].Rchild = -1;
		hft->hf[i].parent = -1;
	}
	for (int i = n; i < 2 * n - 1; i++)
	{
		hft->hf[i].weight = 0;
	}
	for (int i = n; i < 2 * n - 1; i++)
	{
		int min1 = FindMin(hft,i);
		int min2 = FindMin(hft,i);//从前i个里面找找权值最小的两个节点；
		hft->hf[i].Lchild = min1;
		hft->hf[i].Rchild = min2;
		hft->hf[i].weight = hft->hf[min1].weight + hft->hf[min2].weight;
		hft->hf[min1].parent = hft->hf[min2].parent = i;
	}
}
void InitHfmtree(hfmtree_t *hft)
{
	InputLeaves(hft);
	CreatHfmTree(hft);
}
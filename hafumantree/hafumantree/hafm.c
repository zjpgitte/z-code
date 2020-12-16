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
	printf("%s", str);//��ӡҶ�ӽڵ�
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
	printf("����Ҷ�ӽڵ�����:");
	scanf("%d", &hft->n); getchar();
	int n = hft->n;
	hft->hf = (hfmNode_t*)malloc(sizeof(hfmNode_t)*(2 * n - 1));
	if (hft->hf == NULL)
	{
		printf("malloc error\n");
		return;
	}
	for (int i = 0; i < n; i++)//����ÿ��Ҷ�ӽڵ��Ȩֵ���ַ�
	{
		printf("�������%d��Ҷ�ӽڵ������ַ�:",i+1);
		hft->hf[i].ch = getchar(); 
		printf("�������%d��Ҷ�ӽڵ��Ȩֵ:", i + 1);
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
	}//��δ�����ʵ�Ҷ���У��ҵ�һ��Ҷ�Ӽ�������Ȩֵ��С
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
	for (int i = 0; i < 2 * n - 1; i++)//ÿ���ڵ��ʼ��
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
		int min2 = FindMin(hft,i);//��ǰi����������Ȩֵ��С�������ڵ㣻
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
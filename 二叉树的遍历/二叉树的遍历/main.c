#include <stdio.h>
#include <windows.h>
//【基本要求】从键盘输入一棵二叉树的先序序列，以二叉链表作为存储结构，建立二叉树并对其进行遍历（先序、中序和后序），
//然后将遍历结果打印输出。要求编写递归和非递归两种算法来实现。
//【测试数据】 输入序列：ABC**DE*G**F***（其中*表示空子树）
//输出结果：先序序列ABCDEGF
//中序序列CBEGDFA
//后序序列CGEFDBA
typedef struct Tree
{
	char c;
	struct Tree *Lchild;
	struct Tree *Rchild;
}*bitree,bitreenode;
void InitBitree(bitree *root)
{
	*root =(bitree)malloc(sizeof(bitreenode));
	(*root)->Lchild = NULL;
	(*root)->Rchild = NULL;
}
void PreOrderInput(bitree *root)
{
	if (NULL == root)
	{
		return;
	}
	char ch;
	ch = getchar();
	if ('*' != ch)
	{
		*root = (bitree)malloc(sizeof(bitreenode));
		(*root)->Lchild = NULL;
		(*root)->Rchild = NULL;
		(*root)->c = ch;
		PreOrderInput(&((*root)->Lchild));
		PreOrderInput(&((*root)->Rchild));
	}
}
void PreOrderTravel(bitree root)
{
	if (NULL != root)
	{
		printf("%c", root->c);
		PreOrderTravel(root->Lchild);
		PreOrderTravel(root->Rchild);
	}
}
void InOrderTravel(bitree root)
{
	if (NULL != root)
	{
		InOrderTravel(root->Lchild);
		printf("%c", root->c);
		InOrderTravel(root->Rchild);
	}
}
void PostOrderTravel(bitree root)
{
	if (NULL != root)
	{
		PostOrderTravel(root->Lchild);
		PostOrderTravel(root->Rchild);
		printf("%c", root->c);
	}
}
int main()
{
	bitree root;
	//InitBitree(&root);
	printf("输入序列：");
	PreOrderInput(&root);//初始化二叉树的每个节点
	printf("先序序列：");
	PreOrderTravel(root);
	printf("\n中序序列：");
	InOrderTravel(root);
	printf("\n后序序列：");
	PostOrderTravel(root);
	printf("\n");
	system("pause");
	return 0;
}
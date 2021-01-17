#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct BinaryTreeNode
{
	int val;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}BinaryTreeNode;

void BinaryTreeCreat(BinaryTreeNode **root, int **pa)
{
	if (**pa == -1)
	{
		(*pa)++;
		return;
	}

	(*root) = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	(*root)->val = **pa;
	(*root)->left = NULL;
	(*root)->right = NULL;
	(*pa)++;

	BinaryTreeCreat(&(*root)->left,pa);
	BinaryTreeCreat(&(*root)->right,pa);

}

//void TravelJudge(BinaryTreeNode *p, BinaryTreeNode *q, int *tag)
//{
//	//p,q均不存在。p和q均为空结点，不改变tag值
//	if (p == NULL && q == NULL)
//	{
//		return;
//	}
//
//	//p和q只存在一个结点，或者p,q结点均存在但是值不相等，将tag置1
//	else if (p && !q || q && !p || p->val != q->val)
//	{
//		*tag = 1;
//		return;
//	}
//
//	//p,q均存在且值相等
//	else
//	{
//		TravelJudge(p->left, q->left, tag);
//		TravelJudge(p->right, q->right, tag);
//	}
//
//}
//
//int IsSameTree(BinaryTreeNode *p, BinaryTreeNode *q)
//{
//	int tag = 0;
//
//	//遍历判断p,q各个节点值是否相等，若不相等将tag值1，若相等 tag 不变
//	TravelJudge(p, q,&tag);
//
//	
//	if (tag == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

int IsSameTree(BinaryTreeNode *p, BinaryTreeNode *q)
{
	if (p == NULL && q == NULL)
	{
		return 1;
	}

	if (p && !q || q && !p || p->val != q->val)
	{
		return 0;
	}

	return IsSameTree(p->left, q->left) && IsSameTree(p->right, q->right);
}

int main()
{
	int arr1[] = { 1, 2, -1, -1, 3, -1, -1 };
	int arr2[] = { 1, 2, -1, -1, 3, -1, -1 };
	int *pa1 = arr1;
	int *pa2 = arr2;

	//创建两个树
	BinaryTreeNode *p = NULL;
	BinaryTreeNode *q = NULL;
	BinaryTreeCreat(&p, &pa1);
	BinaryTreeCreat(&q, &pa2);
	
	//判断两个数是否相等
	printf("%d\n",IsSameTree(p, q));

	system("pause");
	return 0;
}
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
//	//p,q�������ڡ�p��q��Ϊ�ս�㣬���ı�tagֵ
//	if (p == NULL && q == NULL)
//	{
//		return;
//	}
//
//	//p��qֻ����һ����㣬����p,q�������ڵ���ֵ����ȣ���tag��1
//	else if (p && !q || q && !p || p->val != q->val)
//	{
//		*tag = 1;
//		return;
//	}
//
//	//p,q��������ֵ���
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
//	//�����ж�p,q�����ڵ�ֵ�Ƿ���ȣ�������Ƚ�tagֵ1������� tag ����
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

	//����������
	BinaryTreeNode *p = NULL;
	BinaryTreeNode *q = NULL;
	BinaryTreeCreat(&p, &pa1);
	BinaryTreeCreat(&q, &pa2);
	
	//�ж��������Ƿ����
	printf("%d\n",IsSameTree(p, q));

	system("pause");
	return 0;
}
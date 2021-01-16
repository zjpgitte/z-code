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
	else
	{
		//�������
		*root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
		(*root)->val = **pa;
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*pa)++;

		//������������
		BinaryTreeCreat(&(*root)->left, pa);
		BinaryTreeCreat(&(*root)->right, pa);
	}
}

void TravelJudge(BinaryTreeNode *p, BinaryTreeNode *q,int *tag)
{
	if (p == NULL && q == NULL)
	{
		return;
	}
	else if (p && !q || q && !p || p->val != q->val)
	{
		*tag = 1;
		return;
	}
	else
	{
		TravelJudge(p->left, q->right, tag);
		TravelJudge(p->right, q->left, tag);
	}
}

int IsSymmetric(BinaryTreeNode *root)
{
	//Ҫ�ж���root�Ƿ�Գơ�
	//ֻ���ж� root ���������������� �� root�����������������Ƿ����
	//�Լ�     root ���������������� �� root�����������������Ƿ����

	int tag = 0;

	TravelJudge(root->left, root->right,&tag);

	if (tag == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int arr[] = { 1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1 };
	int *pa = arr;

	//����������
	BinaryTreeNode *root = NULL;
	BinaryTreeCreat(&root, &pa);

	printf("%d\n", IsSymmetric(root));
	system("pause");
	return 0;
}
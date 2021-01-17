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
		//创建结点
		*root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
		(*root)->val = **pa;
		(*root)->left = NULL;
		(*root)->right = NULL;
		(*pa)++;

		//创建左右子树
		BinaryTreeCreat(&(*root)->left, pa);
		BinaryTreeCreat(&(*root)->right, pa);
	}
}

//void TravelJudge(BinaryTreeNode *p, BinaryTreeNode *q,int *tag)
//{
//	if (p == NULL && q == NULL)
//	{
//		return;
//	}
//	else if (p && !q || q && !p || p->val != q->val)
//	{
//		*tag = 1;
//		return;
//	}
//	else
//	{
//		TravelJudge(p->left, q->right, tag);
//		TravelJudge(p->right, q->left, tag);
//	}
//}
//
//int IsSymmetric(BinaryTreeNode *root)
//{
//	//要判断树root是否对称。
//	//只需判断 root 的左子树的左子树 和 root的右子树的右子树是否相等
//	//以及     root 的左子树的右子树 和 root的右子树的左子树是否相等
//
//	int tag = 0;
//
//	TravelJudge(root->left, root->right,&tag);
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

// p, q是对称位置上的节点
int _isSymmetric(BinaryTreeNode* p, BinaryTreeNode* q)
{
	//结构相同值不相同
	if (p == NULL && q == NULL)
	{
		return 1;
	}
	//结构不同
	if (p && !q)
	{
		return 0;
	}

	if (q && !p)
	{
		return 0;
	}
	//结构相同值不相同
	if (p->val != q->val)
	{
		return 0;
	}

	//结构相同值也相同，比较对称位置
	return _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
}

int IsSymmetric(BinaryTreeNode* root){
	if (root == NULL)
	{
		return 1;
	}

	return _isSymmetric(root->left, root->right);
}

int main()
{
	int arr[] = { 1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1 };
	int *pa = arr;

	//创建二叉树
	BinaryTreeNode *root = NULL;
	BinaryTreeCreat(&root, &pa);

	printf("%d\n", IsSymmetric(root));
	system("pause");
	return 0;
}
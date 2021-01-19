#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

void BinaryTreeCreat(TreeNode **root, int *arr, int *i)
{
	if (arr[*i] == -1)
	{
		(*i)++;
		*root = NULL;
		return;
	}
	*root = (TreeNode *)malloc(sizeof(TreeNode));
	(*root)->val = arr[(*i)++];
	
	BinaryTreeCreat(&(*root)->left, arr, i);
	BinaryTreeCreat(&(*root)->right, arr, i);
}

int IsSameTree(TreeNode *p, TreeNode *q)
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

int IsSubTree(TreeNode *s,TreeNode *t)
{
	if (s == NULL)
	{
		return 0;
	}

	if (IsSameTree(s,t))
	{
		return 1;
	}
	
	return IsSubTree(s->left, t) || IsSubTree(s->right, t);
}

int main()
{
	
	TreeNode *s = NULL;
	TreeNode *t = NULL;
	int arr1[] = { 3, 4, 1, -1, -1, 2, -1, -1, 5, -1, -1 };
	int arr2[] = { 4, 1, -1, -1, 2, -1, -1 };
	int i = 0; int j = 0;
	BinaryTreeCreat(&s, arr1, &i);
	BinaryTreeCreat(&t, arr2, &j);

	printf("%d ", IsSubTree(s,t));
	
	system("pause");
	return 0;
}
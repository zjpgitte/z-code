#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


typedef struct BinaryTreeNode
{
	int val;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}BinaryTreeNode;

void BinaryTreeCreat(BinaryTreeNode **root, int *arr, int *i)
{
	if (arr[*i] == -1)
	{
		(*i)++;
		return;
	}
	*root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	(*root)->val = arr[*i];
	(*root)->left = NULL;
	(*root)->right = NULL;
	(*i)++;
	BinaryTreeCreat(&(*root)->left, arr, i);
	BinaryTreeCreat(&(*root)->right, arr, i);

}
//翻转一颗二叉树:
//思路一:
//void InvertBinaryTree(BinaryTreeNode *root)
//{
//	//空节点课叶子结点不需要翻转
//	if (root == NULL || root->left == NULL && root->right == NULL)
//	{
//		return;
//	}
//
//	//交换左右子树位置
//	BinaryTreeNode *temp = root->left;
//	root->left = root->right;
//	root->right = temp;
//
//	//翻转左子树
//	InvertBinaryTree(root->left);
//	//翻转右子树
//	InvertBinaryTree(root->right);
//
//}

//思路二:
BinaryTreeNode* InvertBinaryTree(BinaryTreeNode * root){
	//空节点不翻转
	if (root == NULL)
	{
		return NULL;
	}

	//翻转左右子树，再交换左右子树的位置
	BinaryTreeNode* right = root->right;
	root->right = InvertBinaryTree(root->left);
	root->left = InvertBinaryTree(right);
	return root;

}



void Print(BinaryTreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d ", root->val);
	Print(root->left);
	Print(root->right);

}
int main()
{
	int arr[] = { 4, 2, 1, -1, -1, 3, -1, -1, 7, 6, -1, -1, 9, -1, -1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	BinaryTreeNode *root = NULL;

	//创建二叉树
	BinaryTreeCreat(&root, arr, &i);
	Print(root); printf("\n");

	//翻转一颗二叉树
	root = InvertBinaryTree(root);
	Print(root);
	system("pause");
	return 0;
}
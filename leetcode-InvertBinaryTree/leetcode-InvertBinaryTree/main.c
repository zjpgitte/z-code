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
//�ж��Ƿ�Ϊ��ת������:
void InvertBinaryTree(BinaryTreeNode *root)
{
	//�սڵ��Ҷ�ӽ�㲻��Ҫ��ת
	if (root == NULL || root->left == NULL && root->right == NULL)
	{
		return;
	}

	//������������λ��
	BinaryTreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;

	//��ת������
	InvertBinaryTree(root->left);
	//��ת������
	InvertBinaryTree(root->right);

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

	//����������
	BinaryTreeCreat(&root, arr, &i);
	Print(root); printf("\n");

	//��תһ�Ŷ�����
	InvertBinaryTree(root);
	Print(root);
	system("pause");
	return 0;
}
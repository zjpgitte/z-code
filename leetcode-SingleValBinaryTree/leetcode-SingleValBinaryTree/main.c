#include <stdio.h>
#include <windows.h>

// Definition for a binary tree node.
typedef struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
}TreeNode;


#define true 1
#define false 0

void BinaryTreeCreat(TreeNode **root, int *arr, int *i)
{
	if (arr[*i] == -1)
	{
		(*i)++;
		return;
	}

	*root = (TreeNode *)malloc(sizeof(TreeNode));
	(*root)->val = arr[*i];
	(*root)->left = NULL;
	(*root)->right = NULL;
	(*i)++;
	BinaryTreeCreat(&(*root)->left,arr,i);
	BinaryTreeCreat(&(*root)->right,arr,i);
}

void BinaryTreeTravel(struct TreeNode* root, int val, int *tag)
{
	if (root == NULL)
	{
		return;
	}
	if (root->val != val)
	{
		*tag = 1;//不相等时将tag置1
		return;
	}
	else
	{
		BinaryTreeTravel(root->left, val, tag);
		BinaryTreeTravel(root->right, val, tag);
	}
}

//int isUnivalTree(struct TreeNode* root){
//	if (root == NULL)
//	{
//		return false;
//	}
//
//	int val = root->val;//记录根节点的值，判断其它结点的值和它是否相等
//	int tag = 0;//辅助判断标志位
//
//	BinaryTreeTravel(root->left, val, &tag);//遍历左子树
//	BinaryTreeTravel(root->right, val, &tag);//遍历右子树
//
//	if (tag == 0)//
//	{
//		return true;
//	}
//	else//tag == 1
//	{
//		return false;
//	}
//}
//
void BinaryTreePrint(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->val);
	BinaryTreePrint(root->left);
	BinaryTreePrint(root->right);
}


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//当左右孩子结点存在，但是和根节点的值不相等时，返回false

int isUnivalTree(struct TreeNode* root){
	if (root == NULL)
	{
		return true;
	}
	//左孩子存在但值不相等
	if (root->left && root->val != root->left->val)
	{
		return false;
	}
	//右孩子存在但值不相等
	if (root->right && root->val != root->right->val)
	{
		return false;
	}
	//判断左右子树是否为单值二叉树
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

int main()
{
	int arr[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	TreeNode *root = NULL;
	BinaryTreeCreat(&root, arr, &i);
	BinaryTreePrint(root); printf("\n");
	printf("%d ", isUnivalTree(root));
	system("pause");
	return 0;
}
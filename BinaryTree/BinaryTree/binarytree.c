#include "binarytree.h"

//树的创建
void BinaryTreeCreat(BTNode **root,BTDataType **str)
{
		//如果输入的是'.'表明当前结点为NULL则不创建节点
		if (**str == '.' )//接一次引用拿到当前元素的指针，解两次引用拿到数组当前元素
		{
			(*str)++;
			return;
		}


		//当元素不是NULL时创建节点，放入数组的当前元素
		*root = (BTNode *)malloc(sizeof(BTNode));
		(*root)->_data = **str;
		(*root)->_left = NULL;
		(*root)->_right = NULL;
		(*str)++;
		BinaryTreeCreat(&(*root)->_left,str);
		BinaryTreeCreat(&(*root)->_right,str);
	
}

//树的先序遍历
void BinaryTreePreOrder(BTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePreOrder(root->_left);
	BinaryTreePreOrder(root->_right);
}

//树的中序遍历
void BinaryTreeInOrder(BTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

//树的后序遍历
void BinaryTreePostOrder(BTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

//树的节点个数
int BinaryTreeSize(BTNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

//树的叶子节点个数
int BinaryTreeLeafSize(BTNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL )
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

//树的深度
int BinaryTreeDepth(BTNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	int leftDepth = BinaryTreeDepth(root->_left);
	int rightDepth = BinaryTreeDepth(root->_right);
	int maxDepth = leftDepth;
	if (rightDepth > leftDepth)
	{
		maxDepth = rightDepth;
	}
	return 1+maxDepth;
}

void TravelKLevel(BTNode *root, int cur, int *kSize,int k)
{
	if (cur > k)
	{
		return;
	}
	else if (cur < k)
	{
		cur++;
		TravelKLevel(root->_left, cur, kSize, k);
		TravelKLevel(root->_right, cur, kSize, k);
	}
	else
	{
		if (root != NULL)
		{
			(*kSize)++;
		}
	}
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	int kSize = 0;
	int cur = 1;
	TravelKLevel(root, cur, &kSize,k);
	return kSize;
}

void TravelFind(BTNode *root, BTDataType x, BTNode **ret)
{
	if (root == NULL)
	{
		return;
	}
	if (root->_data == x)
	{
		*ret = root;
		return;
	}
	else
	{
		TravelFind(root->_left, x, ret);
		TravelFind(root->_right, x, ret);
	}
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode *ret = NULL;
	TravelFind(root, x, &ret);
	return ret;
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if ((*root) == NULL)
	{
		return;
	}
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
}
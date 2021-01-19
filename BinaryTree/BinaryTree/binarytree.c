#include "binarytree.h"
#include "Queue.h"

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


// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	//1.当前节点就是要查找的结点
	if (root->_data == x)
	{
		return root;
	}

	//2.当前节点不是，到左子树找
	BTNode *left = BinaryTreeFind(root->_left,x);
	if (left != NULL)
	{
		return left;
	}

	//3.左子树没找到，到右子树找
	BTNode *right = BinaryTreeFind(root->_right, x);
	if (right != NULL)
	{
		return right;
	}

	//左右子树都没找到返回NULL
	return NULL;

}

// 层序遍历
//让根节点入队，然后出队，之后再让根结点的左右孩子入队,NULL结点不入队
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		//当前根节点出队
		BTNode *cur = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", cur->_data);
		//当前根节点的左右孩子入队
		if (cur->_left)
		{
			QueuePush(&q, cur->_left);
		}
		if (cur->_right)
		{
			QueuePush(&q, cur->_right);
		}
	}
	printf("\n");


}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}

	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode *cur = QueueFront(&q);
		QueuePop(&q);
		if (cur == NULL)
		{
			break;
		}
		QueuePush(&q, cur->_left);
		QueuePush(&q, cur->_right);
	}

	while (!QueueEmpty(&q))
	{
		if (QueueFront(&q) != NULL)
		{
			return 0;
		}
		QueuePop(&q);
	}
	return 1;

}

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
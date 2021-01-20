#include "binarytree.h"
#include "Queue.h"


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	//前序遍历 先建立根
	BTNode *root = malloc(sizeof(BTNode));
	root->_val = a[*pi];
	(*pi)++;

	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);

	//最后链接起来
	return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//销毁的时候使用后序遍历更好,前序和中序遍历还要记录左右子树
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	//前序
	//当前节点不存在
	if (root == NULL)
	{
		return 0;
	}

	//当前节点存在 1   +   左子树的节点数  +  右子树的节点数             
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);

}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	//递归出口:空节点
	if (root == NULL)
	{
		return 0;
	}

	//递归出口:当前节点是叶子节点
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}

	//左子树的叶子结点树+右子树的叶子结点树
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
	 
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	
	//递归递归出口,k = 1 说明当前层就是 整个二叉树的第 k 层
	if (k == 1)
	{
		return 1;
	}

	//左右子树的第 K-1 层之和 
	return BinaryTreeLevelKSize(root->_left,k-1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//前序遍历

	if (root == NULL)
	{
		return NULL;
	}

	//判断根节点，若是返回根节点
	if (root->_val == x)
	{
		return root;
	}

	//根节点不是，遍历左子树查找，找到就返回该结点
	BTNode *node = BinaryTreeFind(root->_left, x);
	if (node != NULL)
	{
		return node;
	}

	//左子树没找到遍历右子树找，找到返回该结点
	node = BinaryTreeFind(root->_right, x);
	if (node != NULL)
	{
		return node;
	}

	//右子树也没找到返回NULL  
	return NULL;
}

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->_val);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_val);
	BinaryTreeInOrder(root->_right);
	
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_val);
}
// 层序遍历   每个根节点都进行同样的操作：根节点进队列，出队列的时候将孩子结点带入到队列中，此时的孩子结点便成为了根节点
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		//队头结点出队
		QDataType front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_val);

		//队头结点的孩子结点入队,空姐点不入队
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}

		//空的孩子结点也入队
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}

	//判断第一个空的孩子结点之后是否还有不为空的结点
	//完全二叉树第一个空结点之后全是空结点
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
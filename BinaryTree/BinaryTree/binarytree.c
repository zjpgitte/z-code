#include "binarytree.h"
#include "Queue.h"

//���Ĵ���
void BinaryTreeCreat(BTNode **root,BTDataType **str)
{
		//����������'.'������ǰ���ΪNULL�򲻴����ڵ�
		if (**str == '.' )//��һ�������õ���ǰԪ�ص�ָ�룬�����������õ����鵱ǰԪ��
		{
			(*str)++;
			return;
		}


		//��Ԫ�ز���NULLʱ�����ڵ㣬��������ĵ�ǰԪ��
		*root = (BTNode *)malloc(sizeof(BTNode));
		(*root)->_data = **str;
		(*root)->_left = NULL;
		(*root)->_right = NULL;
		(*str)++;
		BinaryTreeCreat(&(*root)->_left,str);
		BinaryTreeCreat(&(*root)->_right,str);
	
}

//�����������
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

//�����������
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

//���ĺ������
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

//���Ľڵ����
int BinaryTreeSize(BTNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

//����Ҷ�ӽڵ����
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

//�������
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


// ��������k��ڵ����
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

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}

	//1.��ǰ�ڵ����Ҫ���ҵĽ��
	if (root->_data == x)
	{
		return root;
	}

	//2.��ǰ�ڵ㲻�ǣ�����������
	BTNode *left = BinaryTreeFind(root->_left,x);
	if (left != NULL)
	{
		return left;
	}

	//3.������û�ҵ�������������
	BTNode *right = BinaryTreeFind(root->_right, x);
	if (right != NULL)
	{
		return right;
	}

	//����������û�ҵ�����NULL
	return NULL;

}

// �������
//�ø��ڵ���ӣ�Ȼ����ӣ�֮�����ø��������Һ������,NULL��㲻���
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
		//��ǰ���ڵ����
		BTNode *cur = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", cur->_data);
		//��ǰ���ڵ�����Һ������
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

// �ж϶������Ƿ�����ȫ������
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

// ����������
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
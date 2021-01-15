#include "binarytree.h"

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
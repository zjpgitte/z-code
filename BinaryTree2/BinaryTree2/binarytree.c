#include "binarytree.h"
#include "Queue.h"


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	//ǰ����� �Ƚ�����
	BTNode *root = malloc(sizeof(BTNode));
	root->_val = a[*pi];
	(*pi)++;

	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);

	//�����������
	return root;
}
// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	//���ٵ�ʱ��ʹ�ú����������,ǰ������������Ҫ��¼��������
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	//ǰ��
	//��ǰ�ڵ㲻����
	if (root == NULL)
	{
		return 0;
	}

	//��ǰ�ڵ���� 1   +   �������Ľڵ���  +  �������Ľڵ���             
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);

}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	//�ݹ����:�սڵ�
	if (root == NULL)
	{
		return 0;
	}

	//�ݹ����:��ǰ�ڵ���Ҷ�ӽڵ�
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}

	//��������Ҷ�ӽ����+��������Ҷ�ӽ����
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
	 
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	
	//�ݹ�ݹ����,k = 1 ˵����ǰ����� �����������ĵ� k ��
	if (k == 1)
	{
		return 1;
	}

	//���������ĵ� K-1 ��֮�� 
	return BinaryTreeLevelKSize(root->_left,k-1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//ǰ�����

	if (root == NULL)
	{
		return NULL;
	}

	//�жϸ��ڵ㣬���Ƿ��ظ��ڵ�
	if (root->_val == x)
	{
		return root;
	}

	//���ڵ㲻�ǣ��������������ң��ҵ��ͷ��ظý��
	BTNode *node = BinaryTreeFind(root->_left, x);
	if (node != NULL)
	{
		return node;
	}

	//������û�ҵ������������ң��ҵ����ظý��
	node = BinaryTreeFind(root->_right, x);
	if (node != NULL)
	{
		return node;
	}

	//������Ҳû�ҵ�����NULL  
	return NULL;
}

// ������ǰ�����
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

// �������������
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

// �������������
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
// �������   ÿ�����ڵ㶼����ͬ���Ĳ��������ڵ�����У������е�ʱ�򽫺��ӽ����뵽�����У���ʱ�ĺ��ӽ����Ϊ�˸��ڵ�
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		//��ͷ������
		QDataType front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_val);

		//��ͷ���ĺ��ӽ�����,�ս�㲻���
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
// �ж϶������Ƿ�����ȫ������
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

		//�յĺ��ӽ��Ҳ���
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}

	//�жϵ�һ���յĺ��ӽ��֮���Ƿ��в�Ϊ�յĽ��
	//��ȫ��������һ���ս��֮��ȫ�ǿս��
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
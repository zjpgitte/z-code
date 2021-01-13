#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode *_left;
	struct BinaryTreeNode *_right;
}BTNode;

//���Ĵ���
void BinaryTreeCreat(BTNode **root);

//�����������
void BinaryTreePreOrder(BTNode *root);

//�����������
void BinaryTreeInOrder(BTNode *root);

//���ĺ������
void BinaryTreePostOrder(BTNode *root);

//���Ľڵ����
int BinaryTreeSize(BTNode *root);

//����Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode *root);

//�������
int BinaryTreeDepth(BTNode *root);
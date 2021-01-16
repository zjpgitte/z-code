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
void BinaryTreeCreat(BTNode **root,BTDataType **str);

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

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// �������
void BinaryTreeLevelOrder(BTNode* root);

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);

// ����������
void BinaryTreeDestory(BTNode** root);
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

//树的创建
void BinaryTreeCreat(BTNode **root);

//树的先序遍历
void BinaryTreePreOrder(BTNode *root);

//树的中序遍历
void BinaryTreeInOrder(BTNode *root);

//树的后序遍历
void BinaryTreePostOrder(BTNode *root);

//树的节点个数
int BinaryTreeSize(BTNode *root);

//树的叶子节点个数
int BinaryTreeLeafSize(BTNode *root);

//树的深度
int BinaryTreeDepth(BTNode *root);
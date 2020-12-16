#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#pragma warning(disable:4996)
#define visited 1111111
typedef struct
{
	char ch;
	int weight;
	int parent;
	int Lchild;
	int Rchild;
}hfmNode_t;
typedef struct
{
	hfmNode_t *hf;
	int n;//记录叶子节点个数
}hfmtree_t;
void Printhfmtree(hfmtree_t *hft);
void InitHfmtree(hfmtree_t *hf);
void CreatHfmTree(hfmtree_t *fht);
#pragma once
#include <stdio.h>
#include <windows.h>

typedef int ElemType;
typedef struct SListNode
{
	ElemType a;
	struct SListNode *next;
}SListNode;

void SListPrint(SListNode *phead);
void InitSList(SListNode **pphead);
void SListNodePushBack(SListNode **pphead,ElemType x);//β��
void SListNodePopBack(SListNode **pphead);//βɾ
void SListNodePushFront(SListNode **pphead, ElemType x);//ͷ��
void SListNodePopFront(SListNode **pphead);//ͷɾ
void SListNodeAdd( SListNode *p,int x);
void SListNodeErase(SListNode **pphead, SListNode *p);
SListNode* SListNodeSearch(SListNode *phead,int x);


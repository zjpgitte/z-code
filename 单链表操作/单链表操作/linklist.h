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
void SListNodePushBack(SListNode **pphead,ElemType x);//Î²²å
void SListNodePopBack(SListNode **pphead);//Î²É¾
void SListNodePushFront(SListNode **pphead, ElemType x);//Í·²å
void SListNodePopFront(SListNode **pphead);//Í·É¾
void SListNodeAdd( SListNode *p,int x);
void SListNodeErase(SListNode **pphead, SListNode *p);
SListNode* SListNodeSearch(SListNode *phead,int x);


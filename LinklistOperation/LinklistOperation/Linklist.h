#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
#pragma warning(disable:4996)
typedef int LlistDateType;
typedef struct LlistNode
{
	LlistDateType a;
	struct LlistNode *next;
}SListNode;
//增、删、查、改
void SLlistPrint(SListNode *plist);
void SLlistInit(SListNode **pplist);
void SLlistPushBack(SListNode **pplist, int x);
void SLlistPopBack(SListNode **pplist);
void SLlistPushFront(SListNode **pplist, int x);
void SLlistPopFront(SListNode **pplist);
SListNode* SLlistSearch(SListNode *plist, int x);
void SListInsertAfter(SListNode* pos,int x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SListNode* plist);


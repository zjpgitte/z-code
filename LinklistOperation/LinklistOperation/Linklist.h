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
//Ôö¡¢É¾¡¢²é¡¢¸Ä
void SLlistPrint(SListNode *plist);
void SLlistInit(SListNode **pplist);
void SLlistPushBack(SListNode **pplist, int x);
void SLlistPopBack(SListNode **pplist);
void SLlistPushFront(SListNode **pplist, int x);
void SLlistPopFront(SListNode **pplist);
SListNode* SLlistSearch(SListNode *plist, int x);


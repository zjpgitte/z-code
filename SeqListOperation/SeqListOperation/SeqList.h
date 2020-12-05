#ifndef __SEQLIST__H__
#define __SEQLIST__H__
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
typedef int SeqListType;
#define MAXSIZE 4
//Ë³Ðò±í
typedef struct SeqList
{
	SeqListType *a;
	int size;
	int cap;
}SeqList;
void InitSeqList(SeqList **L);
void SeqListPushBack(SeqList **L, int x);
void SeqListPopBack(SeqList *L);
void SeqListPushFront(SeqList **L,int x);
void SeqListPopFront(SeqList *L);
void SeqListShow(SeqList *L);
void SeqListInsert(SeqList **L,int pos, int x);
void SeqListErase(SeqList *L, int pos);


#endif




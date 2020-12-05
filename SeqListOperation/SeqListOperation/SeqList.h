#ifndef __SEQLIST__H__
#define __SEQLIST__H__
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>
typedef int SeqListType;
#define MAXSIZE 4
//顺序表
typedef struct SeqList
{
	SeqListType *a;
	int size;
	int cap;
}SeqList;
//顺序表的初始化、尾插、尾删、前插、前删、中间插、中间删、
void InitSeqList(SeqList **L);
void SeqListPushBack(SeqList **L, int x);
void SeqListPopBack(SeqList *L);
void SeqListPushFront(SeqList **L,int x);
void SeqListPopFront(SeqList *L);
void SeqListShow(SeqList *L);
void SeqListInsert(SeqList **L,int pos, int x);
void SeqListErase(SeqList *L, int pos);


#endif




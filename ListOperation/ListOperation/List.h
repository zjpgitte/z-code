#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
typedef int LDataType;
typedef struct ListNode
{
	LDataType _data;
	struct ListNode *_next;
	struct ListNode *_prev;
}ListNode;

//链表增、删、查、改
//初始化
void ListNodeInit(ListNode **pphead);
void ListNodePrint(ListNode *phead);
//尾插、头插
void ListNodePushBack(ListNode *phead,LDataType x);
void ListNodePushFront(ListNode *phead, LDataType x);
//头删、尾删
void ListNodePopBack(ListNode *phead);
void ListNodePopFront(ListNode *phead);
//查找元素x
ListNode *ListNodeFind(ListNode *phead, LDataType x);
//在pos之前插入结点
void ListNodeInsert(ListNode *pos,LDataType x);
//删除pos结点
void ListNodeErase(ListNode *pos);
//清空结点
void ListNodeClear(ListNode **phead);
//销毁链表
void ListNodeDestroy(ListNode **phead);
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

//��������ɾ���顢��
//��ʼ��
void ListNodeInit(ListNode **pphead);
void ListNodePrint(ListNode *phead);
//β�塢ͷ��
void ListNodePushBack(ListNode *phead,LDataType x);
void ListNodePushFront(ListNode *phead, LDataType x);
//ͷɾ��βɾ
void ListNodePopBack(ListNode *phead);
void ListNodePopFront(ListNode *phead);
//����Ԫ��x
ListNode *ListNodeFind(ListNode *phead, LDataType x);
//��pos֮ǰ������
void ListNodeInsert(ListNode *pos,LDataType x);
//ɾ��pos���
void ListNodeErase(ListNode *pos);
//��ս��
void ListNodeClear(ListNode **phead);
//��������
void ListNodeDestroy(ListNode **phead);
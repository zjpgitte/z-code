#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode *_next;
}QueueNode;

typedef struct Queue
{
	QueueNode *_head;
	QueueNode *_tail;
}Queue;

//��ʼ��
void QueueInit(Queue *pq);
//���
void QueuePush(Queue *pq, QDataType x);
//����
void QueuePop(Queue *pq);
//ȡ��ͷԪ��
QDataType QueueFront(Queue *pq);
//ȡ��βԪ��
QDataType QueueBack(Queue* pq);
//�п�
int QueueEmpty(Queue *pq);
//��Ԫ�ظ���
int QueueSize(Queue *pq);
//����
void QueueDestroy(Queue *pq);
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

//初始化
void QueueInit(Queue *pq);
//入队
void QueuePush(Queue *pq, QDataType x);
//出队
void QueuePop(Queue *pq);
//取队头元素
QDataType QueueFront(Queue *pq);
//取队尾元素
QDataType QueueBack(Queue* pq);
//判空
int QueueEmpty(Queue *pq);
//求元素个数
int QueueSize(Queue *pq);
//销毁
void QueueDestroy(Queue *pq);
#include "Queue.h"

//初始化
void QueueInit(Queue *pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}
static QueueNode *BuyQueueNode()
{
	QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	return newNode;
}
//入队
void QueuePush(Queue *pq, QDataType x)
{
	assert(pq);
	QueueNode *newNode = BuyQueueNode();
	newNode->_data = x;
	newNode->_next = NULL;
	if (pq->_head == NULL)
	{
		pq->_head = newNode;
		pq->_tail = newNode;
	}
	else
	{
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
	}
}
//出队
void QueuePop(Queue *pq)
{
	assert(pq);
	QueueNode *next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;
}
//取队头元素
QDataType QueueFront(Queue *pq)
{
	return pq->_head->_data;
}
//取队尾元素
QDataType QueueBack(Queue* pq)
{
	return pq->_tail->_data;
}
//判空
int QueueEmpty(Queue *pq)
{
	return pq->_head == NULL ? 1 : 0;
}
//求元素个数
int QueueSize(Queue *pq)
{
	assert(pq);
	QueueNode *cur = pq->_head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
}
//销毁
void QueueDestroy(Queue *pq)
{
	assert(pq);
	QueueNode *cur = pq->_head;
	while (cur)
	{
		QueueNode *del = pq->_head;
		pq->_head = pq->_head->_next;
		free(del);
	}
	pq->_head = pq->_tail = NULL;
}
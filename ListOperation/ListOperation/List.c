#include"List.h"

static ListNode* BuyListNode()
{
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	return newNode;
}
//初始化
void ListNodeInit(ListNode **pphead)
{
	assert(pphead );
	*pphead = BuyListNode();
	(*pphead)->_next = (*pphead)->_prev = *pphead;
}
void ListNodePrint(ListNode *phead)
{
	assert(phead);
	ListNode *cur = phead->_next;
	while (cur != phead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
//尾插、头插
void ListNodePushBack(ListNode *phead, LDataType x)
{
	assert(phead);
	ListNode *newNode = BuyListNode();
	newNode->_data = x;
	newNode->_next = newNode->_prev = NULL;
	ListNode *tail = phead->_prev;
	newNode->_next = phead;
	newNode->_prev = tail;
	tail->_next = newNode;
	phead->_prev = newNode;
}
void ListNodePushFront(ListNode *phead, LDataType x)
{
	assert(phead);
	ListNode *newNode = BuyListNode();
	newNode->_data = x;
	newNode->_next = newNode->_prev = NULL;
	ListNode *first = phead->_next;
	newNode->_next = first;
	newNode->_prev = phead;
	phead->_next = newNode;
	first->_prev = newNode;
}
//头删、尾删
void ListNodePopBack(ListNode *phead)
{
	assert(phead);
	assert(phead->_next != phead);
	ListNode *tail = phead->_prev;
	ListNode *tailPrev = tail->_prev;
	tailPrev->_next = phead;
	phead->_prev = tailPrev;
	free(tail);
}
void ListNodePopFront(ListNode *phead)
{
	assert(phead);
	assert(phead->_next != phead);
	ListNode *first = phead->_next;
	ListNode *second = first->_next;
	phead->_next = second;
	second->_prev = phead;
	free(first);
}
//查找元素x
ListNode *ListNodeFind(ListNode *phead, LDataType x)
{
	assert(phead);
	ListNode *cur = phead->_next;
	while (cur != phead)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	printf("can't find!\n");
	return NULL;
}
//在pos之前插入结点
void ListNodeInsert(ListNode *pos,LDataType x)
{
	assert(pos);
	ListNode *posPrev = pos->_prev;
	ListNode *newNode = BuyListNode();
	newNode->_data = x;
	newNode->_next = newNode->_prev = NULL;
	newNode->_next = pos;
	newNode->_prev = posPrev;
	posPrev->_next = newNode;
	pos->_prev = newNode;
}
//删除pos结点
void ListNodeErase(ListNode *pos)
{
	assert(pos);
	ListNode *posPrev = pos->_prev;
	ListNode *posBehind = pos->_next;
	posPrev->_next = posBehind;
	posBehind->_prev = posPrev;
	free(pos);
}
//清空结点
void ListNodeClear(ListNode **pphead)
{
	assert(pphead);
	ListNode *cur = (*pphead)->_next;
	while (cur != (*pphead))
	{
		ListNode *del = cur;
		cur = cur->_next;
		free(del);
	}
	(*pphead)->_next = (*pphead)->_prev = (*pphead);
}
//销毁链表
void ListNodeDestroy(ListNode **pphead)
{
	assert(pphead);
	ListNodeClear(pphead);
	free(*pphead);
	*pphead = NULL;
}
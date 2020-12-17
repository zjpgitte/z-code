#include"linklist.h"

void InitSList(SListNode **pphead)
{
	*pphead = NULL;
}
static SListNode* SListBuyNode()
{
	SListNode *newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		printf("malloc error!\n");
		exit(0);
	}
	return newnode;
}
void SListNodePushBack(SListNode **pphead, int x)
{
	SListNode *newnode = SListBuyNode();
	
	newnode->a = x;
	newnode->next = NULL;
	if ((*pphead) == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode *rear = *pphead;
		while (rear->next)
		{
			rear = rear->next;
		}
		rear->next = newnode;
	}
}
void SListPrint(SListNode *phead)
{
	if (phead == NULL)
	{
		printf("NULL\n");
		return;
	}
	SListNode *cur = phead;
	while (cur)
	{
		printf("%d-->", cur->a);
		cur = cur->next;
	}
	printf("NULL\n");

}
void SListNodePopBack(SListNode **pphead)//βɾ
{
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->next == NULL)
	{
		free((*pphead));
		*pphead = NULL;
		return;
	}
	SListNode *pre = *pphead, *rear = *pphead;
	while (rear->next)
	{
		pre = rear;
		rear = rear->next;
	}
	pre->next = NULL;
	free(rear);

}
void SListNodePushFront(SListNode **pphead, ElemType x)//ǰ��
{
	SListNode *newnode = SListBuyNode();
	
	newnode->a = x;
	newnode->next = (*pphead);
	*pphead = newnode;
}
void SListNodePopFront(SListNode **pphead)//ͷɾ
{
	if (pphead == NULL) return;
	if ((*pphead) == NULL)
	{
		return;
	}
	SListNode *del = *pphead;
	(*pphead) = (*pphead)->next;
	free(del);
}
SListNode* SListNodeSearch(SListNode *phead, int x)
{
	if (phead == NULL)
	{
		return NULL;
	}
	SListNode *cur = phead;
	while (cur)
	{
		if (cur->a == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListNodeAdd( SListNode *p,int x)
{
	if ( p == NULL)
	{
		return;
	}
	SListNode *newnode = SListBuyNode();
	newnode->a = x;
	newnode->next = p->next;
	p->next = newnode;
	
}
void SListNodeErase(SListNode **pphead, SListNode *p);
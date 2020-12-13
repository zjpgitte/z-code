#include "Linklist.h"
void SLlistInit(SListNode **pplist)
{
	*pplist = NULL;
}
void SLlistPrint(SListNode *plist)
{
	SListNode *cur = plist;
	while (NULL != cur)
	{
		printf("%d->", cur->a);
		cur = cur->next;
	}
	if (cur == NULL)
	{
		printf("NULL");
	}
	printf("\n");
}
static SListNode* BuySLlistNewNode()
{
	SListNode *newnode = (SListNode *)malloc(sizeof(SListNode));
	return newnode;
}
void SLlistPushBack(SListNode **pplist, int x)
{
	assert(pplist);
	SListNode *newnode = BuySLlistNewNode();
	newnode->a = x;
	newnode->next = NULL;
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode *tail = *pplist;
		while (NULL != tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SLlistPopBack(SListNode **pplist)
{
	//1.链表为空
	//2.只有一个节点
	//3.多余一个节点
	if ((*pplist) == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode *pre = NULL, *cur = (*pplist);
		while (NULL != cur->next)
		{
			pre = cur;
			cur = cur->next; 
		}
		free(cur);
		pre->next = NULL;
	}
}
void SLlistPushFront(SListNode **pplist, int x)
{
	//1.plist 为NULL
	//2.有一个及一个以上个节点
	SListNode *newnode = BuySLlistNewNode();
	newnode->a = x;
	newnode->next = NULL;
	if (NULL == (*pplist))
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = (*pplist);
		(*pplist) = newnode;
	}
}
void SLlistPopFront(SListNode **pplist)
{
	/*1.plist为空
	2.plist只有一个节点
	3.plist有一个以上节点*/
	if (NULL == (*pplist))
	{
		return;
	}
	else if (NULL == (*pplist)->next)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode *nlist = (*pplist)->next;
		free(*pplist);
		*pplist = nlist;
	}

}
SListNode* SLlistSearch(SListNode *plist, int x)
{
	//1.plist为空
	//2.找到
	//3.没找到
	if (plist == NULL)
	{
		return NULL;
	}
	else
	{
		SListNode *cur = plist;
		while ( cur)
		{
			if (cur->a == x)
			{
				return cur;
			}
			cur = cur->next;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, int x)
{
	//1.pos 为空不插入
	//2.
	if (pos == NULL)
	{
		return;
	}
	SListNode *newnode = BuySLlistNewNode();
	newnode->a = x;
	newnode->next = pos->next;
	pos->next = newnode;

}
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	SListNode *behind = pos->next;
	pos->next = behind->next;
	free(behind);
}
void SListDestory(SListNode* plist)
{
	if (plist == NULL)
	{
		return;
	}
	SListNode *cur = plist;
	while (cur)
	{
		free(cur);
	}
}


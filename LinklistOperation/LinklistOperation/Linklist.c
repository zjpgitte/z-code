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
	//1.����Ϊ��
	//2.ֻ��һ���ڵ�
	//3.����һ���ڵ�
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
	//1.plist ΪNULL
	//2.��һ����һ�����ϸ��ڵ�
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
	/*1.plistΪ��
	2.plistֻ��һ���ڵ�
	3.plist��һ�����Ͻڵ�*/
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
	//1.plistΪ��
	//2.�ҵ�
	//3.û�ҵ�
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
	//1.pos Ϊ�ղ�����
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


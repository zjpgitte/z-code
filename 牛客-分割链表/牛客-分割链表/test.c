#include <stdio.h>
typedef struct Node
{
	int val;
	struct Node *next;
}ListNode;
ListNode* func1(ListNode *pHead, int x)
{
	//将新建一个带哨兵位头节点和尾指针的链表
	//在原链表中找比 x 小的节点从原链表删除再尾插到新链表上
	//最后将原链表插入新链表表尾
	//返回新链表非哨兵位的表头
	if (pHead == NULL)
	{
		return pHead;
	}
	ListNode *cur = pHead, *pre = NULL;//cur指向旧链表当前位置,pre 是便于删除 cur 节点
	ListNode *nhead = (ListNode*)malloc(sizeof(ListNode));
	ListNode *nrear = nhead;
	nhead->next = NULL;//定义一个带哨兵位头结点和尾指针的单链表用于保存原链表中比 x 小的节点
	while (cur)
	{
		if (cur->val < x)
		{
			if (cur == pHead)
			{
				pHead = pHead->next;
				cur->next = NULL;
				nrear->next = cur;
				nrear = nrear->next;
				cur = pHead;
			}//删除链表的头结点并插入
			else
			{
				pre->next = cur->next;
				cur->next = nrear->next;
				nrear->next = cur;
				nrear = nrear->next;
				
					cur = pre->next;
				
				
			}//删除中间节点并插入

		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}//将 cur->val 比较并将 小于 x 的节点从原链表删除，再尾插到 新链表 
	nrear->next = pHead;//将原链表的剩余部分(即 大于 x 的节点) 接到新链表的表尾
	ListNode *rhead = nhead->next;//真实的头是 nhead->next
	free(nhead);
	return rhead;


}
void Print(ListNode *a)
{
	if (a == NULL)
	{
		printf("NULL");
		return;
	}
	ListNode *cur = a;
	while (cur)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
}
int main()
{
	ListNode *a, *b, *c, *d;
	a = (ListNode*)malloc(sizeof(ListNode));
	b = (ListNode*)malloc(sizeof(ListNode));
	c = (ListNode*)malloc(sizeof(ListNode));
	d = (ListNode*)malloc(sizeof(ListNode));
	a->val = 3;
	b->val = 2;
	c->val = 3;
	d->val = 1;
	a->next = b; b->next = c;
	c->next = d; d->next = NULL;
	a = func1(a, 2);
	Print(a);
	return 0;
}
#include <stdio.h>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };


typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
	//定义一个带哨兵位头结点的新链表
	//在新链表当中找比老链表的头结点大的节点插入到该节点之前找不到就插到尾
	//
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node *nhead = (Node*)malloc(sizeof(Node));
	nhead->next = NULL;//创建以一个新链表，存放已经有序的节点
	Node *h = head;//h指向未排序链表的头
	Node *cur = nhead->next, *pre = nhead;//cur是当前和 h 节点比较的节点，h 节点最终插入到 pre节点之后
	while (h)
	{
		if (nhead->next == NULL)
		{
			head = head->next;
			h->next = nhead->next;
			nhead->next = h;
			h = head;
			cur = nhead->next;
			pre = nhead;
		}//给新链表先添加第一个一个节点
		else
		{
			if ((cur == NULL) || (h->val < cur->val))//h 可能插在比它大的节点之前，也有可能插在尾部
			{
				head = head->next;
				h->next = cur;
				pre->next = h;
				h = head;
				cur = nhead->next;
				pre = nhead;
			}//h 节点在已排序号的新链表中找到合适位置后插入
			else
			{
				pre = cur;
				cur = cur->next;
			}//cur和pre向后走，为了找到合适的位置
		}
	}
	Node *rhead = nhead->next;
	free(nhead);
	return rhead;
}
int main()
{
	Node *a = (Node*)malloc(sizeof(Node));
	Node *b = (Node*)malloc(sizeof(Node));
	Node *c = (Node*)malloc(sizeof(Node));
	Node *d = (Node*)malloc(sizeof(Node));
	a->val = 4; b->val = 2; c->val = 1; d->val = 3;
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	Node *h = insertionSortList(a);
	
	return 0;
}
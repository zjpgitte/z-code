#include <stdio.h>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };


typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
	//����һ�����ڱ�λͷ����������
	//�����������ұ��������ͷ����Ľڵ���뵽�ýڵ�֮ǰ�Ҳ����Ͳ嵽β
	//
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node *nhead = (Node*)malloc(sizeof(Node));
	nhead->next = NULL;//������һ������������Ѿ�����Ľڵ�
	Node *h = head;//hָ��δ���������ͷ
	Node *cur = nhead->next, *pre = nhead;//cur�ǵ�ǰ�� h �ڵ�ȽϵĽڵ㣬h �ڵ����ղ��뵽 pre�ڵ�֮��
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
		}//������������ӵ�һ��һ���ڵ�
		else
		{
			if ((cur == NULL) || (h->val < cur->val))//h ���ܲ��ڱ�����Ľڵ�֮ǰ��Ҳ�п��ܲ���β��
			{
				head = head->next;
				h->next = cur;
				pre->next = h;
				h = head;
				cur = nhead->next;
				pre = nhead;
			}//h �ڵ���������ŵ����������ҵ�����λ�ú����
			else
			{
				pre = cur;
				cur = cur->next;
			}//cur��pre����ߣ�Ϊ���ҵ����ʵ�λ��
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
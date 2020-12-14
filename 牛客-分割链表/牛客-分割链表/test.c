#include <stdio.h>
typedef struct Node
{
	int val;
	struct Node *next;
}ListNode;
ListNode* func1(ListNode *pHead, int x)
{
	//���½�һ�����ڱ�λͷ�ڵ��βָ�������
	//��ԭ�������ұ� x С�Ľڵ��ԭ����ɾ����β�嵽��������
	//���ԭ��������������β
	//������������ڱ�λ�ı�ͷ
	if (pHead == NULL)
	{
		return pHead;
	}
	ListNode *cur = pHead, *pre = NULL;//curָ�������ǰλ��,pre �Ǳ���ɾ�� cur �ڵ�
	ListNode *nhead = (ListNode*)malloc(sizeof(ListNode));
	ListNode *nrear = nhead;
	nhead->next = NULL;//����һ�����ڱ�λͷ����βָ��ĵ��������ڱ���ԭ�����б� x С�Ľڵ�
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
			}//ɾ�������ͷ��㲢����
			else
			{
				pre->next = cur->next;
				cur->next = nrear->next;
				nrear->next = cur;
				nrear = nrear->next;
				
					cur = pre->next;
				
				
			}//ɾ���м�ڵ㲢����

		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}//�� cur->val �Ƚϲ��� С�� x �Ľڵ��ԭ����ɾ������β�嵽 ������ 
	nrear->next = pHead;//��ԭ�����ʣ�ಿ��(�� ���� x �Ľڵ�) �ӵ�������ı�β
	ListNode *rhead = nhead->next;//��ʵ��ͷ�� nhead->next
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
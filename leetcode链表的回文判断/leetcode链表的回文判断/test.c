#include <stdio.h>
typedef struct Node
{
	int val;
	struct Node *next;
}Node;
#define false 0
#define true 1
int func1(Node *A)
{
	if (A == NULL)
	{
		return false;
	}
	if (A->next == NULL)
	{
		return true;
	}
	Node *fast = A, *slow = A;
	Node *nhead = (Node*)malloc(sizeof(Node));//建立新链表
	nhead->next = NULL;
	while (fast != NULL && fast->next != NULL)//找中间节点
	{
		slow = slow->next;
		fast = fast->next;
		fast = fast->next;
	}
	if (fast != NULL)//slow 指向后半部分的第一个节点
	{
		slow = slow->next;
	}
	Node *ohead = slow;//保存老链表后半部分的头
	while (slow)//老链表后半部分头插到新链表上
	{
		ohead = slow->next;
		slow->next = nhead->next;
		nhead->next = slow;
		slow = ohead;
	}
	Node *Acur = A, *ncur = nhead->next;//从第一个有效节点开始比较
	while (ncur)//比较到新链表的尾
	{
		if (Acur->val != ncur->val)
		{
			return false;
		}
		Acur = Acur->next;
		ncur = ncur->next;
	}
	return true;

}
int main()
{
	Node *A = (Node*)malloc(sizeof(Node));
	A->val = 1;
	
	Node *b= (Node*)malloc(sizeof(Node));
	b->val = 12;


	Node *c = (Node*)malloc(sizeof(Node));

	c->val = 12;
	Node *d = (Node*)malloc(sizeof(Node));
	A->next = b; b->next = c;	c->next = d; d->next = NULL;
	d->val = 1;
	
	printf("%d", func1(A));
	return 0;
}
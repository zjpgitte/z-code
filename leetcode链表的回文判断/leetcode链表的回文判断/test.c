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
	Node *nhead = (Node*)malloc(sizeof(Node));//����������
	nhead->next = NULL;
	while (fast != NULL && fast->next != NULL)//���м�ڵ�
	{
		slow = slow->next;
		fast = fast->next;
		fast = fast->next;
	}
	if (fast != NULL)//slow ָ���벿�ֵĵ�һ���ڵ�
	{
		slow = slow->next;
	}
	Node *ohead = slow;//�����������벿�ֵ�ͷ
	while (slow)//�������벿��ͷ�嵽��������
	{
		ohead = slow->next;
		slow->next = nhead->next;
		nhead->next = slow;
		slow = ohead;
	}
	Node *Acur = A, *ncur = nhead->next;//�ӵ�һ����Ч�ڵ㿪ʼ�Ƚ�
	while (ncur)//�Ƚϵ��������β
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
#include <stdio.h>
#include <malloc.h>
typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *random;
}Node;
/**
* Definition for a Node.
* struct Node {
*     int val;
*     struct Node *next;
*     struct Node *random;
* };
*/
//struct Node* copyRandomList(struct Node* head) {
//	//1.��ԭ�����ÿ����㶼����һ�������뵽��ǰ���ĺ���
//	//2.��ÿ����������randomָ��ԭ���ڵ��random->next->random
//	//3.��ÿ����������nextָ������next->next;
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	Node *clone_node = NULL;
//	Node *original = head;
//	while (original)
//	{
//		clone_node = (Node*)malloc(sizeof(Node));
//		clone_node->val = original->val;
//		clone_node->next = original->next;
//		original->next = clone_node;
//		original = original->next->next;
//	}//��¡��㲢���뵽ԭ���֮��
//	Node *original_cur_node = head, *clone_cur_node = NULL;
//	Node *original_random_node = NULL, *clone_random_node = NULL;
//
//	while (original_cur_node)
//	{
//		clone_cur_node = original_cur_node->next;
//		original_random_node = original_cur_node->random;
//		if (original_random_node == NULL)
//		{
//			clone_cur_node->random = NULL;
//			original_cur_node = original_cur_node->next->next;
//		}
//		else
//		{
//			clone_random_node = original_random_node->next;
//			clone_cur_node->random = clone_random_node;
//			original_cur_node = original_cur_node->next->next;
//		}
//	}//clone����randomָ���Ӧλ��
//	Node *original_next_node = NULL, *clone_next_node = NULL;
//	original_cur_node = head;
//	Node *nhead = head->next;
//	while (original_cur_node)
//	{
//		clone_cur_node = original_cur_node->next;
//		if (clone_cur_node->next == NULL)
//		{
//			original_cur_node->next = NULL;
//			original_cur_node = original_cur_node->next;
//
//		}
//		else
//		{
//			original_next_node = clone_cur_node->next;
//			clone_next_node = original_next_node->next;
//			original_cur_node->next = original_next_node;
//			clone_cur_node->next = clone_next_node;
//			original_cur_node = original_cur_node->next;
//		}
//	}//clone����nextָ���Ӧλ��
//
//	return nhead;
//
//}
struct Node* copyRandomList(struct Node* head) {
	//��ԭ�����ÿ����㿽������뵽ԭ�����ԭ���֮��
	//�ÿ�¡�����randomָ�����λ��
	//Ȼ��ԭ����Ϳ���������ֿ�
	if (head == NULL)
	{
		return head;
	}
	Node *original_cur = head, *clone_cur = NULL;
	while (original_cur)
	{
		clone_cur = (Node*)malloc(sizeof(Node));
		clone_cur->val = original_cur->val;
		clone_cur->next = original_cur->next;
		original_cur->next = clone_cur;
		original_cur = original_cur->next->next;
	}//��¡��㲢���뵽ԭ����֮��

	original_cur = head;
	while (original_cur)
	{
		clone_cur = original_cur->next;
		if (original_cur->random == NULL)
		{
			clone_cur->random = NULL;
			original_cur = original_cur->next->next;

		}//��ǰ����randomλNULL
		else
		{
			clone_cur->random = original_cur->random->next;
			original_cur = original_cur->next->next;

		}//��ǰ����random��ΪNULL
	}//��clone����randomָ�����λ��
	original_cur = head;
	clone_cur = head->next;
	Node *nhead = head->next;
	while (clone_cur->next)
	{
		original_cur->next = original_cur->next->next;
		clone_cur->next = clone_cur->next->next;
		original_cur = original_cur->next;
		clone_cur = clone_cur->next;
	}//��ԭ����Ϳ�¡����ֿ���
	original_cur->next = NULL;//ԭ�����βָ��NULL
	return nhead;


}
int main()
{
	Node *a = (Node*)malloc(sizeof(Node));
	Node *b = (Node*)malloc(sizeof(Node));
	Node *c = (Node*)malloc(sizeof(Node));
	Node *d = (Node*)malloc(sizeof(Node));
	Node *e = (Node*)malloc(sizeof(Node));
	a->val = 7; b->val = 13;
	c->val = 11; d->val = 10; e->val = 1;
	a->next = b; b->next = c; c->next = d; d->next = e; e->next = NULL;
	a->random = NULL; b->random = a; c->random = e;
	d->random = c; e->random = a;
	Node *head = copyRandomList(a);
	Node *cur = head;
	while (cur)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	system("pause");
	return 0;
}
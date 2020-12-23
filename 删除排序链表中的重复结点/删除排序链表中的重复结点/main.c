#include <stdio.h>
typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *random;
}Node;
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
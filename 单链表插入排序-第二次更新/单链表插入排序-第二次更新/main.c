#include <stdio.h>
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode
{
	int val;
	struct ListNode *next;
};
typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
	//�ӵ�һ����㿪ʼǰһ���ͺ�һ���Ƚ���ǰһ�����һ����
	//�Ѻ�һ�����뵽ǰ��������õ�λ��
	//��ͬ��ʼ�ұȺ�һ����Ĳ��뵽��ǰ��
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node *cur = head, *behind = NULL;
	Node *insert = head, *ipre = NULL;
	while (cur->next)
	{
		if (cur->val > cur->next->val)
		{
			behind = cur->next;
			cur->next = behind->next;
			insert = head;
			while (insert->val <= behind->val)
			{
				ipre = insert;
				insert = insert->next;
			}
			if (insert == head)
			{
				behind->next = head;
				head = behind;
			}
			else
			{
				behind->next = insert;
				ipre->next = behind;
			}
		}
		else
		{
			cur = cur->next;
		}
	}
	return head;
}
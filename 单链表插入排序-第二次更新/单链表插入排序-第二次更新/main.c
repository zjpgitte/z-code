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
	//从第一个结点开始前一个和后一个比较若前一个别后一个大
	//把后一个插入到前面已排序好的位置
	//从同开始找比后一个大的插入到它前面
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
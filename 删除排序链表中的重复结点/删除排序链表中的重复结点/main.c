#include <stdio.h>
typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *random;
}Node;
struct Node* copyRandomList(struct Node* head) {
	//将原链表的每个结点拷贝后插入到原链表的原结点之后
	//让克隆链表的random指向合适位置
	//然后将原链表和拷贝的链表分开
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
	}//克隆结点并插入到原链表之中

	original_cur = head;
	while (original_cur)
	{
		clone_cur = original_cur->next;
		if (original_cur->random == NULL)
		{
			clone_cur->random = NULL;
			original_cur = original_cur->next->next;

		}//当前结点的random位NULL
		else
		{
			clone_cur->random = original_cur->random->next;
			original_cur = original_cur->next->next;

		}//当前结点的random不为NULL
	}//将clone结点的random指向合适位置
	original_cur = head;
	clone_cur = head->next;
	Node *nhead = head->next;
	while (clone_cur->next)
	{
		original_cur->next = original_cur->next->next;
		clone_cur->next = clone_cur->next->next;
		original_cur = original_cur->next;
		clone_cur = clone_cur->next;
	}//将原链表和克隆链表分开，
	original_cur->next = NULL;//原链表的尾指向NULL
	return nhead;


}
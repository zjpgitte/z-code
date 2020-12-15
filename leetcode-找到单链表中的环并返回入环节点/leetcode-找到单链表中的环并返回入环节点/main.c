#include <stdio.h>

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };

typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
	//定义快慢指针指向头，快指针走两步，慢指针走一步，(这时候我们一定不能走一步判断一步，而应该快指针走完两步，慢指针走完一步，之后再判断，这样在快慢指针相遇时才会满足快指针走的路程是慢指针的 2 倍)当这两个指针在环当中相遇，这时慢指针不变，快指重新指向头，之后让快慢指针每次都是向后走一步，当相遇时，相遇位置即是入环的头
	Node *slow = head, *fast = head;
	while (fast && fast->next)
	{
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}//这里需要在fast走完两步且slow走完一步之后再进行判断
		//这样才能在相遇时，满足快指针走的路程是慢指针的 2 倍
		//这样我们才可以用下面的方法来找入环结点
	}//找到第一次相遇的位置
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}
	fast = head;//快指针重新从头开始走,而慢指针不变
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}//找第二次相遇的位置即为入环的头
	return fast;
}
#include <stdio.h>


// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
#define false 0
#define true 1
typedef struct ListNode Node;
int hasCycle(struct ListNode *head) {
	//一：快慢指针
	//定义一对快慢指针指向head，快指针走两步，慢指针走一步，这三步每走一步都进行一次判断(判断快慢指针的值是否相同)，若相同返回true，若快指针指向NULL，或快指针的NEXT指向NULL,则结束循环，返回false

	Node *slow = head, *fast = head;//定义快慢指针
	while (fast && fast->next)
	{
		fast = fast->next;
		if (fast == slow)
		{
			return true;
		}
		fast = fast->next;
		if (fast == slow)
		{
			return true;
		}
		slow = slow->next;
		if (fast == slow)
		{
			return true;
		}
	}//每走一步判断一下，循环结束说明没有环
	return false;
}
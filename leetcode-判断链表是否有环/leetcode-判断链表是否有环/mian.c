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
	//һ������ָ��
	//����һ�Կ���ָ��ָ��head����ָ������������ָ����һ����������ÿ��һ��������һ���ж�(�жϿ���ָ���ֵ�Ƿ���ͬ)������ͬ����true������ָ��ָ��NULL�����ָ���NEXTָ��NULL,�����ѭ��������false

	Node *slow = head, *fast = head;//�������ָ��
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
	}//ÿ��һ���ж�һ�£�ѭ������˵��û�л�
	return false;
}
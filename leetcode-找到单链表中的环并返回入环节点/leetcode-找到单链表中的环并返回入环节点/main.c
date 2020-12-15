#include <stdio.h>

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };

typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
	//�������ָ��ָ��ͷ����ָ������������ָ����һ����(��ʱ������һ��������һ���ж�һ������Ӧ�ÿ�ָ��������������ָ������һ����֮�����жϣ������ڿ���ָ������ʱ�Ż������ָ���ߵ�·������ָ��� 2 ��)��������ָ���ڻ�������������ʱ��ָ�벻�䣬��ָ����ָ��ͷ��֮���ÿ���ָ��ÿ�ζ��������һ����������ʱ������λ�ü����뻷��ͷ
	Node *slow = head, *fast = head;
	while (fast && fast->next)
	{
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
		if (fast == slow)
		{
			break;
		}//������Ҫ��fast����������slow����һ��֮���ٽ����ж�
		//��������������ʱ�������ָ���ߵ�·������ָ��� 2 ��
		//�������ǲſ���������ķ��������뻷���
	}//�ҵ���һ��������λ��
	if (fast == NULL || fast->next == NULL)
	{
		return NULL;
	}
	fast = head;//��ָ�����´�ͷ��ʼ��,����ָ�벻��
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}//�ҵڶ���������λ�ü�Ϊ�뻷��ͷ
	return fast;
}
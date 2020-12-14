#include <stdio.h>


//Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
 };

typedef struct ListNode Node;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	//һ:�����ⷨ
	//     if(headA == NULL || headB == NULL)
	//     {
	//         return NULL;
	//     }
	//     Node *curA = headA,*curB = headB;
	//     while(curA)
	//     {
	//         curB = headB;
	//         while(curB)
	//         {
	//          if(curA == curB)
	//         {

	//             return curA;
	//         }
	//          curB = curB->next;
	//         }
	//         curA = curA->next;

	//     }
	//    return NULL;



	//��:�Ƚ����������̣���ò�ֵK���Ӷ�����ĵ�һ����������ĵ�K+1����ʼ����Ƚϣ��ҵ���ͬ�Ľڵ㷵�ظýڵ��ַ�����򷵻�NULL


	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	int sizeA = 0, sizeB = 0;
	Node *curA = headA, *curB = headB;
	while (curA)
	{
		sizeA++;
		curA = curA->next;
	}//��A����ĳ���
	while (curB)
	{
		sizeB++;
		curB = curB->next;
	}//B������
	curA = headA;
	curB = headB;//curA��curB �����������ͷ
	if (sizeA > sizeB)
	{
		int size = sizeA - sizeB;// �������ĳ���
		while (size--)
		{
			curA = curA->next;
		}//curA ָ����Ƚϵ�A����ĵ�һ��
	}
	else
	{
		int size = sizeB - sizeA;
		while (size--)
		{
			curB = curB->next;
		}


	}//curB ָ����Ƚϵ�B����ĵ�һ��
	while (curA && curB)
	{
		if (curA == curB)
		{
			return curA;
		}
		else
		{
			curA = curA->next;
			curB = curB->next;
		}//curA��curB�� ��ͷ�� λ�ô��Ƚ�ֱ������ֵ��ͬ
	}
	return NULL;











}

















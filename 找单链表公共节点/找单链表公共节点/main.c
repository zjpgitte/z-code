#include <stdio.h>


//Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
 };

typedef struct ListNode Node;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	//一:暴力解法
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



	//二:比较两个链表长短，求得插值K，从短链表的第一个及长链表的第K+1个开始逐个比较，找到相同的节点返回该节点地址，否则返回NULL


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
	}//求A链表的长度
	while (curB)
	{
		sizeB++;
		curB = curB->next;
	}//B链表长度
	curA = headA;
	curB = headB;//curA和curB 到各自链表表头
	if (sizeA > sizeB)
	{
		int size = sizeA - sizeB;// 计算相差的长度
		while (size--)
		{
			curA = curA->next;
		}//curA 指向待比较的A链表的第一个
	}
	else
	{
		int size = sizeB - sizeA;
		while (size--)
		{
			curB = curB->next;
		}


	}//curB 指向待比较的B链表的第一个
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
		}//curA和curB从 ‘头’ 位置处比较直到两个值相同
	}
	return NULL;











}

















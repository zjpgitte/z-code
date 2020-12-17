#include<stdio.h>


// Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
 };

typedef struct ListNode Node;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	// if(headA == NULL || headB == NULL)
	// {
	//     return NULL;
	// }
	// int sizeA = 0 , sizeB = 0;
	// Node *curA = headA, *curB = headB;
	// while(curA)
	// {
	//     sizeA++;
	//     curA = curA->next;
	// }
	// while(curB)
	// {
	//      sizeB++;
	//      curB = curB->next;   
	// }
	// curA = headA;
	// curB = headB;
	// if(sizeA > sizeB)
	// {
	//     int size = sizeA - sizeB;
	//     while(size--)
	//     {
	//         curA = curA->next;
	//     }
	// }
	// else
	// {
	//     int size = sizeB - sizeA;
	//     while(size--)
	//     {
	//         curB = curB->next;
	//     }
	// }
	// while(curA && curB)
	// {
	//     if(curA == curB)
	//     {
	//         return curA;
	//     }
	//     curA = curA->next;
	//     curB = curB->next;
	// }
	// return NULL;
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	Node *curA = headA, *curB = headB;
	while (curA != curB)
	{
		if (curA != NULL)
		{
			curA = curA->next;
		}
		else
		{
			curA = headB;
		}//curA先遍历headA 再遍历 headB,路程就是headA+headB的长度
		if (curB != NULL)
		{
			curB = curB->next;
		}
		else
		{
			curB = headA;
		}//curB先遍历headB,在遍历headA,路程就是headB+headA的长度
	}//curA 和 curB 都把headA 和 headB遍历了一遍，这样curA 和 curB 走的路程就相同,那么他俩同时到达两个链表结尾处。若有相交，同时到达交点处。(因为从交点处到结尾只有一条路径这样curA和curB才能同时到达尾部)
	return curA;


}
int main()
{

	system("pause");
	return 0;
}
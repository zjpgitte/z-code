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
		}//curA�ȱ���headA �ٱ��� headB,·�̾���headA+headB�ĳ���
		if (curB != NULL)
		{
			curB = curB->next;
		}
		else
		{
			curB = headA;
		}//curB�ȱ���headB,�ڱ���headA,·�̾���headB+headA�ĳ���
	}//curA �� curB ����headA �� headB������һ�飬����curA �� curB �ߵ�·�̾���ͬ,��ô����ͬʱ�������������β���������ཻ��ͬʱ���ｻ�㴦��(��Ϊ�ӽ��㴦����βֻ��һ��·������curA��curB����ͬʱ����β��)
	return curA;


}
int main()
{

	system("pause");
	return 0;
}
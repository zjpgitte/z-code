#include "List.h"

void TestList1()
{
	ListNode *phead;
	ListNodeInit(&phead);
	ListNodePushFront(phead, 1);
	ListNodePushFront(phead, 2);
	ListNodePushFront(phead, 3);
	ListNodePushFront(phead, 4);
	ListNodePrint(phead);
	ListNodePopBack(phead);
	ListNodePopBack(phead);
	ListNodePopBack(phead);
	ListNodePrint(phead);
	ListNodePopFront(phead);
	ListNodePrint(phead);
}

void TestList2()
{
	ListNode *phead;
	ListNodeInit(&phead);
	ListNodePushFront(phead, 1);
	ListNodePushFront(phead, 2);
	ListNodePushFront(phead, 3);
	ListNodePushFront(phead, 4);
	ListNodePrint(phead);
	ListNode *pos = ListNodeFind(phead, 4);
	ListNodeInsert(pos, 5);
	ListNodePrint(phead);
	ListNodeInsert(phead,0);
	ListNodePrint(phead);
	ListNodeErase(phead->_prev);
	pos = NULL;
	ListNodePrint(phead);
	ListNodeClear(&phead);
	ListNodePrint(phead);

}

int main()
{
	//TestList1();
	TestList2();
	system("pause");
	return 0;
}
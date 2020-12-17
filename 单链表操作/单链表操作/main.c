#include "linklist.h"

void test()
{
	SListNode *phead;            
	InitSList(&phead);                  
	SListNodePushBack(&phead, 1);
	SListNodePushBack(&phead, 2);
	SListNodePushBack(&phead, 3);
	SListNodePushBack(&phead, 4);
	SListPrint(phead);
	SListNodePopBack(&phead);
	SListNodePopBack(&phead);
	SListNodePopBack(&phead);
	SListNodePopBack(&phead);
	SListPrint(phead);
	SListNodePushFront(&phead, 1);
	SListNodePushFront(&phead, 2);
	SListNodePushFront(&phead, 3);
	SListNodePushFront(&phead, 4);
	SListPrint(phead);
	SListNodeAdd(SListNodeSearch(phead, 5), 4);
	SListPrint(phead);

	

}
int main()
{
	test();
	                                                                                   
	system("pause");
	return 0;
}
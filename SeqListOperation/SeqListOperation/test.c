#include "SeqList.h"
void test()
{
	SeqList *L;
	InitSeqList(&L);
	SeqListPushBack(&L, 2);
	SeqListPushBack(&L, 3);
	SeqListPushBack(&L, 4);
	SeqListPushBack(&L, 5);
    SeqListShow(L);
	SeqListPopBack(L);
	SeqListPopBack(L);
	SeqListPopBack(L);
	SeqListShow(L);
	SeqListPushFront(&L, 1);
	SeqListPushFront(&L, 2);
	SeqListPushFront(&L, 3);
	SeqListPushFront(&L, 4);
	SeqListShow(L);
	SeqListPopFront(L);
	SeqListShow(L);
	SeqListInsert(&L, 2, 9);
	SeqListInsert(&L, 3, 10);
	SeqListShow(L);
	SeqListErase(L, 2);
	SeqListErase(L, 3);
	SeqListShow(L);
}

int main()
{

	test();
	system("pause");
	return 0;
}
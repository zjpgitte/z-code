#include "Linklist.h"
void test1()
{
	SListNode *plist;
	SLlistInit(&plist);
	SLlistPushBack(&plist, 4);
	SLlistPushBack(&plist, 5);
	SLlistPushBack(&plist, 6);
	SLlistPrint(plist);
	SLlistPopBack(&plist);
	SLlistPopBack(&plist);
	SLlistPopBack(&plist);
	SLlistPrint(plist);
	SLlistPushFront(&plist, 1);
	SLlistPushFront(&plist, 2);
	SLlistPushFront(&plist, 3);
	SLlistPrint(plist);
	SLlistPopFront(&plist);
	SLlistPopFront(&plist);
	SLlistPopFront(&plist);
	SLlistPopFront(&plist);
	SLlistPrint(plist);
	
}
void test2()
{
	SListNode *plist;
	SLlistInit(&plist);
	SLlistPushBack(&plist, 4);
	SLlistPushBack(&plist, 5);
	SLlistPushBack(&plist, 6);
	SLlistPrint(plist);

	SListNode* nlist = SLlistSearch(plist, 4);
	nlist->a = 3;
	SLlistPrint(plist);

}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
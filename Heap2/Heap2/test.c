#include "heap.h"
void Test()
{
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int size = sizeof(a) / sizeof(a[0]);
	Heap hp;
	HeapInit(&hp, a, size);
	HeapPrint(&hp);
	HeapPush(&hp, 12);
	HeapPush(&hp, 17);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapSort(a, size);
	
}
int main()
{
	Test();

	system("pause");
	return 0;
}
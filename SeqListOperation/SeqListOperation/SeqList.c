#include "SeqList.h"


void InitSeqList(SeqList **L)
{
	(*L) = (SeqList *)malloc(sizeof(SeqList));
	(*L)->a = (SeqListType*)malloc(sizeof(SeqListType)*MAXSIZE);
	(*L)->size = 0;
	(*L)->cap = MAXSIZE;

}
void SeqListCheckCap(SeqList **L)
{
	if ((*L)->size == (*L)->cap)
	{
		(*L)->cap *= 2;
		(*L) = (SeqList *)realloc(*L, sizeof(SeqList)*(*L)->cap);
	}
}
void SeqListPushBack(SeqList **L, int x)
{
	assert(*L);
	
	(*L)->a[(*L)->size] = x;
	(*L)->size++;
}
void SeqListShow(SeqList *L)
{
	for (int i = 0; i < L->size; i++)
	{
		printf("%d ", L->a[i]);
	}
	printf("\n");
}

void SeqListPopBack(SeqList *L)
{
	assert(L);
	if (L->size == 0)
	{
		return;
	}
	L->size--;

}
void SeqListPushFront(SeqList **L, int x)
{
	assert(L);
	SeqListCheckCap(L);
	for (int i = (*L)->size - 1; i >= 0; i--)
	{
		(*L)->a[i + 1] = (*L)->a[i];
	}
	(*L)->a[0] = x;
	(*L)->size++;
}
void SeqListPopFront(SeqList *L)
{
	assert(L);
	if (L->size == 0)
	{
		return;
	}
	for (int i = 0; i < L->size-1; i++)
	{
		L->a[i] = L->a[i + 1];
	}
	L->size--;
}
void SeqListInsert(SeqList **L, int pos, int x)
{
	assert(*L);
	SeqListCheckCap(L);
	SeqList *p = (*L);
	for (int i = p->size - 1; i >= pos; i--)
	{
		p->a[i + 1] = p->a[i];
	}
	p->a[pos] = x;
	p->size++;
}
void SeqListErase(SeqList *L, int pos)
{
	assert(L);
	if (L->size == 0)
	{
		return;
	}
	for (int i = pos; i < L->size - 1; i++)
	{
		L->a[i] = L->a[i + 1];
	}
	L->size--;
}
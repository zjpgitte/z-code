#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType *_data;
	int _size;
	int _capacity;
}Heap;

//打印对元素
void HeapPrint(Heap *php);
//创建堆
void HeapInit(Heap *php, int *a, int asize);
//插入
void HeapPush(Heap *php, int x);
//删除
void HeapPop(Heap *php);
//取堆顶元素
HPDataType HeapTop(Heap *phd);
//堆的元素个数
int Heapsize(Heap *php);
//堆的判空
int HeapEmpty(Heap *php);
//堆排序
void HeapSort(int *a, int asize);
//向下调整算法
void AdjustDown(int *a, int asize, int root);//root是要调整的数的树根
//向上调整算法
void AdjustUp(int *a, int asize, int leaf);




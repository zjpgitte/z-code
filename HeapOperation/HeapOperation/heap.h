#pragma once

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType *_a;//用数组保存堆中元素
	int _size;//记录堆中元素个数
	int _capacity;//记录堆的容量
}Heap;

//打印
void HeapPrint(Heap *php);
//向下调整算法
void AdjustDown(HPDataType *a, int size, int root);
//堆的创建
void HeapInit(Heap *php, int *a, int n);
//堆的销毁
void HeapDestory(Heap *php);
//压入元素
void HeapPush(Heap *php, int x);
//弹出堆顶元素
void HeapPop(Heap *php);
//取堆顶元素
HPDataType HeapTop(Heap *php);
//堆的数据个数
int Heapsize(Heap *php);
//求堆的元素个数
int HeapEmpty(Heap *php);
//对数组排序(堆排序)
void HeapSort(int *a,int n);




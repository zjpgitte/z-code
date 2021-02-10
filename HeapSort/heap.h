#pragma once

#include <stdio.h>
#include <stdlib.h>

//交换
void Swap(int *pa, int *pb);
//向下调整算法
void AdjustDown(int *a, int n, int root);
//堆排序
void HeapSort(int *a, int n);
//打印
void PrintArray(int *a, int n);

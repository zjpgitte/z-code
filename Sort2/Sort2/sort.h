#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void PrintArray(int *a, int n);

void Swap(int *pa, int *pb);

//直接插入排序
void InsertSort(int *a, int n);

//希尔排序
void ShellSort(int *a, int n);

//直接选择排序
void SelectSort(int *a, int n);

//堆排序
void HeapSort(int *a, int n);
//向下调整算法
void AdjustDown(int *a, int n, int root);

//冒泡算法
void BubbleSort(int *a, int n);

//快速排序
void QuickSort(int *a, int left, int right);
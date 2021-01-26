#pragma once
#include <stdio.h>
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

//冒泡排序
void BubbleSort(int *a, int n);

//快速排序
void QuickSort(int *a, int n);

//快速排序非递归
void QSortNonR(int *a, int left, int right);

//归并排序
//归并排序的时间复杂度为O(N*logN)
void MergeSort(int *a, int n);

void MergeSortNonR(int *a, int n);

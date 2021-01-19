#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
#include <time.h>


void PrintArray(int *a, int n);
//直接插入排序
void InsertSort(int *a, int n);

//希尔排序
void ShellSort(int *a, int n);

//选择排序
void SelectSort(int *a, int n);

//堆排序
void HeapSort(int *a, int n);
//向下调整算法
void AdjustDown(int *a, int size, int root);
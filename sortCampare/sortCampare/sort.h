#pragma once
#include <stdio.h>
#include <windows.h>

void PrintArray(int *a, int n);

void Swap(int *pa, int *pb);
//ֱ�Ӳ�������
void InsertSort(int *a, int n);

//ϣ������
void ShellSort(int *a, int n);

//ֱ��ѡ������
void SelectSort(int *a, int n);

//������
void HeapSort(int *a, int n);

//ð������
void BubbleSort(int *a, int n);

//��������
void QuickSort(int *a, int n);

//��������ǵݹ�
void QSortNonR(int *a, int left, int right);

//�鲢����
//�鲢�����ʱ�临�Ӷ�ΪO(N*logN)
void MergeSort(int *a, int n);

void MergeSortNonR(int *a, int n);

#include <stdio.h>
#include <stdlib.h>
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
//���µ����㷨
void AdjustDown(int *a, int n, int root);

//ð���㷨
void BubbleSort(int *a, int n);

//��������
void QuickSort(int *a, int left, int right);
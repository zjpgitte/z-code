#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>
#include <time.h>


void PrintArray(int *a, int n);
//ֱ�Ӳ�������
void InsertSort(int *a, int n);

//ϣ������
void ShellSort(int *a, int n);

//ѡ������
void SelectSort(int *a, int n);

//������
void HeapSort(int *a, int n);
//���µ����㷨
void AdjustDown(int *a, int size, int root);
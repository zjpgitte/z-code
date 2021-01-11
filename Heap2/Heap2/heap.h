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

//��ӡ��Ԫ��
void HeapPrint(Heap *php);
//������
void HeapInit(Heap *php, int *a, int asize);
//����
void HeapPush(Heap *php, int x);
//ɾ��
void HeapPop(Heap *php);
//ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap *phd);
//�ѵ�Ԫ�ظ���
int Heapsize(Heap *php);
//�ѵ��п�
int HeapEmpty(Heap *php);
//������
void HeapSort(int *a, int asize);
//���µ����㷨
void AdjustDown(int *a, int asize, int root);//root��Ҫ��������������
//���ϵ����㷨
void AdjustUp(int *a, int asize, int leaf);




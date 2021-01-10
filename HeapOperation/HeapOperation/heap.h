#pragma once

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType *_a;//�����鱣�����Ԫ��
	int _size;//��¼����Ԫ�ظ���
	int _capacity;//��¼�ѵ�����
}Heap;

//��ӡ
void HeapPrint(Heap *php);
//���µ����㷨
void AdjustDown(HPDataType *a, int size, int root);
//�ѵĴ���
void HeapInit(Heap *php, int *a, int n);
//�ѵ�����
void HeapDestory(Heap *php);
//ѹ��Ԫ��
void HeapPush(Heap *php, int x);
//�����Ѷ�Ԫ��
void HeapPop(Heap *php);
//ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap *php);
//�ѵ����ݸ���
int Heapsize(Heap *php);
//��ѵ�Ԫ�ظ���
int HeapEmpty(Heap *php);
//����������(������)
void HeapSort(int *a,int n);




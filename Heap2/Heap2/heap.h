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
HPDataType HeapTop(HPDataType *a);
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

//TopK���⣺�ҳ�N����������� / ��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);





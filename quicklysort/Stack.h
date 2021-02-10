#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType *_arr;
	int Top;
	int capacity;
}Stack;

//��ʼ��
void StackInit(Stack *st);
//ѹջ
void StackPush(Stack *st,STDataType x);
//��ջ
void StackPop(Stack *st);
//ȡջ��
STDataType StackTop(Stack *st);
//�п�
int StackEmpty(Stack *st);
//��Ԫ�ظ���
int StackSize(Stack *st);
//����
void StackDestroy(Stack *st);
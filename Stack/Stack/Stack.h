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

//³õÊ¼»¯
void StackInit(Stack *st);
//Ñ¹Õ»
void StackPush(Stack *st,STDataType x);
//µ¯Õ»
void StackPop(Stack *st);
//È¡Õ»¶¥
STDataType StackTop(Stack *st);
//ÅÐ¿Õ
int StackEmpty(Stack *st);
//Ïú»Ù
void StackDestroy(Stack *st);
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

//初始化
void StackInit(Stack *st);
//压栈
void StackPush(Stack *st,STDataType x);
//弹栈
void StackPop(Stack *st);
//取栈顶
STDataType StackTop(Stack *st);
//判空
int StackEmpty(Stack *st);
//求元素个数
int StackSize(Stack *st);
//销毁
void StackDestroy(Stack *st);
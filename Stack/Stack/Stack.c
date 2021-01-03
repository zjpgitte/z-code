#include "Stack.h"

//³õÊ¼»¯
void StackInit(Stack *st)
{
	assert(st);
	st->Top = 0;
	st->capacity = 4;
	st->_arr = (STDataType*)malloc(sizeof(STDataType)*(st->capacity));
}
static void StackCheckCapacity(Stack *st)
{
	//Õ»ÂúÀ©ÈÝ
	if (st->Top == st->capacity)
	{
		st->capacity *= 2;
		STDataType *temp = (STDataType*)realloc(st->_arr, sizeof(STDataType)*(st->capacity));
		if (temp == NULL)
		{
			printf("realloc error!\n");
			exit(-1);
		}
		st->_arr = temp;
	}
}
//Ñ¹Õ»
void StackPush(Stack *st,STDataType x)
{
	assert(st);
	//ÅÐÕ»ÊÇ·ñÂú
	StackCheckCapacity(st);
	st->_arr[st->Top] = x;
	st->Top++;
}
//µ¯Õ»
void StackPop(Stack *st)
{
	assert(st);
	assert(st->Top != 0);
	st->Top--;
}
//È¡Õ»¶¥ÔªËØ
STDataType StackTop(Stack *st)
{
	return st->_arr[st->Top - 1];
}
//ÅÐ¿Õ
int StackEmpty(Stack *st)
{
	assert(st);
	return st->Top == 0 ? 1 : 0;
	//return st->Top;
}
//Ïú»Ù
void StackDestroy(Stack *st)
{
	assert(st);
	free(st->_arr);
	st->_arr = NULL;
}

#include "Stack.h"

//��ʼ��
void StackInit(Stack *st)
{
	assert(st);
	st->Top = 0;
	st->capacity = 4;
	st->_arr = (STDataType*)malloc(sizeof(STDataType)*(st->capacity));
}
static void StackCheckCapacity(Stack *st)
{
	//ջ������
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
//ѹջ
void StackPush(Stack *st,STDataType x)
{
	assert(st);
	//��ջ�Ƿ���
	StackCheckCapacity(st);
	st->_arr[st->Top] = x;
	st->Top++;
}
//��ջ
void StackPop(Stack *st)
{
	assert(st);
	assert(st->Top != 0);
	st->Top--;
}
//ȡջ��Ԫ��
STDataType StackTop(Stack *st)
{
	return st->_arr[st->Top - 1];
}
//�п�
int StackEmpty(Stack *st)
{
	assert(st);
	return st->Top == 0 ? 1 : 0;
	//return st->Top;
}
//����
void StackDestroy(Stack *st)
{
	assert(st);
	free(st->_arr);
	st->_arr = NULL;
}

#include <iostream>
#include <assert.h>

using namespace std;

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
void StackPush(Stack *st, STDataType x);
//µ¯Õ»
void StackPop(Stack *st);
//È¡Õ»¶¥
STDataType StackTop(Stack *st);
//ÅÐ¿Õ
int StackEmpty(Stack *st);
//ÇóÔªËØ¸öÊý
int StackSize(Stack *st);
//Ïú»Ù
void StackDestroy(Stack *st);

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
void StackPush(Stack *st, STDataType x)
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
int StackSize(Stack *st)
{
	assert(st);
	return st->Top;
}
//Ïú»Ù
void StackDestroy(Stack *st)
{
	assert(st);
	free(st->_arr);
	st->_arr = NULL;
}

int TransformToInt(char *s)
{
	int sign = 1;
	char *ps = s;
	if (*ps == '-')
	{
		sign = -1;
		ps++;
	}
	if (*ps == '+')
	{
		sign = 1;
		ps++;
	}
	int ret = 0;
	while (*ps != '\0')
	{
		int a = *ps - '0';
		ret = ret * 10 + a;
		ps++;
	}

	return ret * sign;
}

int Calculate(int a, int b, char* ch)
{
	switch (ch[0])
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	}
	return 1;
}

char *TransformToch(int x)
{
	int y = x;
	int n = 0;
	while (y)
	{
		y /= 10;
		n++;
	}
	char *s = (char*)malloc(sizeof(char)*(n + 1));
	s[n] = '\0';
	int i = n - 1;
	while (x)
	{
		s[i--] = x % 10 + '0';
		x /= 10;
	}

	return s;
}

int evalRPN(char ** tokens, int tokensSize){
	Stack operate;
	StackInit(&operate);
	for (int i = 0; i < tokensSize; i++)
	{
		if (*tokens[i] >= '0' && *tokens[i] <= '9' || *tokens[i] == '-' && strlen(tokens[i]) > 1)
		{
			int curOperate = TransformToInt(tokens[i]);
			StackPush(&operate, curOperate);
		}
		else
		{
			int operate2 = StackTop(&operate);
			StackPop(&operate);
			int operate1 = StackTop(&operate);
			StackPop(&operate);
			int ret = Calculate(operate1, operate2, tokens[i]);
			StackPush(&operate, ret);
		}

	}
	int ret = StackTop(&operate);

	StackDestroy(&operate);
	return ret;
}

int main()
{
	char *s[] = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	int size = sizeof(s) / sizeof(s[0]);

	int ret = evalRPN(s, size);
}
#include <stdio.h>
#include <windows.h>
#define NUMBER 100
typedef struct stack
{
	char ch[NUMBER];
	int Top;
}Stack;
void InitStack(Stack *str)
{
	str->Top = -1;
}
void Input(char arr1[],char arr2[])
{
	char ch;
	int i = 0;
	printf("请输入&之前字符串：(以@结束): ");
	while ((ch=getchar()) != '@')
	{
		
		arr1[i] = ch;
		i++;
	}
	arr1[i] = '@';
	printf("请输入&后的字符串：(以@结束): ");
	getchar();
	i = 0;
	while ((ch = getchar()) != '@')
	{
		arr2[i] = ch;
		i++;
	}
	arr2[i] = '@';
}
void PushStack(Stack *str, char arr1[])
{
	int i = 0;
	while (arr1[i] != '@')
	{
		str -> Top++;
		str->ch[str->Top] = arr1[i];
		i++;
	}
}
void PopStack(Stack *str, char *ch)
{
	(*ch) = str->ch[str->Top];
	str->Top--;
}
int Compare(char ch, char e)
{
	if (ch == e) return 1;
	else return 0;
}
void Judge(char arr1[],char arr2[])
{
	Stack str;
	int ch;
	int i = 0;
	InitStack(&str);
	PushStack(&str,arr1);
	while (arr1[i] != '@' && arr2[i] != '@')
	{
		PopStack(&str,&ch);
   		int ret=Compare(ch,arr2[i]);
		i++;
		if (0 == ret)
		{
			break;
		}
	}
	if (arr1[i] == '@' && arr2[i] == '@')
	{
		printf("是回文\n");
	}
	else
	{
		printf("不是回文\n");
	}
}
int main()
{
	char arr1[NUMBER],arr2[NUMBER];
	Input(arr1, arr2);
	Judge(arr1,arr2);
	system("pause");
	return 0;
}
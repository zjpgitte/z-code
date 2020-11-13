#include<stdio.h>
#include<windows.h>
#define NUMBER 100
typedef struct
{
	char ch[NUMBER];
	int Top;
}Stack;
void Input(char arr[])
{
	char ch;
	int i = 0;
	printf("�����ַ�����(@��Ϊ������־):\n");
	while ((ch = getchar()) != '@')
	{
		arr[i] = ch;
		i++;
		if (ch == '\n')
		{
			printf("����������(@��Ϊ������־)��");
			i = 0;
			
		}
	}
	getchar();
	arr[i] = '@';
}
void InitStack(Stack *str)
{
	str->Top = -1;
}
void PushStack(Stack *str, char arr[])
{
	int i = 0;
	while (arr[i] != '&')
	{
		str->Top++;
		str->ch[str->Top] = arr[i];
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
	return 0;
}

void Judge(char arr[])
{
	Stack str;
	char ch;
	int i = 0;
	InitStack(&str);
	PushStack(&str, arr);//���ַ�����&֮ǰ���ַ���ջ
	while ( arr[i] != '&')
	{
		i++;
	}
	i++;
	while (str.Top !=-1 && arr[i] != '@')
	{
		PopStack(&str, &ch);
		int ret=Compare(ch, arr[i]);
		i++;
		if (ret == 0)
		{
			break;
		}
	}
	if (str.Top == -1 && arr[i] == '@')
	{
		printf("�ǻ���\n");
	}
	else
	{
		printf("���ǻ���\n");
	}
}
int main()
{
	char arr[NUMBER];
	Input(arr);
	Judge(arr);
	system("pause");
	return 0;
}
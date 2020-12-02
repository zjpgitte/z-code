#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
#define SIZE 20
typedef struct
{
	char name[SIZE];
	
}hashtable_t;
int hash(char nam[])
{
	int sum = 0;
	char *p = nam;
	while ('\0' != *p)
	{
		sum += (*p);
		p++;
	}
	return (sum % SIZE);
}
void Input(hashtable_t h[])
{
	printf("����Ҫ���������ĸ�����");
	int num = 0;
	scanf("%d", &num);
	char nam[SIZE];
	for (int i = 0; i < num; i++)
	{
		printf("�����%d������", i + 1);
		scanf("%s", nam);
		int pos = hash(nam);
		while (h[pos].name[0] != 0 && pos < SIZE*5)
		{
			pos += 1;
		}
		if (pos == SIZE * 5)
		{
			return -1;
		}
		strcpy(h[pos].name, nam);
	}
}
int HashSearch(hashtable_t h[], char nam[])
{
	int pos = hash(nam);
	while (strcmp(h[pos].name, nam) != 0)
	{
		pos += 1;
		if (h[pos].name[0] == 0)
			return -1;
	}
	return pos;
}

int main()
{
	hashtable_t h[SIZE * 5] = {0};
	Input(h);//���ϣ��������ؼ���;
	while (1)
	{
		printf("��������ҵ�����:");
		char nam[SIZE];
		scanf("%s", nam);
		int pos = HashSearch(h, nam);
		if (-1 != pos)
		{
			printf("%s ��λ��Ϊ %d\n", nam, pos);
		}
		else {
			printf("û�ҵ�����\n");
		}
	}
	system("pause");
	return 0;
}
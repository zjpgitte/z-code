#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define Max 100
typedef struct
{
	char word[Max / 10];
}Word;
void func(char str[])
{
	char *p = str;
	Word w[Max / 2];
	int i = 0, j = 0;
	while ((*p) != '\0')
	{
		j = 0;
		while ((*p) != ' ' && (*p) != '\0')
		{
			w[i].word[j++] = *p++;
		}
		w[i++].word[j] = '\0';
		if ((*p) != '\0')
		p++;
	}
	i--;
	p = str;
	while (i >= 0)
	{
		j = 0;
		while (w[i].word[j] != '\0')
		{
			*p = w[i].word[j];
			j++;
			p++;
		}
		if (i != 0) *p = ' ';
		p++;
		i--;
	}


}
int main()
{
	
	char str[Max];
	int i = 0;
	gets(str);
	printf("before:%s\n",str);
	func(str);
	printf("after:%s\n", str);
	system("pause");
	return 0;
}
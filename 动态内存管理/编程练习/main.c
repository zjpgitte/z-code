#include <stdio.h>
#include <windows.h>
#include <string.h>
#pragma warning(disable:4996)
const char *my_strncat(const char *dst, const char *source, int num)
{
    char *p = dst;
	while (*p)
	{
		p++;
	}
	while ((*p = *source) && num)
	{
		p++;
		source++;
		num--;
	}
	*p = '\0';
	return dst;
}
const char *my_strncpy(const char *dst, const char *source, int num)
{
	char *p = dst;
	while ((*p = *source) && num)
	{
		p++;
		source++;
	}
	return dst;
}
int main()
{
	const char str[20] = "hello ";
	printf("%s\n", my_strncat(str, "world!", 5));
	printf("%s\n", my_strncpy(str, "hallo ", 2));
	system("pause");
	return 0;
}
#include "main.h"

int main()
{
	char str[6];
	//scanf("%s %s", str,str);
	fgets(str, sizeof(str)-1, stdin);
	printf("%s", str);
	system("pause");
	return 0;
}
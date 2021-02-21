#include "test.h"


int main()
{
	/*int a = 4, b = 5;
	if (a > b)
		a = b; b = a;
	else
		a++; b++;
*/
	char s[] = "aaabbaa";
	int n = compress(s, strlen(s));

	printf("%s",s);

	system("pause");
	return 0;
}
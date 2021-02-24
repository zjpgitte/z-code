#include "test.h"


int main()
{
	/*int a = 4, b = 5;
	if (a > b)
		a = b; b = a;
	else
		a++; b++;
*/
	char s[] = { '%', '%', '2', '2', '2', ')', ')', ')' };
	
	int size = sizeof(s) / sizeof(s[0]);

	int n = compress(s, size);

	printf("%s",s);

	system("pause");
	return 0;
}
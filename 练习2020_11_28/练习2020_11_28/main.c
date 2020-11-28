#include <stdio.h>
#include <windows.h>

int main()
{
	printf("%s\n", __FILE__);
	printf("%s\n", __LINE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);

	system("pause");
	return 0;
}
#include<stdio.h>
#include<windows.h>
void func()
{
	int a = 1;
	char *p = (char *)&a;
	if ((*p) == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}

}
int main()
{
	func();
	system("pause");
	return 0;
}
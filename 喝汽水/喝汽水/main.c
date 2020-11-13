#include<stdio.h>
#include<windows.h>
int func(int money)
{
	int drink_num = money;
	int empty_num = drink_num;
	while (empty_num > 1)
	{
		drink_num += empty_num / 2;
		empty_num = empty_num / 2 + empty_num % 2;
	}
	return drink_num;
}
int main()
{
	int money = 20;
	printf("%d\n",func(money));

	system("pause");
	return 0;
}
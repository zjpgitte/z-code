#include <stdio.h>
#include <windows.h>
void Drink(int money)
{
	int drink = money;//有多少钱喝多少瓶
	int empty = drink;//喝多少瓶有多少空瓶
	while (empty > 1)//空瓶比1大可以一直换
	{
		drink += empty / 2;//这总共和的熟练。（换了再喝的数量是空瓶数量的一半）
		empty = empty / 2 + empty % 2;//这是最终空瓶剩余的数量
	}
	printf("%d\n", drink);
}
int main()
{
	int money = 20;
	Drink(money);
	system("pause");
	return 0;
}
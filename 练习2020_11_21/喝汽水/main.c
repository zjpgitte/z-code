#include <stdio.h>
#include <windows.h>
void Drink(int money)
{
	int drink = money;//�ж���Ǯ�ȶ���ƿ
	int empty = drink;//�ȶ���ƿ�ж��ٿ�ƿ
	while (empty > 1)//��ƿ��1�����һֱ��
	{
		drink += empty / 2;//���ܹ��͵��������������ٺȵ������ǿ�ƿ������һ�룩
		empty = empty / 2 + empty % 2;//�������տ�ƿʣ�������
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
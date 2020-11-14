#include<stdio.h>
#include<windows.h>
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次
void func()
{
	//穷举：
	int ret[5] = { 0 };
	int i = 0, j = 0, k = 0, m = 0, n = 0;
	for ( i = 1; i <= 5; i++)
	{
		ret[0] = i;
		for ( j = 1; j <= 5; j++)
		{
			ret[1] = j;
			for ( k = 1; k <= 5; k++)
			{
				ret[2] = k;
				for ( m = 1; m <= 5; m++)
				{
					ret[3] = m;
					for ( n = 1; n <= 5; n++)
					{
						ret[4] = n;
						if ((((ret[1] == 2) + (ret[0] == 3)) == 1) && (((ret[1] == 2) + (ret[4] == 4)) == 1) && (((ret[2] == 1) + (ret[3] == 2) == 1))\
							&& (((ret[2] == 5) + (ret[3]) == 3) == 1) && (((ret[4] == 4) + (ret[0] == 1) == 1)))
						{
							if (ret[0] * ret[1] * ret[2] * ret[3] * ret[4] == 120)
								goto next;
						}
							
					}
				}
			}
		}
	}

next:	for (int i = 0; i < 5; i++)
	{
		printf("%c:%d\n", 'A' + i, ret[i]);
	}
}
int main()
{
	func();
	system("pause");
	return 0;
}
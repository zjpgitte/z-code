#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <errno.h>
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
#pragma warning(disable:4996)
int main()
{
	char killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if (((killer != 'A') +( killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
		{
			printf("%c\n", killer);
			break;
		}
	}
	system("pause");
	return 0;
}
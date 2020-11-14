#include<stdio.h>
#include<windows.h>
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
void func()
{
	char murder = 0;
	for (murder = 'a'; murder <= 'd'; murder++)//假设法：假设凶手是一个人，再判断条件（已知3个人说了真话，1个人说的是假话）是否成立
	{                                             //若成立则假设成立，否则假设不成立。
		if( ((murder != 'a') + (murder == 'c') + (murder == 'd') + (murder != 'd') ) == 3)
			printf("%c is murder\n", murder);
	}
}
int main()
{
	func();
	system("pause");
	return 0;
}
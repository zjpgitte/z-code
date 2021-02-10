#include <iostream>

using namespace std;

int Add(int a, int b)
{
	printf("%d\n", a + b);
	return a + b;
}

int main()
{
	/*char ch;
	while ((ch = getchar()) != EOF)
	{
		printf("%c", ch);
	}
*/

	/*short s = 0;
	int a = 10;
	printf("%d\n", sizeof(s = a + 2));*/

	//float f = 9.0;
	//int a = f;
	//printf("%d\n", a);

	//char c = 'a';
	//printf("%d\n", sizeof(c));
	//printf("%d\n", sizeof(+c));
	//printf("%d\n", sizeof(-c));

	//char a;
	//char b = 10;
	//char c = 20;
	//a = b + c; // 表达式中b和c先转换成int类型，再进行运算
	//		  //最后将运算结果截断性存到 a 中

	/*int a = 1567893838;
	float b = a;
	printf("%f\n", b);
*/
	
	printf("%d\n", Add(1.1, 2.2));


	system("pause");

	return 0;
}
#include "test.h"


int main()
{
	
	/*int i = 10, j = 10, k = 3;
	k *= i + j;
	cout << k << endl;*/
	
	/*char c = 1;
	cout << sizeof(c) << endl;
	cout << sizeof(+c) << endl;
	cout << sizeof(-c) << endl;*/

	/*float f = 9.0;
	int num = f;
	cout << num << endl;
	printf("%d\n", f);*/

	/*int n = 2/3;
	float f = n;
	cout << f << endl;*/

	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(a) / sizeof(a[0]);
	rotate(a, size, 3);
	system("pause");
	return 0;
}
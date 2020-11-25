#include <stdio.h>
#include <windows.h>

int main()
{
    int  a[3][4] = { 0 };
	printf("%d\n", sizeof(a[0]+1));//4 a[0]表示数组首元素，也是第一个数组的地址，而a[0]+1是第一个第数组二个元素的地址
	printf("%d\n", sizeof(a+1));//4 a是二维数组第一个元素的地址，a+1是第二个元素的地址
	printf("%d\n", sizeof(*(a+1)));//16 a+1是第二个元素的地址，解引用后是第二个元素，而第二个元素是个一维数组，*(a+1)就是一维数组的数组名
	printf("%d\n", sizeof(*(&a[0]+1)));//16 &a[0]+1是第二元素的地址，同上*(&a[0]+1)是第二个一维数组数组名
	printf("%d\n", sizeof(*a));//16 *a是第一个元素，第一个元素是数组，*a是该数组名
	system("pause");
	return 0;
}
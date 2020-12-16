#include "hafm.h"
void test()
{
	hfmtree_t hft ;
	InitHfmtree(&hft);
	Printhfmtree(&hft);
}
int main()
{
	test();
	system("pause");
	return 0;
}
#include "binarytree.h"

void Test()
{
	BTDataType str[] = "ABD..E..C..";
	char *ps = str;
	BTNode *root = NULL;
	BinaryTreeCreat(&root,&ps);//root��ps��������ָ��,�����ڲ��������õ������ָ�롣
	BinaryTreePreOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("TreeSize:%d\n", BinaryTreeSize(root));
	printf("TreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("TreeDepth:%d\n", BinaryTreeDepth(root));
}

int main()
{

	Test();

	system("pause");
	return 0;
}
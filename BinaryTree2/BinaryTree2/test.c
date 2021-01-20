#include "binarytree.h"

void BinaryTreeTest()
{
	char str[] = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode *root = BinaryTreeCreate(str, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("TreeSize:%d\n", BinaryTreeSize(root));
	printf("TreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("TreeLevelKSize:%d\n", BinaryTreeLevelKSize(root,2));
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("TreeComplete:%d\n", BinaryTreeComplete(root));


}

int main()
{

	BinaryTreeTest();

	system("pause");
	return 0;
}
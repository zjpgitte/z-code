#include "binarytree.h"

void Test()
{
	BTDataType str[] = "ABD..E.H..CF..G..";
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
	printf("3 level size:%d\n", BinaryTreeLevelKSize(root, 3));
	printf("%c\n", BinaryTreeFind(root, 'D')->_data);
	BinaryTreeLevelOrder(root);
	printf("%d\n", BinaryTreeComplete(root));
	BinaryTreeDestory(&root);
}

int main()
{

	Test();

	system("pause");
	return 0;
}